#include "dice.h"

namespace key = aqua::keyboard;

const float CDice::m_change_dice_time = 0.05f;
const float CDice::m_add_dice_time = 0.15f;
const float CDice::m_emphasis_dice_time = 2.0f;
const float CDice::m_emphasis_dice_max_size = 1.5f;
const float CDice::m_emphasis_dice_min_size = 1.0f;
const int CDice::m_aftertaste_max_count = 5;
const int CDice::m_rand_dice[dice::rand_pattern][dice::max_dice]
{
	{ 1,4,5,2,6,3},
	{ 5,2,4,6,3,1},
	{ 4,2,5,1,3,6},
	{ 3,6,5,4,2,1}
};

CDice::CDice(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Dice")
	, m_ReturnDice(false)
	, m_DiceNumber(0)
	, m_DiceAftertasteCount(0)
{
}

void CDice::Initialize()
{
	float dice_sprite_h = 0.0f;

	for (int dice_sprite_i = 0; dice_sprite_i < dice::max_dice; ++dice_sprite_i)
	{
		m_DiceSprite[dice_sprite_i].Create("data\\game_main\\UI\\dice.png");

		if (dice_sprite_h == 0.0f)
			dice_sprite_h = (float)(m_DiceSprite[dice_sprite_i].GetTextureHeight() / dice::max_dice);

		m_DiceSprite[dice_sprite_i].rect.top = (int)dice_sprite_h * dice_sprite_i;
		m_DiceSprite[dice_sprite_i].rect.bottom = (int)dice_sprite_h * (dice_sprite_i + 1);

		m_DiceSprite[dice_sprite_i].position.x =
			(aqua::GetWindowWidth() - m_DiceSprite[dice_sprite_i].GetTextureWidth()) / 2.0f;
		m_DiceSprite[dice_sprite_i].position.y =
			(aqua::GetWindowHeight() - dice_sprite_h) / 2.0f;

		m_DiceSprite[dice_sprite_i].anchor.x =
			m_DiceSprite[dice_sprite_i].GetTextureWidth() / 2.0f;
		m_DiceSprite[dice_sprite_i].anchor.y =
			dice_sprite_h / 2.0f ;

	}

	SetUpDice();

	// ŽžŠÔ
	m_ChangeDiceTimer.Setup(m_change_dice_time);
	m_EmphasisDiceTimer.Setup(m_emphasis_dice_time);

	// ”wŒi
	m_BackGround.Setup
	(
		aqua::CVector2::ZERO,
		(float)aqua::GetWindowWidth(),
		(float)aqua::GetWindowHeight(),
		0x77000000
	);
}

void CDice::Update()
{
	if (m_ChangeDiceTimer.Finished())
	{
		m_DiceNumber = aqua::Mod(m_DiceNumber + 1, 0, dice::max_dice - 1);

		if (m_ReturnDice)
		{
			m_ChangeDiceTimer.SetLimit(m_ChangeDiceTimer.GetLimit() + m_add_dice_time);
			m_DiceAftertasteCount++;
		}

		if (m_DiceAftertasteCount < m_aftertaste_max_count)
			m_ChangeDiceTimer.Reset();
	}

	if (!m_ReturnDice && key::Trigger(key::KEY_ID::RETURN))
		m_ReturnDice = true;

	if (m_DiceAftertasteCount < m_aftertaste_max_count)
		m_ChangeDiceTimer.Update();
	else
	{
		m_DrawDiceSprite[m_DiceNumber]->scale =
			aqua::CVector2::ONE *
			aqua::easing::OutBounce
			(
				m_EmphasisDiceTimer.GetTime(),
				m_EmphasisDiceTimer.GetLimit(),
				m_emphasis_dice_min_size,
				m_emphasis_dice_max_size
			);

		

		m_EmphasisDiceTimer.Update();
	}
}

void CDice::Draw()
{
	m_BackGround.Draw();
	m_DrawDiceSprite[m_DiceNumber]->Draw();
}

void CDice::Finalize()
{
	m_DrawDiceSprite.clear();

	for (int dice_sprite_i = 0; dice_sprite_i < dice::max_dice; ++dice_sprite_i)
		m_DiceSprite[dice_sprite_i].Delete();
}

int CDice::GetDice()
{
	if (m_DiceAftertasteCount < m_aftertaste_max_count || !m_EmphasisDiceTimer.Finished())
		return -1;

	return m_DiceNumber;
}

void CDice::SetUpDice()
{
	int rand_dice = aqua::Rand(dice::rand_pattern - 1);

	if (m_DrawDiceSprite.empty())
	{
		for (int dice_i = 0; dice_i < dice::max_dice; ++dice_i)
		{
			m_DrawDiceSprite.push_back(&m_DiceSprite[m_rand_dice[rand_dice][dice_i] - 1]);
		}
	}
}