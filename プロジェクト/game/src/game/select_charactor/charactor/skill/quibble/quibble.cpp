#include "quibble.h"
const int   CQuibble::m_quibble_damage = 1;
const float CQuibble::m_quibble_down_rate = 0.5f;


CQuibble::CQuibble(aqua::IGameObject* parent)
	:ISkill(parent,"Quibble")
{
}

void CQuibble::Update()
{
}

void CQuibble::Finalize()
{
}

void CQuibble::InvokeSkill(STATUS_LIST& m_SubjectChara)
{
	for (auto& it : m_SubjectChara)
	{
		it.m_Hp -= m_quibble_damage;
		it.m_Dex = (int)((float)it.m_Dex * m_quibble_down_rate);
	}
}