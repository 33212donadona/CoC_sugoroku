#include "select_characor.h"
#include "charactor/charactor_info.h"
#include "parameter/parameter.h"
#include "../common_data/common_data.h"

const float  CSelectCharactor::m_box_thickness = 10.0f;
const unsigned int  CSelectCharactor::m_box_color[] = 
{
	0xffff0000,
	0xff0000ff,
	0xff00ff00,
	0xffffff00
};

CSelectCharactor::CSelectCharactor(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SelectCharactor")
	, m_NowSelectPlayer(PLAYER_ID::PL1)
	, m_SelectCharactor(0)
{
}

/*
*  初期化
*/
void CSelectCharactor::Initialize()
{
	// クラス参照
	m_CommonDataClass = (CCommonData*)aqua::FindGameObject("CommonData");

	aqua::CCSVLoader loader;

	loader.Load("data\\character\\charactor_list.csv");

	int row = loader.GetRows(); //　縦

	for (int i = 0; i < row; ++i)
	{
		CCharactorInfo* info;
		CParameter* param;
		STATUS status;
		aqua::CSprite sprite;
		std::string file_name = loader.GetString(i, 2);

		status.m_Hp = loader.GetFloat(i, 5);
		status.m_Str = loader.GetInteger(i, 6);
		status.m_Dex = loader.GetInteger(i, 7);

		info = aqua::CreateGameObject<CCharactorInfo>(this);
		param = aqua::CreateGameObject<CParameter>(this);

		info->Initialize
		(
			file_name,
			(JOB_ID)loader.GetInteger(i, 0),
			(SKILL_ID)loader.GetInteger(i, 3),
			status
		);

		sprite.Create(file_name);
		sprite.scale.x = 0.75;
		sprite.scale.y = 0.75;

		sprite.position.x = sprite.GetTextureWidth() - sprite.GetTextureWidth() * sprite.scale.x;
		sprite.position.x *= 0.5f;

		sprite.position.y = sprite.GetTextureHeight() - sprite.GetTextureHeight() * sprite.scale.y;
		sprite.position.y *= 0.5f;

		param->Initialize
		(
			status,
			aqua::CVector2(aqua::GetWindowWidth() / 64.0f * 24.0f, 0.0f),
			aqua::CVector2(aqua::GetWindowWidth() / 64.0f * 35.0f, aqua::GetWindowHeight() / 2.0f)
		);

		info->m_Scale = aqua::CVector2::ONE * 0.3f;

		info->m_Position.x = (float)(i % 4);
		info->m_Position.x += (i % 4 / 2) * aqua::GetWindowWidth() / 2.0f;
		info->m_Position.x += aqua::GetWindowWidth() / 4.0f;
		info->m_Position.x -= (float)((i + 1) % 2 * info->GetSpriteSize().x);

		info->m_Position.y = aqua::GetWindowHeight() / 2.0f;
		info->m_Position.y += (i / 4) * aqua::GetWindowHeight() / 4.0f;
		info->m_Position.y += (aqua::GetWindowHeight() / 4.0f - info->GetSpriteSize().y) / 2.0f;

		m_Charactor.push_back(info);
		m_Parameter.push_back(param);
		m_CharactorSpriteList.push_back(sprite);
	}

	loader.Unload(); // CSV解放

	m_CharactorMaxNum = (int)m_Charactor.size() - 1;

	m_BackgroudSprite.Create("data\\select\\back_ground\\back_ground2.png");

	m_SelectBox.Setup
	(
		m_Charactor[m_SelectCharactor]->m_Position,
		m_Charactor[m_SelectCharactor]->GetSpriteSize().x,
		m_Charactor[m_SelectCharactor]->GetSpriteSize().y,
		m_box_color[(int)m_NowSelectPlayer],
		false,
		m_box_thickness
	);

	m_SelectBlendBox.Setup
	(
		m_Charactor[m_SelectCharactor]->m_Position,
		m_Charactor[m_SelectCharactor]->GetSpriteSize().x,
		m_Charactor[m_SelectCharactor]->GetSpriteSize().y,
		m_box_color[(int)m_NowSelectPlayer]
	);

	m_SelectBlendBox.color.alpha = (unsigned char)100;
}

/*
*  更新
*/
void CSelectCharactor::Update()
{
	SelectCharactor();

	DecideCharactor();

	aqua::IGameObject::Update();
}

/*
*  描画
*/
void CSelectCharactor::Draw()
{
	m_BackgroudSprite.Draw();

	for (auto& chara_it : m_Charactor)
		chara_it->Draw();

	int i = 0;

	for (auto& param_it : m_Parameter)
	{
		if (i == m_SelectCharactor)
		{
			param_it->Draw();
			m_CharactorSpriteList[i].Draw();
		}

		i++;
	}

	m_SelectBlendBox.Draw();
	m_SelectBox.Draw();
}

/*
*  解放
*/
void CSelectCharactor::Finalize()
{
	m_BackgroudSprite.Delete();

	for (auto& chara_it : m_Charactor)
	{
		chara_it->Finalize();

		aqua::ListErase(&m_ChildObjectList, chara_it);

		AQUA_SAFE_DELETE(chara_it);
	}

	for (auto& param_it : m_Parameter)
	{
		param_it->Finalize();

		aqua::ListErase(&m_ChildObjectList, param_it);

		AQUA_SAFE_DELETE(param_it);
	}

	for (auto& sprite_it : m_CharactorSpriteList)
	{
		sprite_it.Delete();
	}

	m_Charactor.clear();
	m_Parameter.clear();
	m_CharactorSpriteList.clear();

	aqua::IGameObject::Finalize();
}

/*
*  キャラクター選択
*/
void CSelectCharactor::SelectCharactor()
{
	int step_right = aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RIGHT);
	int step_left = aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::LEFT) * (-1);
	int step_up = aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::UP) * (m_CharactorMaxNum + 1) / 2 * (-1);
	int step_down = aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::DOWN) * (m_CharactorMaxNum + 1) / 2;

	if (step_right || step_left || step_up || step_down)
	{
		m_SelectCharactor += step_right + step_left + step_up + step_down;

		m_SelectCharactor = aqua::Mod(m_SelectCharactor, 0, m_CharactorMaxNum);

		// ボックスの座標を変更
		m_SelectBlendBox.position = m_Charactor[m_SelectCharactor]->m_Position;
		m_SelectBox.position = m_SelectBlendBox.position;
	}
}

