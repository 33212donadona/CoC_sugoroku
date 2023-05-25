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

	std::vector<aqua::CLabel> m_CommandLabel;

	CommandID    m_NowSelectCommand;

};
