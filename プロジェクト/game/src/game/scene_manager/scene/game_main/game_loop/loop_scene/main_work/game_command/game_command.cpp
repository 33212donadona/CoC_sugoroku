#include "game_command.h"
#include "dice/dice.h"
#include "../charactor_map_move/charactor_map_move.h"
#include "select_tile_text/select_tile_text.h"
#include "../../../../../../../stage_manager/stage/tile_manager/tile_manager.h"
#include "../../../../../../../select_charactor/charactor/charactor_id.h"

namespace key = aqua::keyboard;

const int  CGameCommand::m_select_text_size = 120;
const std::string CGameCommand::m_CommandName[] =
{
	"サイコロを振る",
	"他とチームを組む"
};

CGameCommand::CGameCommand(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GameCommand")
	, m_NowSelectCommand(CommandID::DICE)
	, m_UpdateCommand(false)
	, m_DiceClass(nullptr)
	, m_TileManager(nullptr)
	, m_MoveTile(0)
	, m_PlayerID(PLAYER_ID::PL1)
{
}

/*
 * 初期化
 */
void CGameCommand::Initialize(aqua::CVector2 position)
{
	for (int i = (int)CommandID::DICE; i < (int)CommandID::MAX; ++i)
	{
		aqua::CLabel label;

		label.Create(40);
		label.text = m_CommandName[i];
		label.position = position;

		m_CommandLabel.push_back(label);
		label.Delete();
	}

	m_CommandLabel[(int)m_NowSelectCommand].color = aqua::CColor::YELLOW;

	m_CommandLabel[(int)CommandID::TEAM].position.y +=
		m_CommandLabel[(int)CommandID::DICE].GetFontHeight() * 2.0f;

	m_CharactorMapMove = (CCharactorMapMove*)aqua::FindGameObject("CharactorMapMove");
	m_TileManager = (CTileManager*)aqua::FindGameObject("TileManager");
}

/*
 * 更新
 */
void CGameCommand::Update()
{
	m_PrevUpdateCommand = m_UpdateCommand;

	if (m_UpdateCommand)
	{
		switch (m_NowSelectCommand)
		{
		case CommandID::DICE:

			DiceCommand();

			break;
		case CommandID::TEAM:

			TeamCommand();

			break;
		}
	}
	else
	{
		m_UpdateCommand = key::Trigger(key::KEY_ID::RETURN);
		SelectCommand();
	}
}

/*
 * 描画
 */
void CGameCommand::Draw()
{
	for (auto& label : m_CommandLabel)
	{
		label.Draw();
	}

	if (m_DiceClass && m_DiceClass->GetDice() != -1)
	{
		m_DiceClass->Draw();
	}

	if (!m_SelectTextVector.empty())
	{
		for (auto& text_it : m_SelectTextVector)
			text_it->Draw();
	}

}

/*
 * 解放
 */
void CGameCommand::Finalize()
{
	for (auto& label : m_CommandLabel)
		label.Delete();

	if (!m_SelectTextVector.empty())
	{
		for (auto& text_it : m_SelectTextVector)
			text_it->Finalize();
	}
}

/*
 * コマンドの終わり
 */
bool CGameCommand::GetFinishedCommand()
{
	return !m_UpdateCommand && m_PrevUpdateCommand;
}

/*
 * プレイヤーのIDを書き換える
 */
void CGameCommand::SetPlayerID(PLAYER_ID id)
{
	m_PlayerID = id;
}

/*
 * コマンドの選択
 */
void CGameCommand::SelectCommand()
{
	if (key::Trigger(key::KEY_ID::W) || key::Trigger(key::KEY_ID::S))
	{
		int add = key::Trigger(key::KEY_ID::W) - key::Trigger(key::KEY_ID::S);

		m_NowSelectCommand =
			aqua::Mod<CommandID, int>((int)m_NowSelectCommand + add, (int)CommandID::DICE, (int)CommandID::MAX - 1);

		for (auto& label : m_CommandLabel)
		{
			label.color = aqua::CColor::WHITE;
		}

		m_CommandLabel[(int)m_NowSelectCommand].color = aqua::CColor::YELLOW;

	}

}

/*
 * サイコロを振るコマンド
 */
void CGameCommand::DiceCommand()
{
	if (!m_DiceClass)
	{
		m_DiceClass = aqua::CreateGameObject<CDice>(this);
		m_DiceClass->Initialize();
	}
	else
	{
		if (m_DiceClass->GetDice() != -1)
		{
			m_DiceClass->Update();

			if (m_DiceClass->GetDice() != -1)
				m_MoveTile = m_DiceClass->GetDice();
		}
		else
		{

			if (key::Trigger(key::KEY_ID::W) || key::Trigger(key::KEY_ID::S))
			{

				int add = key::Trigger(key::KEY_ID::S) - key::Trigger(key::KEY_ID::W);
				int tile_id = m_CharactorMapMove->GetPlayerTileID(m_PlayerID);

				m_TileManager->LineVisible(tile_id, (*m_TileManager->GetNextTileID(tile_id))[m_SelectFromTile]);
				
				m_SelectFromTile = aqua::Mod(m_SelectFromTile + add, 0, m_MaxFromTile - 1);

				m_TileManager->LineVisible(tile_id, (*m_TileManager->GetNextTileID(tile_id))[m_SelectFromTile]);

			}

			if (!m_SelectTextVector.empty())
			{

				for (auto& text_it : m_SelectTextVector)
					text_it->Update();

				m_SelectTextVector[m_SelectFromTile]->FlashingColor();

			}
			else
			{
				CreateSelectTileText();
			}

			if (key::Trigger(key::KEY_ID::RETURN))
			{

				int tile = m_CharactorMapMove->GetPlayerTileID(m_PlayerID);
				int from_tile = (*m_TileManager->GetNextTileID(tile))[m_SelectFromTile];

				m_TileManager->LineVisible(tile, from_tile);

				m_CharactorMapMove->SetPlayerTileID(from_tile);

				for (auto& text_it : m_SelectTextVector)
				{

					text_it->Finalize();

					aqua::ListErase(&m_ChildObjectList, text_it);

				}

				m_SelectTextVector.clear();

				m_MoveTile--;

				if (m_MoveTile == 0)
				{
					m_UpdateCommand = false;

					m_DiceClass->Finalize();
					m_DiceClass = nullptr;
				}
			}
		}
	}
}

/*
 * チームを組むコマンド
 */
void CGameCommand::TeamCommand()
{
	m_UpdateCommand = false;
}

/*
 * 選択肢の生成
 */
void CGameCommand::CreateSelectTileText()
{

	m_SelectFromTile = 0;

	int tile_id = m_CharactorMapMove->GetPlayerTileID(m_PlayerID);
	m_TileManager->LineVisible(tile_id, (*m_TileManager->GetNextTileID(tile_id))[m_SelectFromTile]);
	m_MaxFromTile = m_CharactorMapMove->GetFromTileSize(tile_id);

	for (int i = 0; i < m_MaxFromTile; ++i)
	{

		CSelectTileText* text;
		aqua::CVector2 position;
		text = aqua::CreateGameObject<CSelectTileText>(this);

		int from_tile = (*m_TileManager->GetNextTileID(tile_id))[i];
		text->Initialize("タイル" + std::to_string(from_tile) + "へ", aqua::GetWindowSize() / 2.0f, m_select_text_size);

		position.x = aqua::GetWindowWidth()   - text->GetTextSize().x / 2.0f;
		position.y = aqua::GetWindowHeight() / 2.0f  + text->GetTextSize().y * i;

		text->SetPosition(position);
		m_SelectTextVector.push_back(text);

	}
}
