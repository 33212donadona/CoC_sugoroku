#include "charactor_map_move.h"
#include "../../../../../stage_manager/stage/tile_manager/tile_manager.h"
#include "../../../../../common_data/common_data.h"
#include "../loop_scene/main_work/main_game_work.h"


CCharactorMapMove::CCharactorMapMove(aqua::IGameObject* parent)
	:IGameObject(parent,"CharactorMapMove")
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
}

void CCharactorMapMove::Update()
{

}

void CCharactorMapMove::Draw()
{

}

void CCharactorMapMove::Finalize()
{

}

void CCharactorMapMove::SetPlayerID(PLAYER_ID id)
{
	if (id == PLAYER_ID::DUMMY)return;
	m_PlayerID = id;
}

void CCharactorMapMove::SetPlayerPosition(int tile_id)
{
}
