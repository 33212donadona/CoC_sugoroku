#pragma once
#include "aqua.h"

class CCharactorInfo;

class CSelectCharactor
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CSelectCharactor(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CSelectCharactor() = default;

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

private:

	void SelectCharactor();

private:
	static const float          m_box_thickness;  //  �{�b�N�X�̐��̑���
	static const unsigned int   m_box_color;      //  �{�b�N�X�̐��̑���

	std::vector<CCharactorInfo*> m_Charactor;     //�@�L�����N�^�[���X�g

	aqua::CSprite              m_BackgroudSprite; //  �w�i

	aqua::CBoxPrimitive        m_SelectBox;       //  �I�𒆂̘g
	aqua::CBoxPrimitive        m_SelectBlendBox;  //  �I�𒆂̔�

	PLAYER_ID                  m_NowSelectPlayer; //  ���삵�Ă���v���C���[
	
	int                        m_CharactorMaxNum;

	int                        m_SelectCharactor;
};