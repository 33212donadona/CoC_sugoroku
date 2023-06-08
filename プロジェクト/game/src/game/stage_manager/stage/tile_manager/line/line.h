#pragma once
#include "aqua.h"

using LinePair = std::pair<aqua::CSprite*, bool*>;
using LineList = std::list<LinePair*>;

enum class LineWay
{
	FROM,
	TO,

	MAX
};

class CLine :
	public aqua::IGameObject
{
public:

	CLine(aqua::IGameObject* parent);
	~CLine() = default;

	/*
	 * @brief 初期化
	 */
	void Initialize(aqua::CVector2* start_pos, aqua::CVector2* end_pos,int tile_id,int from_id);

	/*
	 * @brief 更新
	 */
	void Update()override;

	/*
	 * @brief 描画
	 */
	void Draw()override;

	/*
	 * @brief 解放
	 */
	void Finalize()override;

	/*
	 * @brief 矢印の描画
	 * 
	 */
	static void ArrowDraw();

	/*
	 * @brief 始点終点のタイル番号を取得
	 */
	int GetWayTileID(LineWay way);

	static LineList m_ArrowSpriteList;    // 矢印画像リスト

	bool visible;                         // 

private:

	static const float m_LineThick;       // 線の太さ
	static const float m_ArrowSize;       // 矢印の大きさ
										  
	aqua::CVector2* m_FirstPosition;      // 始点座標のポインタ
	aqua::CVector2* m_TergetPosition;     // 終点座標のポインタ
	aqua::CVector2  m_Distance;           // 距離
	aqua::CSprite   m_ArrowSprite;        // 矢印画像
	aqua::CSprite   m_LineSprite;         // 線画像
										  
	LinePair        m_LinePair;           // 矢印のペア
										  
	int*            m_RefalenceTileID;    // 始点終点のタイル番号
};