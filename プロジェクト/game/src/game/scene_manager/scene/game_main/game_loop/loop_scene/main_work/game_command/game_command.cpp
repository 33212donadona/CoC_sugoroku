#include "game_command.h"

namespace key = aqua::keyboard;

const std::string CGameCommand::m_CommandName[] =
{
	"サイコロを振る",
	"他とチームを組む"
};
const float CGameCommand::m_change_dice_time = 0.5f;
const int CGameCommand::m_rand_pattern = 2;
const int CGameCommand::m_max_dice = 6;
const int CGameCommand::m_rand_dice[m_rand_pattern][m_max_dice]
{
	{
		1,4,5,2,6,3
     },

	{
		5,2,4,6,3,1
    }
};

CGameCommand::CGameCommand(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GameCommand")
	, m_NowSelectCommand(CommandID::DICE)
	, m_UpdateCommand(false)
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

	
	float dice_sprite_h = 0.0f;

	for (int dice_sprite_i = 0; dice_sprite_i < m_max_dice; ++dice_sprite_i)
	{
		m_DiceSprite[dice_sprite_i].Create("data\\game_main\\UI\\dice.png");

		if (dice_sprite_h == 0.0f)
			dice_sprite_h = m_DiceSprite[dice_sprite_i].GetTextureHeight() / 6;

		m_DiceSprite[dice_sprite_i].rect.top    = dice_sprite_h * dice_sprite_i;
		m_DiceSprite[dice_sprite_i].rect.bottom = dice_sprite_h * (dice_sprite_i + 1);
	}

	int rand_dice = aqua::Rand(m_rand_pattern - 1); //TODO

	for (int dice_i = 0; dice_i < m_max_dice; ++dice_i)
	{
		m_DrawDiceSprite.push_back(&m_DiceSprite[m_rand_dice[rand_dice][dice_i] - 1]);
	}

	m_ChangeDiceTimer.Setup(m_change_dice_time);
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
	if (key::Trigger(key::KEY_ID::S))
	{
		m_NowSelectCommand =
			aqua::Mod<CommandID, int>((int)m_NowSelectCommand - 1, CommandID::DICE, CommandID::MAX);
	}
}

void CGameCommand::DiceCommand()
{

}

void CGameCommand::TeamCommand()
{
}