/*
*  キャラクターの決定
*/
void CSelectCharactor::DecideCharactor()
{
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::LSHIFT) && aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
	{
		if (!m_CommonDataClass->EmptyChara())
		{
			// リストから除外
			m_CommonDataClass->EraseBackChara();

			// 範囲を限定する
			m_NowSelectPlayer = 
				aqua::Limit<PLAYER_ID,int>((int)m_NowSelectPlayer - 1,(int)PLAYER_ID::PL1, (int)PLAYER_ID::PL4);

			// ボックスの色を変更
			m_SelectBlendBox.color = m_box_color[(int)m_NowSelectPlayer];
			m_SelectBox.color = m_box_color[(int)m_NowSelectPlayer];

			m_SelectBlendBox.color.alpha = (unsigned char)100;

		}
	}
	else if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN) && m_NowSelectPlayer != PLAYER_ID::DUMMY)
	{
		m_CommonDataClass->PushBack_Chara((*m_Charactor[m_SelectCharactor]));

		m_NowSelectPlayer = aqua::Limit<PLAYER_ID, int>((int)m_NowSelectPlayer + 1, (int)PLAYER_ID::PL1, (int)PLAYER_ID::DUMMY);

		if (m_NowSelectPlayer != PLAYER_ID::DUMMY)
		{
			// ボックスの色を変更
			m_SelectBlendBox.color = m_box_color[(int)m_NowSelectPlayer];
			m_SelectBox.color = m_box_color[(int)m_NowSelectPlayer];

			m_SelectBlendBox.color.alpha = (unsigned char)100;
		}
	}
}