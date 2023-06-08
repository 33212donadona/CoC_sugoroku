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

		m_PlayerTileID[i] = 1;
	}

	m_EasingTime.Setup(m_max_easing_time);
}

void CCharactorMapMove::Update()
{
	if (m_PlayerIcom[(int)m_PlayerID].position != m_FromPosition)
	{
		if (m_EasingTime.Finished())
			m_EasingTime.SetTime(m_EasingTime.GetLimit());

		m_PlayerIcom[(int)m_PlayerID].position.x =
			aqua::easing::InCubic
			(
				m_EasingTime.GetTime(),
				m_EasingTime.GetLimit(),
				m_Position.x,
				m_FromPosition.x
			);

		m_PlayerIcom[(int)m_PlayerID].position.y =
			aqua::easing::InCubic
			(
				m_EasingTime.GetTime(),
				m_EasingTime.GetLimit(),
				m_Position.y,
				m_FromPosition.y
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
	m_FromPosition = m_PlayerIcom[(int)m_PlayerID].position;
}

int CCharactorMapMove::GetPlayerTileID(PLAYER_ID id)
{
	if (id == PLAYER_ID::DUMMY)return 0;

	return m_PlayerTileID[(int)id];

}

bool CCharactorMapMove::SetPlayerPosition(int tile_id)
{
	m_PlayerTileID[(int)m_PlayerID] = tile_id;

	if (!m_EasingTime.Finished())
	{

		m_Position = m_PlayerIcom[(int)m_PlayerID].position;
		m_FromPosition = *m_TileManager->GetTilePosition(tile_id);

	}

	return m_EasingTime.Finished();
}

int CCharactorMapMove::GetFromTileSize(int tile_id)
{
	if (tile_id < 0 || tile_id > m_TileManager->GetTileSize())
		return 0;

	return (int)m_TileManager->GetNextTileID(tile_id)->size();
}