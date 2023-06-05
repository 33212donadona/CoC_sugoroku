#pragma once
#include "aqua.h"

class CSelectTileText
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief コンストラクタ
	*/
	CSelectTileText(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CSelectTileText() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize(std::string text,aqua::CVector2 center_position,int font_size = 20);

	/*!
	 *  @brief 更新
	 */
	void Update()override;

	/*!
	 *  @brief 描画
	 */
	void Draw()override;

	/*!
	 *  @brief 解放
	 */
	void Finalize()override;

private:
	static const aqua::CPoint m_font_space;
	static const aqua::CPoint m_shake_noise;
	static const float m_shake_interval;
	static const int   m_shake_max_count;

	aqua::CLabel  m_TextLabel;
	aqua::CSprite m_TextBox;
	aqua::CSprite m_TextBothEnds[2];


	aqua::CVector2 m_ShakeMove;
	aqua::CTimer  m_ShakeTimer;
	int m_ShakeCount;
	float m_Angle;

};