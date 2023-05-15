#include "quibble.h"

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

void CQuibble::InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara)
{
}
