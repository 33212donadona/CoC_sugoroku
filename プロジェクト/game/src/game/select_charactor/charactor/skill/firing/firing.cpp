#include "firing.h"
const float CFiring::m_firing_damage_rate = 2.5f;

CFiring::CFiring(aqua::IGameObject* parent)
	:ISkill(parent,"Firing")
{
}

void CFiring::Update()
{
}

void CFiring::Finalize()
{
}

void CFiring::InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara)
{
	m_SubjectChara.m_Hp -= (float)m_MyChara.m_Str * m_firing_damage_rate;
}
