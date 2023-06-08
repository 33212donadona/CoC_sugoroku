#include "game_command.h"
#include "dice/dice.h"
#include "../charactor_map_move/charactor_map_move.h"
#include "select_tile_text/select_tile_text.h"
#include "../../../../../../../stage_manager/stage/tile_manager/tile_manager.h"
#include "../../../../../../../select_charactor/charactor/charactor_id.h"

namespace key = aqua::keyboard;

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

void CGameCommand::Update()
{

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

void CGameCommand::Finalize()
{
	for (auto& label : m_CommandLabel)
		label.Delete();

	if (!m_SelectTextVector.empty())
	{
		for (auto& text_it : m_SelectTextVector)
			text_it->Draw();
	}
}

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
			// TODO
			if (m_SelectTextVector.empty())
			{
				m_TileManager->LineVisible(m_CharactorMapMove->GetPlayerTileID(m_PlayerID));

				m_DiceClass->Finalize();

				m_SelectFromTile = 0;

				int tile_id = m_CharactorMapMove->GetPlayerTileID(m_PlayerID);
				m_MaxFromTile = m_CharactorMapMove->GetFromTileSize(tile_id);

				for (int i = 0; i < m_MaxFromTile; ++i)
				{
					CSelectTileText* text;
					aqua::CVector2 position;
					text = aqua::CreateGameObject<CSelectTileText>(this);
					text->Initialize("タイル" + std::to_string(i), aqua::GetWindowSize() / 2.0f, 80);

					position.x = aqua::GetWindowWidth() / 2.0f - text->GetTextSize().x / 2.0f;
					position.y = aqua::GetWindowHeight() / 2.0f + text->GetTextSize().y * i;

					text->SetPosition(position);
					m_SelectTextVector.push_back(text);

				}
			}

			if (key::Trigger(key::KEY_ID::W) || key::Trigger(key::KEY_ID::S))
			{

				int add = key::Trigger(key::KEY_ID::S) - key::Trigger(key::KEY_ID::W);

				m_SelectFromTile = aqua::Mod(m_SelectFromTile + add, 0, m_MaxFromTile - 1);

			}

			if (!m_SelectTextVector.empty())
			{
				for (auto& text_it : m_SelectTextVector)
					text_it->Update();

				m_SelectTextVector[m_SelectFromTile]->FlashingColor();
			}

			if (key::Trigger(key::KEY_ID::RETURN))
			{
				int tile = m_CharactorMapMove->GetPlayerTileID(m_PlayerID);
				int from_tile = (*m_TileManager->GetNextTileID(tile))[m_SelectFromTile];

				m_CharactorMapMove->SetPlayerPosition(from_tile);

				for (auto& text_it : m_SelectTextVector)
					text_it->Finalize();

				m_SelectTextVector.clear();

				m_MoveTile--;

				if (m_MoveTile == 0)
				{
					m_UpdateCommand = false;

					m_TileManager->LineVisible(m_CharactorMapMove->GetPlayerTileID(m_PlayerID));

					m_DiceClass->Finalize();
					m_DiceClass = nullptr;
				}
			}
		}
	}
}


void CGameCommand::TeamCommand()
{
	m_UpdateCommand = false;
}
