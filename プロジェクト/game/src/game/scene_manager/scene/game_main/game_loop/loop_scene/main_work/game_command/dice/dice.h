#pragma once
#include "aqua.h"


const int m_rand_pattern = 4;
const int m_max_dice = 6;

class CDice
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CDice(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CDice() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize();

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

	/*!
	 *  @brief �o���T�C�R���̖ڂ��擾 
	 */
	int GetDice();

private:

	/*
	 *  @brief �T�C�R���̏��Ԃ��Đݒu
	 */
	void SetUpDice();

private:
	static const int m_aftertaste_max_count;
	static const int m_rand_dice[4][6];
	static const float m_change_dice_time;
	static const float m_add_dice_time;
	static const float m_emphasis_dice_time;
	static const float m_emphasis_dice_max_size;
	static const float m_emphasis_dice_min_size;

	aqua::CSprite             m_DiceSprite[6];                   //! �T�C�R����ʂ��̉摜
	std::vector<aqua::CSprite*> m_DrawDiceSprite;

	aqua::CBoxPrimitive       m_BackGround;

	aqua::CTimer  m_ChangeDiceTimer;
	aqua::CTimer  m_EmphasisDiceTimer;     // �o���o�ڂ̋���

	bool m_ReturnDice;

	int  m_DiceNumber;
	int  m_DiceAftertasteCount;
};