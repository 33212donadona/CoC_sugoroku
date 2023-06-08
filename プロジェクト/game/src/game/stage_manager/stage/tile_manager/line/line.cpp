#include "line.h"
#include <cmath>

LineList CLine::m_ArrowSpriteList;

const float CLine::m_LineThick = 30.0f;
const float CLine::m_ArrowSize = 1.2f;

CLine::CLine(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Line")
	, visible(false)
	, m_TergetPosition(nullptr)
	, m_FirstPosition(nullptr)
{
	m_LinePair.first = &m_ArrowSprite;
	m_LinePair.second = &visible;

	m_ArrowSpriteList.push_back(&m_LinePair);
}

/*
 * 初期化
 */
void CLine::Initialize(aqua::CVector2* start_pos, aqua::CVector2* end_pos,int tile_id, int from_id)
{
	m_FirstPosition = start_pos;
	m_TergetPosition = end_pos;

	m_RefalenceTileID = AQUA_NEW int[(int)LineWay::MAX];

	m_RefalenceTileID[(int)LineWay::TO]   = tile_id;
	m_RefalenceTileID[(int)LineWay::FROM] = from_id;

	m_LineSprite.Create("data\\line\\line.png");
	m_LineSprite.anchor.y = m_LineSprite.GetTextureHeight() / 2.0f;

	m_LineSprite.position    = *m_FirstPosition;
	m_LineSprite.position.y -=  m_LineSprite.GetTextureHeight() / 2.0f;

	m_LineSprite.rotation = atan2(m_TergetPosition->y - m_FirstPosition->y, m_TergetPosition->x - m_FirstPosition->x);

	m_Distance.x  = (m_TergetPosition->x - m_FirstPosition->x);
	m_Distance.x *=  m_Distance.x;
	m_Distance.y  = (m_TergetPosition->y - m_FirstPosition->y);
	m_Distance.y *=  m_Distance.y;

	m_LineSprite.scale.x = std::sqrt(m_Distance.x + m_Distance.y) / m_LineSprite.GetTextureWidth();

	m_ArrowSprite.Create("data\\line\\arrow.png");
	m_ArrowSprite.scale     =   aqua::CVector2::ONE * m_ArrowSize;
	m_ArrowSprite.anchor.x  =   m_ArrowSprite.GetTextureWidth() / 2.0f * m_ArrowSprite.scale.x;
	m_ArrowSprite.anchor.y  =   m_ArrowSprite.GetTextureHeight() / 2.0f * m_ArrowSprite.scale.y;
	m_ArrowSprite.position  =  *m_FirstPosition;
	m_ArrowSprite.position += (*m_TergetPosition - *m_FirstPosition) / 2.0f - m_ArrowSprite.anchor;
	m_ArrowSprite.rotation  =   m_LineSprite.rotation;

}

/*
 * 更新
 */
void CLine::Update()
{

}

/*
 * 描画
 */
void CLine::Draw()
{
	m_LineSprite.Draw();
}

/*
 * 解放
 */
void CLine::Finalize()
{
	m_LinePair.first->Delete();

	aqua::ListErase(&m_ArrowSpriteList,&m_LinePair);
	m_ArrowSprite.Delete();

	AQUA_SAFE_DELETE_ARRAY(m_RefalenceTileID);
}

/*
 * 矢印の描画 
 */
void CLine::ArrowDraw()
{
	if (m_ArrowSpriteList.empty())return;

	for (auto& it : m_ArrowSpriteList)
	{
		if (*(it->second))
			it->first->Draw();
	}
}

/*
 *  始点終点のタイル番号を取得
 */
int CLine::GetWayTileID(LineWay way)
{
	if (way == LineWay::MAX)return 0;

	return m_RefalenceTileID[(int)way];
}