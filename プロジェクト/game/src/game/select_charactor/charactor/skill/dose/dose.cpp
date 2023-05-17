#include "dose.h"
const int CDose::m_max_heel = 3;
const int CDose::m_min_heel = 1;

CDose::CDose(aqua::IGameObject* parent)
	:ISkill(parent,"Dose")
{
}

void CDose::Update()
{

}

void CDose::Finalize()
{

}

void CDose::InvokeSkill(STATUS_LIST& m_SubjectChara)
{
	for (auto& it : m_SubjectChara)
		it.m_Hp += aqua::Rand(m_min_heel, m_min_heel);
}
