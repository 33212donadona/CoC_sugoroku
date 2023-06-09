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

		m_Position[(int)m_PlayerID] = m_PlayerIcom[(int)m_PlayerID].position;

		m_PlayerTileID[i]    =  1;
		m_FromPosition[i]    = *m_TileManager->GetTilePosition(1);
		m_FromPosition[i].x -=  m_PlayerIcom[i].GetTextureWidth() / 2;
		m_FromPosition[i].y -=  m_PlayerIcom[i].GetTextureHeight();

		m_EasingTime[i].Setup(m_max_easing_time);

	}

}

void CCharactorMapMove::Update()
{
	for (int i = 0; i < (int)PLAYER_ID::DUMMY; ++i)
	{
		if (m_PlayerIcom[i].position != m_FromPosition[i])
		{
			if (m_EasingTime[i].Finished())
				m_EasingTime[i].SetTime(m_EasingTime[i].GetLimit());

			m_PlayerIcom[i].position.x =
				aqua::easing::InCubic
				(
					m_EasingTime[i].GetTime(),
					m_EasingTime[i].GetLimit(),
					m_Position[i].x,
					m_FromPosition[i].x
				);

			m_PlayerIcom[i].position.y =
				aqua::easing::InCubic
				(
					m_EasingTime[i].GetTime(),
					m_EasingTime[i].GetLimit(),
					m_Position[i].y,
					m_FromPosition[i].y
				);

			m_EasingTime[i].Update();

		}
		else
		{
			m_EasingTime[i].Reset();
		}
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

	aqua::IGameObject::Finalize();
}

void CCharactorMapMove::SetPlayerID(PLAYER_ID id)
{
	if (id == PLAYER_ID::DUMMY)return;
	m_PlayerID = id;
	m_FromPosition[(int)m_PlayerID] = m_PlayerIcom[(int)m_PlayerID].position;
}

int CCharactorMapMove::GetPlayerTileID(PLAYER_ID id)
{
	if (id == PLAYER_ID::DUMMY)return 0;

	return m_PlayerTileID[(int)id];
}

bool CCharactorMapMove::SetPlayerTileID(int tile_id)
{
	m_PlayerTileID[(int)m_PlayerID] = tile_id;

	if (!m_EasingTime[(int)m_PlayerID].Finished())
	{

		m_Position[(int)m_PlayerID]        =  m_PlayerIcom[(int)m_PlayerID].position;

		m_FromPosition[(int)m_PlayerID]    = *m_TileManager->GetTilePosition(tile_id);
		m_FromPosition[(int)m_PlayerID].x -=  m_PlayerIcom[(int)m_PlayerID].GetTextureWidth() / 2;
		m_FromPosition[(int)m_PlayerID].y -=  m_PlayerIcom[(int)m_PlayerID].GetTextureHeight();

	}

	return m_EasingTime[(int)m_PlayerID].Finished();
}

int CCharactorMapMove::GetFromTileSize(int tile_id)
{
	if (tile_id <= 0 || tile_id - 1 > m_TileManager->GetTileSize())
		return 1;

	return (int)m_TileManager->GetNextTileID(tile_id)->size();
}