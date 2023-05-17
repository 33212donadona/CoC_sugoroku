#include "select_characor.h"
#include "charactor/charactor_info.h"

const float  CSelectCharactor::m_box_thickness = 10.0f;
const unsigned int  CSelectCharactor::m_box_color = 0xffff0000;

CSelectCharactor::CSelectCharactor(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SelectCharactor")
	, m_NowSelectPlayer(PLAYER_ID::PL1)
	, m_SelectCharactor(0)
{
}

void CSelectCharactor::Initialize()
{
	aqua::CCSVLoader loader;
	loader.Load("data\\character\\charactor_list.csv");
	int row = loader.GetRows(); //　縦
	int col = loader.GetCols(); //　横

	for (int i = 0; i < row; ++i)
	{
		CCharactorInfo* info;
		STATUS status;

		status.m_Hp = loader.GetFloat(i, 5);
		status.m_Str = loader.GetInteger(i, 6);
		status.m_Dex = loader.GetInteger(i, 7);

		info = aqua::CreateGameObject<CCharactorInfo>(this);

		info->Initialize
		(
			loader.GetString(i, 2),
			(JOB_ID)loader.GetInteger(i, 0),
			(SKILL_ID)loader.GetInteger(i, 3),
			status
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
	}

	loader.Unload();

	m_CharactorMaxNum = (int)m_Charactor.size();

	m_BackgroudSprite.Create("data\\select\\back_ground\\back_ground2.png");

	m_SelectBox.Setup
	(
		m_Charactor[0]->m_Position,
		m_Charactor[0]->GetSpriteSize().x,
		m_Charactor[0]->GetSpriteSize().y,
		m_box_color,
		false,
		m_box_thickness
	);

	m_SelectBlendBox.Setup
	(
		m_Charactor[0]->m_Position,
		m_Charactor[0]->GetSpriteSize().x,
		m_Charactor[0]->GetSpriteSize().y,
		m_box_color
	);

	m_SelectBlendBox.color.alpha = (unsigned char)100;
}

void CSelectCharactor::Update()
{
	SelectCharactor();

	aqua::IGameObject::Update();
}

void CSelectCharactor::Draw()
{
	m_BackgroudSprite.Draw();
	aqua::IGameObject::Draw();
	m_SelectBlendBox.Draw();
	m_SelectBox.Draw();
}

void CSelectCharactor::Finalize()
{
	m_BackgroudSprite.Delete();

	for (auto& it : m_Charactor)
	{
		it->Finalize();
		
		aqua::ListErase(&m_ChildObjectList, it);

		AQUA_SAFE_DELETE(it);
	}

	m_Charactor.clear();

	aqua::IGameObject::Finalize();
}

void CSelectCharactor::SelectCharactor()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RIGHT))
	{
		if(m_SelectCharactor++ >= m_CharactorMaxNum)
			m_SelectCharactor = 0;

		// ボックスの座標を変更
	}

	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::LEFT))
		m_SelectCharactor--;

	m_SelectCharactor = aqua::Limit(m_SelectCharactor, 0, m_CharactorMaxNum);

}
