#pragma once
#include "aqua.h"

class Shake;

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

	/*
	 *  @brief 点滅
	 */
	void FlashingColor();

	/*!
	 *  @brief テキストの大きさ
	 */
	aqua::CVector2 GetTextSize();

	/*!
	 *  @brief テキストの座標
	 */
	void SetPosition(aqua::CVector2 position);

private:

	static const aqua::CPoint	m_font_space;
	static const aqua::CPoint	m_shake_noise;
	static const float			m_shake_interval;
	static const int			m_shake_max_count;
	static const int			m_flashing_max_time;
	static const int			m_max_both_ends;
	static const unsigned char  m_flashing_alpha;

	aqua::CLabel    m_TextLabel;					//! 
	aqua::CSprite   m_TextBox;						//! 
	aqua::CSprite*  m_TextBothEnds;					//! 
	aqua::CPoint    m_TextSize;						//! 

	aqua::CSprite   m_FlashingTextBox;				//! 
	aqua::CSprite*  m_FlashingTextBothEnds;			//! 
	bool            m_FlashingFlag;					//! 
	bool            m_PrevFlashingFlag;				//! 
	int             m_FlashingFrame;				//! 
	int             m_FlashingTime;					//! 

	Shake*          m_Shake;						//! 

	aqua::CVector2  m_TextLabelPosition;			//! 
	aqua::CVector2  m_TextBoxPosition;				//! 
	aqua::CVector2* m_TextBothEndsPosition;			//! 
	aqua::CVector2  m_FlashingTextBoxPosition;		//! 
	aqua::CVector2* m_FlashingTextBothEndsPosition; //! 

};