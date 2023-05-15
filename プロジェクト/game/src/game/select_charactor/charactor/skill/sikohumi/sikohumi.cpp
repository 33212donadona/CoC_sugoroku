#include "sikohumi.h"

CSikohumi::CSikohumi(aqua::IGameObject* parent)
	:ISkill(parent, "Sikohumi")
{
}

void CSikohumi::Update()
{
}

void CSikohumi::InvokeSkill(STATUS& m_MyChara, STATUS_LIST& m_SubjectChara)
{
	for (auto& it : m_SubjectChara)
	{
		it.m_Terget = m_MyChara.m_Player;
	}
}
