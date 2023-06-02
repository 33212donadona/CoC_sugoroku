#include "charactor_map_move.h"
#include "../../../../../../../stage_manager/stage/tile_manager/tile_manager.h"
#include "../../../../../../../common_data/common_data.h"
#include "../../main_work/main_game_work.h"
const float CCharactorMapMove::m_max_easing_time = 1.0f;

CCharactorMapMove::CCharactorMapMove(aqua::IGameObject* parent)
	:IGameObject(parent, "CharactorMapMove")
	, m_PlayerID(PLAYER_ID::PL1)
{
}

void CCharactorMapMove::Initialize()
{

	m_TileManager = (CTileManager*)aqua::FindGameObject("TileManager");
	m_MainGameWork = (CMainGameWork*)aqua::FindGameObject("MainGameWork");
	m_CommonData = (CCommonData*)aqua::FindGameObject("CommonData");

	for (int i = 0; i < (int)PLAYER_ID::DUMMY; i++)
	{
		m_PlayerIcom[i].Create("data\\game_main\\UI\\キャラアイコン.png");
		m_PlayerIcom[i].color = m_CommonData->GetPlayerColor((PLAYER_ID)i);
	}

	m_EasingTime.Setup(m_max_easing_time);
}

void CCharactorMapMove::Update()
{
	if (m_PlayerIcom[(int)m_PlayerID].position != m_PrevPosition)
	{
		m_PlayerIcom[(int)m_PlayerID].position.x =
			aqua::easing::InCubic
			(
				m_EasingTime.GetTime(),
				m_EasingTime.GetLimit(),
				m_Position.x,
				m_PrevPosition.x
			);

		m_PlayerIcom[(int)m_PlayerID].position.y =
			aqua::easing::InCubic
			(
				m_EasingTime.GetTime(),
				m_EasingTime.GetLimit(),
				m_Position.y,
				m_PrevPosition.y
			);

		m_EasingTime.Update();
	}
	else
	{
		m_EasingTime.Reset();
	}
}

void CCharactorMapMove::Draw()
{
	for (int i = 0; i < (int)PLAYER_ID::DUMMY; i++)
		m_PlayerIcom[i].Draw();
}

void CCharactorMapMove::Finalize()
{
	for (int i = 0; i < (int)PLAYER_ID::DUMMY; i++)
		m_PlayerIcom[i].Delete();
}

void CCharactorMapMove::SetPlayerID(PLAYER_ID id)
{
	if (id == PLAYER_ID::DUMMY)return;
	m_PlayerID = id;
}

bool CCharactorMapMove::SetPlayerPosition(int tile_id)
{
	if (!m_EasingTime.Finished())
	{
		m_Position = m_PlayerIcom[(int)m_PlayerID].position;
		m_PrevPosition = *m_TileManager->GetTilePosition(tile_id);
	}

	return m_EasingTime.Finished();
}