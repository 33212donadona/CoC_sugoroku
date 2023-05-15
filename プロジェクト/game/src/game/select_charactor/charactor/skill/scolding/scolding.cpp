#include "scolding.h"

const int CScolding::m_strength_up = 2;

CScolding::CScolding(aqua::IGameObject* parent)
	:ISkill(parent,"Scolding")
	, m_MyStatus(nullptr)
{
}

void CScolding::Update()
{
}

void CScolding::Finalize()
{
	(*m_MyStatus).m_Str -= m_strength_up;
	AQUA_SAFE_DELETE(m_MyStatus);
}

void CScolding::InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara)
{
	m_MyStatus = &m_MyChara;
	m_SubjectChara.m_Hp -= (*m_MyStatus).m_Str;
	(*m_MyStatus).m_Str += m_strength_up;
}
