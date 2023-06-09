#include "main_game_work.h"
#include "../../../../../../common_data/common_data.h"
#include "../../../../../../select_charactor/charactor/charactor_info.h"
#include "game_command/game_command.h"
#include "charactor_map_move/charactor_map_move.h"

const aqua::CPoint   CMainGameWork::m_text_box_space(20, 15);
const int            CMainGameWork::m_font_size = 30;

CMainGameWork::CMainGameWork(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "MainGameWork")
	, m_NowPlayerID(PLAYER_ID::PL4)
	, m_Status(nullptr)
{
}

/*
 * 初期化 
 */
void CMainGameWork::Initialize()
{
	m_TextBoxSprite.Create("data\\game_main\\UI\\text_box.png");
	m_TextBoxSprite.position.y = (float)(aqua::GetWindowHeight() - m_TextBoxSprite.GetTextureHeight());

	m_CommonData = (CCommonData*)aqua::FindGameObject("CommonData");

	// キャラクターの設定
	if (m_CommonData)
	{
		for (int i = (int)PLAYER_ID::PL1; i < (int)PLAYER_ID::DUMMY; ++i)
		{
			(*m_CommonData).RefarenceChara((PLAYER_ID)i)->m_Position = m_TextBoxSprite.position;

			(*m_CommonData).RefarenceChara((PLAYER_ID)i)->m_Scale = aqua::CVector2::ONE;

			(*m_CommonData).RefarenceChara((PLAYER_ID)i)->Update();
		}
	}

	m_LabelHP.Create(m_font_size);
	m_LabelSTR.Create(m_font_size);
	m_LabelDEX.Create(m_font_size);

	m_Status = (*m_CommonData).RefarenceChara(PLAYER_ID::PL1)->GetStatus();

	SetUpStatus();

	m_LabelHP.position = (*m_CommonData).RefarenceChara(PLAYER_ID::PL1)->m_Position + m_text_box_space;

	m_LabelHP.position.x += (*m_CommonData).RefarenceChara(PLAYER_ID::PL1)->GetSpriteSize().x / 2.0f;
	m_LabelSTR.position.x = m_LabelHP.position.x;
	m_LabelDEX.position.x = m_LabelSTR.position.x;

	m_LabelSTR.position.y = m_LabelHP.position.y + m_LabelHP.GetFontHeight();
	m_LabelDEX.position.y = m_LabelSTR.position.y + m_LabelSTR.GetFontHeight();

	m_CharactorMapMove = aqua::CreateGameObject<CCharactorMapMove>(this);
	m_CharactorMapMove->Initialize();

	m_GameCommand = aqua::CreateGameObject<CGameCommand>(this);
	m_GameCommand->Initialize(m_LabelHP.position + aqua::CVector2(m_LabelHP.GetTextWidth(),0) + m_text_box_space);

}

/*
 * 更新 
 */
void CMainGameWork::Update()
{
	CharaStatusUpdate();

	m_CharactorMapMove->Update();

	m_GameCommand->Update();

	if (m_TextBoxSprite.color.GetColor() != m_CommonData->GetPlayerColor(m_NowPlayerID))
	{
		m_TextBoxSprite.color = m_CommonData->GetPlayerColor(m_NowPlayerID);
	}
}

/*
 * 描画 
 */
void CMainGameWork::Draw()
{
	m_TextBoxSprite.Draw();

	if (m_CommonData)
	{
		(*m_CommonData).RefarenceChara(m_NowPlayerID)->TextBoxCharaDraw();
	}

	m_LabelHP.Draw();
	m_LabelSTR.Draw();
	m_LabelDEX.Draw();

	m_CharactorMapMove->Draw();

	m_GameCommand->Draw();
}

/*
 * 解放 
 */
void CMainGameWork::Finalize()
{
	m_TextBoxSprite.Delete();

	m_LabelHP.Delete();
	m_LabelSTR.Delete();
	m_LabelDEX.Delete();

	m_CharactorMapMove->Finalize();
	m_GameCommand->Finalize();

	IGameObject::Finalize();
}

/*
 * 今のプレイヤー番号 
 */
PLAYER_ID CMainGameWork::GetNowPlayerID()
{
	return m_NowPlayerID;
}

/*
 *  キャラクターのステータス更新
 */
void CMainGameWork::CharaStatusUpdate()
{
	if (m_GameCommand->GetFinishedCommand()) // キャラクターが切り替わる
	{
		m_NowPlayerID = aqua::Mod<PLAYER_ID, int>((int)m_NowPlayerID + 1, (int)PLAYER_ID::PL1, (int)PLAYER_ID::PL4);

		m_CharactorMapMove->SetPlayerID(m_NowPlayerID);
		m_GameCommand->SetPlayerID(m_NowPlayerID);

		m_Status = (*m_CommonData).RefarenceChara(m_NowPlayerID)->GetStatus();

		SetUpStatus();
	}

	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::S)) // ダメージ
	{
		m_Status->m_Hp -= 0.2f;
		m_LabelHP.text = "HP  : " + aqua::FloatToString(m_Status->m_Hp) + " / " + aqua::FloatToString(m_Status->m_MaxHp);
	}
}

void CMainGameWork::SetUpStatus()
{
	m_LabelHP.text = "HP  : " + aqua::FloatToString(m_Status->m_Hp) + " / " + aqua::FloatToString(m_Status->m_MaxHp);
	m_LabelSTR.text = "STR : " + std::to_string(m_Status->m_Str);
	m_LabelDEX.text = "DEX : " + std::to_string(m_Status->m_Dex);
}