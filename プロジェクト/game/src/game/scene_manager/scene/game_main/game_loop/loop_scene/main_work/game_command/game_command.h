#pragma once
#include "aqua.h"

enum class CommandID
{
	DICE,
	TEAM,

	MAX
};

class CGameCommand
	:public aqua::IGameObject
{
public:

	/*!
	 *  @brief �R���X�g���N�^
	 */
	CGameCommand(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CGameCommand() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize(aqua::CVector2 position);

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

private:

	/*
	 *  @brief �R�}���h��I�� 
	 */
	void SelectCommand();

	/*
	 *  @brief �T�C�R���̃R�}���h 
	 */
	void DiceCommand();

	/*
	 *  @brief �`�[����g�ރR�}���h 
	 */
	void TeamCommand();

private:
	static const std::string m_CommandName[(int)CommandID::MAX];
	static const int m_rand_pattern;
	static const int m_max_dice;
	static const int m_rand_dice[2][6];
	static const float m_change_dice_time;

	std::vector<aqua::CLabel> m_CommandLabel;
	
	aqua::CSprite             m_DiceSprite[6];                   //! �T�C�R����ʂ��̉摜
	std::vector<aqua::CSprite*> m_DrawDiceSprite;

	aqua::CTimer  m_ChangeDiceTimer;

	CommandID    m_NowSelectCommand;

	bool m_UpdateCommand;

};
