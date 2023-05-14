#pragma once
#include "aqua.h"

class CLine :
	public aqua::IGameObject
{
public:

	CLine(aqua::IGameObject* parent);
	~CLine() = default;

	/*
	 * @brief 初期化
	 */
	void Initialize(aqua::CVector2* start_pos, aqua::CVector2* end_pos);

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


	static std::list<aqua::CSprite*> m_ArrowSpriteList;    // 矢印画像リスト

private:

	enum class LineWay
	{
		FROM,
		TO,

		MAX
	};

private:

	static const float m_LineThick;                        // 線の太さ
	static const float m_ArrowSize;                        // 矢印の大きさ

	aqua::CVector2* m_FirstPosition;                       // 始点座標のポインタ
	aqua::CVector2* m_TergetPosition;                      // 終点座標のポインタ
	aqua::CVector2  m_Distance;                            // 距離
	aqua::CSprite   m_ArrowSprite;                         // 矢印画像
	aqua::CSprite   m_LineSprite;                          // 線画像

	int*            m_RefalenceTileID[(int)LineWay::MAX];  // 始点終点のタイル番号
};