#include "emergency_surgery.h"
const int CEmergencySurgery::m_max_heel = 6;
const int CEmergencySurgery::m_min_heel = 4;

CEmergencySurgery::CEmergencySurgery(aqua::IGameObject* parent)
	:ISkill(parent,"EmergencySurgery")
{
}

void CEmergencySurgery::Update()
{
}

void CEmergencySurgery::Finalize()
{
}

void CEmergencySurgery::InvokeSkill(STATUS& m_SubjectChara)
{
	m_SubjectChara.m_Hp += aqua::Rand(m_max_heel, m_min_heel);
}