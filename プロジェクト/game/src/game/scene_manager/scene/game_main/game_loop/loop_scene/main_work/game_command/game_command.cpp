#include "game_command.h"
#include "dice/dice.h"

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
	}

	m_CommandLabel[(int)m_NowSelectCommand].color = aqua::CColor::YELLOW;

	m_CommandLabel[(int)CommandID::TEAM].position.y +=
		m_CommandLabel[(int)CommandID::DICE].GetFontHeight() * 2.0f;
}

void CGameCommand::Update()
{
	SelectCommand();

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
		m_UpdateCommand = key::Trigger(key::KEY_ID::RETURN);
}

void CGameCommand::Draw()
{
	for (auto& label : m_CommandLabel)
	{
		label.Draw();
	}
	
	if (m_DiceClass)
	{
		m_DiceClass->Draw();
	}

}

void CGameCommand::Finalize()
{
	for (auto& label : m_CommandLabel)
		label.Delete();
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
		m_DiceClass->Update();

		if (m_DiceClass->GetDice() != -1)
		{
			m_DiceClass->Finalize();
			m_DiceClass = nullptr;
			m_UpdateCommand = false;
		}
	}
}


void CGameCommand::TeamCommand()
{
	m_UpdateCommand = false;
}
