#include "line.h"

const float CLine::m_LineThick = 50.0f;

CLine::CLine(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Line")
{
}

void CLine::Initialize(aqua::CVector2* first_pos)
{
	m_FirstPosition = first_pos;
}

void CLine::Update()
{
	if (m_TergetPosition)
		m_PrevFirstPosition = *m_TergetPosition;
}

void CLine::Draw()
{
	DrawLineAA(m_FirstPosition->x, m_FirstPosition->y, m_PrevFirstPosition.x, m_PrevFirstPosition.y, 0xffffffff, m_LineThick);
}

void CLine::Finalize()
{
}
