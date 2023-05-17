#include "finale.h"
const float CFinale::m_finale_rate = 1.2f;

CFinale::CFinale(aqua::IGameObject* parent)
	:ISkill(parent,"Finale")
{
}

void CFinale::Update()
{
}

void CFinale::Finalize()
{
}

void CFinale::InvokeSkill(STATUS_LIST& m_SubjectChara)
{
	for (auto& it : m_SubjectChara)
	{
		it.m_Str *= m_finale_rate;
		it.m_Dex *= m_finale_rate;
	}
}
