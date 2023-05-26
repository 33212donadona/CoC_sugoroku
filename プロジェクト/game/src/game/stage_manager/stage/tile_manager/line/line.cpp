#include "line.h"
#include <cmath>

std::list<aqua::CSprite*> CLine::m_ArrowSpriteList;

const float CLine::m_LineThick = 30.0f;
const float CLine::m_ArrowSize = 1.2f;

CLine::CLine(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Line")
	, m_TergetPosition(nullptr)
	, m_FirstPosition(nullptr)
{
	m_ArrowSpriteList.push_back(&m_ArrowSprite);
}

/*
 * èâä˙âª
 */
void CLine::Initialize(aqua::CVector2* start_pos, aqua::CVector2* end_pos)
{
	m_FirstPosition = start_pos;
	m_TergetPosition = end_pos;

	for (int i = 0; i < (int)LineWay::MAX; i++)
		m_RefalenceTileID[i] = 0;

	m_LineSprite.Create("data\\line\\line.png");
	m_LineSprite.anchor.y = m_LineSprite.GetTextureHeight() / 2.0f;

	m_LineSprite.position = *m_FirstPosition;
	m_LineSprite.position.y -= m_LineSprite.GetTextureHeight() / 2.0f;

	m_LineSprite.rotation = atan2(m_TergetPosition->y - m_FirstPosition->y, m_TergetPosition->x - m_FirstPosition->x);

	m_Distance.x = (m_TergetPosition->x - m_FirstPosition->x);
	m_Distance.x *= m_Distance.x;
	m_Distance.y = (m_TergetPosition->y - m_FirstPosition->y);
	m_Distance.y *= m_Distance.y;

	m_LineSprite.scale.x = std::sqrt(m_Distance.x + m_Distance.y) / m_LineSprite.GetTextureWidth();

	m_ArrowSprite.Create("data\\line\\arrow.png");
	m_ArrowSprite.scale = aqua::CVector2::ONE * m_ArrowSize;
	m_ArrowSprite.anchor.x = m_ArrowSprite.GetTextureWidth() / 2.0f * m_ArrowSprite.scale.x;
	m_ArrowSprite.anchor.y = m_ArrowSprite.GetTextureHeight() / 2.0f * m_ArrowSprite.scale.y;
	m_ArrowSprite.position = *m_FirstPosition;
	m_ArrowSprite.position += (*m_TergetPosition - *m_FirstPosition) / 2.0f - m_ArrowSprite.anchor;
	m_ArrowSprite.rotation = m_LineSprite.rotation;

}

/*
 * çXêV
 */
void CLine::Update()
{

}

/*
 * ï`âÊ
 */
void CLine::Draw()
{
	m_LineSprite.Draw();
}

/*
 * âï˙
 */
void CLine::Finalize()
{
	aqua::ListErase(&m_ArrowSpriteList, &m_ArrowSprite);
	m_ArrowSprite.Delete();
}

void CLine::ArrowDraw()
{
	if (m_ArrowSpriteList.empty())return;

	for (auto& it : m_ArrowSpriteList)
	{
		it->Draw();
	}
}
