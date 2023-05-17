#include "steel_muscle.h"

CSteelMuscle::CSteelMuscle(aqua::IGameObject* parent)
	:ISkill(parent,"SteelMuscle")
{
}

void CSteelMuscle::Update()
{
}

void CSteelMuscle::InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara)
{
	// çUåÇîºå∏ÇÃÇΩÇﬂÇÃâÒïú
	m_MyChara.m_Hp += (int)m_SubjectChara.m_Str / 2.0f;
	m_SubjectChara.m_Hp -= m_MyChara.m_Str;
}
