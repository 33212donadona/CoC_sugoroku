#include "common_data.h"
#include "../select_charactor/charactor/charactor_info.h"

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