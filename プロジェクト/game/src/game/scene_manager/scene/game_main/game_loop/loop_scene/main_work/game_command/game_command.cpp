#include "game_command.h"

namespace key = aqua::keyboard;

const std::string CGameCommand::m_CommandName[] =
{
	"サイコロを振る",
	"他とチームを組む"
};

CGameCommand::CGameCommand(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"GameCommand")
	, m_NowSelectCommand(CommandID::DICE)
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

	m_CommandLabel[(int)CommandID::TEAM].position.y +=
		m_CommandLabel[(int)CommandID::DICE].GetFontHeight() * 2.0f;

}

void CGameCommand::Update()
{
	SelectCommand();
}

void CGameCommand::Draw()
{
	for (auto& label : m_CommandLabel)
		label.Draw();
}

void CGameCommand::Finalize()
{
	for (auto& label : m_CommandLabel)
		label.Delete();
}

void CGameCommand::SelectCommand()
{
	if (key::Trigger(key::KEY_ID::W))
	{
		m_NowSelectCommand =
			aqua::Mod<CommandID, int>((int)m_NowSelectCommand + 1, CommandID::DICE, CommandID::MAX);


	}
}

void CGameCommand::DiceCommand()
{
}

void CGameCommand::TeamCommand()
{
}
