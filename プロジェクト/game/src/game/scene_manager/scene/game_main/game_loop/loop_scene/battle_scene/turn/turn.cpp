#include "turn.h"
#include "../../../../../../../common_data/common_data.h"
#include "../../../../../../../select_charactor/charactor/charactor_info.h"
#include <algorithm>
#include <tuple>

const int            CTurn::m_menu_font_size = 20;
const float          CTurn::m_box_thickness = 20.0f;
const unsigned char  CTurn::m_box_alpha = 150;
const aqua::CVector2 CTurn::m_player_box_pos(50, 50);
const std::string    CTurn::m_menu_name[(int)MENU_ID::MAX] =
{
	"攻撃",
	"スキル",
	"回避"
};

struct StatusLess
{
	bool operator()(const STATUS* a, const STATUS* b) const {
		//比較したい要素を列挙
		return std::tie(a->m_Dex) < std::tie(b->m_Dex);
	}
};

CTurn::CTurn(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Turn")
	, m_TurnNum(0)
	, m_NowTurnID(TURN_ID::PLAYER)
	, m_NowMenuID(MENU_ID::ATTACK)
{
}

/*
*  初期化
*/
void CTurn::Initialize()
{
	m_CommonData = (CCommonData*)aqua::FindGameObject("CommonData");

	// メニューラベル
	for (int menu_i = 0; menu_i < (int)MENU_ID::MAX; ++menu_i)
	{
		m_MenuLabel[menu_i].Create(m_menu_font_size);
		m_MenuLabel[menu_i].text = m_menu_name[menu_i];
	}

	for (int i = 0; i < (int)PLAYER_ID::DUMMY; ++i)
	{
		m_Player.push_back(m_CommonData->RefarenceChara((PLAYER_ID)i)->GetStatus());
	}

	std::sort(m_Player.begin(), m_Player.end(), StatusLess{});

	m_MaxTurn = (int)m_Player.size();

	aqua::CVector2  icon_size = m_CommonData->RefarenceChara(PLAYER_ID::PL1)->GetSpriteSize();

	// キャラクターの枠
	for (int player_i = 0; player_i > (int)PLAYER_ID::DUMMY; ++player_i)
	{
		m_PlayerBox[player_i].Setup
		(
			m_player_box_pos + aqua::CVector2((float)player_i * icon_size.x, 0.0f),
			icon_size.x,
			icon_size.y,
			aqua::CColor::BLACK,
			TRUE,
			m_box_thickness
		);

		m_CommonData->RefarenceChara((PLAYER_ID)player_i)->m_Position = m_PlayerBox[player_i].position;
	}

	m_SelectBox = m_PlayerBox[(int)PLAYER_ID::PL1];
	m_SelectBox.color = aqua::CColor::YELLOW;
	m_SelectBox.color.alpha = m_box_alpha;

	m_MenuLabel[(int)m_NowMenuID].color = aqua::CColor::YELLOW;

}

/*
*  更新
*/
void CTurn::Update()
{
	SelectCommand();

	m_ChangeTurn = aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN);

	if (m_ChangeTurn)
	{
		switch (m_NowMenuID)
		{
		case MENU_ID::ATTACK:

			m_Status->m_Hp -= m_Player[m_TurnNum]->m_Str;

			break;

		case MENU_ID::SKIIL:

			SKILL_ID id = m_CommonData->RefarenceChara((PLAYER_ID)m_TurnNum)->GetSkillID();

			switch (id)
			{
			case SKILL_ID::FIRING:
			case SKILL_ID::SCOLDING:
			case SKILL_ID::STEEL_MUSCLE:
			case SKILL_ID::SIKOHUMI:
			case SKILL_ID::EMERGENCY_SURGERY:

				m_CommonData->RefarenceChara((PLAYER_ID)m_TurnNum)->InvokeSkill(*m_Status);

				break;

			case SKILL_ID::FINALE:
			case SKILL_ID::QUIBBLE:
			case SKILL_ID::DOSE:
			case SKILL_ID::MAX:

				m_CommonData->RefarenceChara((PLAYER_ID)m_TurnNum)->InvokeSkill(*m_StatusLIST);

				break;
			}

			break;

		case MENU_ID::AVERT:

			break;
		}
	}

	m_TurnNum = aqua::Mod(m_TurnNum + m_ChangeTurn, 0, m_MaxTurn);

	if (m_ChangeTurn)
	{
		m_SelectBox.position = m_PlayerBox[m_TurnNum].position;
	}
}

/*
*  描画
*/
void CTurn::Draw()
{
	for (int menu_i = 0; menu_i < (int)MENU_ID::MAX; ++menu_i)
	{
		m_MenuLabel[menu_i].Draw();
	}

	for (int player_i = 0; player_i > (int)PLAYER_ID::DUMMY; ++player_i)
	{
		m_PlayerBox[player_i].Draw();
		m_CommonData->RefarenceChara((PLAYER_ID)player_i)->TextBoxCharaDraw();
	}

	m_SelectBox.Draw();
}

/*
*  解放
*/
void CTurn::Finalize()
{
	for (int menu_i = 0; menu_i < (int)MENU_ID::MAX; ++menu_i)
	{
		m_MenuLabel[menu_i].Delete();
	}
}

/*
*  コマンドの選択
*/
void CTurn::SelectCommand()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::S) ||
		aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::W))
	{
		int add = 
			aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::S) -
			aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::W);

		//  文字を白くする
		m_MenuLabel[(int)m_NowMenuID].color = aqua::CColor::WHITE; 

		//  選択コマンドを移動
		m_NowMenuID = aqua::Mod((MENU_ID)((int)m_NowMenuID + add), MENU_ID::ATTACK, MENU_ID::MAX);

		//　文字を黄色にする
		m_MenuLabel[(int)m_NowMenuID].color = aqua::CColor::YELLOW;
	}



}
