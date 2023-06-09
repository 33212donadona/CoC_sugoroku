#pragma once
#include "aqua.h"

class Shake;

class CSelectTileText
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief �R���X�g���N�^
	*/
	CSelectTileText(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CSelectTileText() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize(std::string text,aqua::CVector2 center_position,int font_size = 20);

	/*!
	 *  @brief �X�V
	 */
	void Update()override;

	/*!
	 *  @brief �`��
	 */
	void Draw()override;

	/*!
	 *  @brief ���
	 */
	void Finalize()override;

	/*
	 *  @brief �_��
	 */
	void FlashingColor();

	/*!
	 *  @brief �e�L�X�g�̑傫��
	 */
	aqua::CVector2 GetTextSize();

	/*!
	 *  @brief �e�L�X�g�̍��W
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