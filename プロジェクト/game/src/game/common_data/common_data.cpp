#include "common_data.h"
#include "../select_charactor/charactor/charactor_info.h"

const unsigned int  CCommonData::m_player_color[] =
{
	0xffff0000,
	0xff0000ff,
	0xff00ff00,
	0xffffff00
};

CCommonData::CCommonData(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"CommonData")
{
}

void CCommonData::Finalize()
{
	m_CharaList.clear();
}

void CCommonData::PushBack_Chara(CCharactorInfo info)
{
	m_CharaList.push_back(info);
}

void CCommonData::EraseBackChara()
{
	if (!m_CharaList.empty())
		m_CharaList.erase(m_CharaList.end() - 1);
}

bool CCommonData::EmptyChara()
{
	return m_CharaList.empty();
}

CCharactorInfo* CCommonData::RefarenceChara(PLAYER_ID player_id)
{
	if (player_id == PLAYER_ID::DUMMY)
		return &m_CharaList[(int)PLAYER_ID::PL1];
	
	return &m_CharaList[(int)player_id];
}

unsigned int CCommonData::GetPlayerColor(PLAYER_ID player_id)
{
	if (player_id == PLAYER_ID::DUMMY)return m_player_color[(int)PLAYER_ID::PL1];
	return m_player_color[(int)player_id];
}
