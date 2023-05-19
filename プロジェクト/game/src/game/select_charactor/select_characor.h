#pragma once
#include "aqua.h"
#include "charactor/charactor_id.h"

class CCharactorInfo;
class CParameter;

using CHARACTOR_VECTOR = std::vector<CCharactorInfo>;

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
	void Initialize()override;

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

	void DecideCharactor();

private:

	static const float          m_box_thickness;                     //  �{�b�N�X�̐��̑���
	static const unsigned int   m_box_color[(int)PLAYER_ID::DUMMY];  //  �{�b�N�X�̐��̐F
												        
	std::vector<CCharactorInfo*> m_Charactor;                        //�@�L�����N�^�[���X�g
	CHARACTOR_VECTOR             m_SelectChara;                      //  �I�񂾃L�����N�^�[
	std::vector<CParameter*>     m_Parameter;                        //�@�p�����[�^�[���X�g
	std::vector<aqua::CSprite>   m_CharactorSpriteList;              //  �L�����N�^�[�摜���X�g

	aqua::CSprite              m_BackgroudSprite;                    //  �w�i


	aqua::CBoxPrimitive        m_SelectBox;                          //  �I�𒆂̘g
	aqua::CBoxPrimitive        m_SelectBlendBox;                     //  �I�𒆂̔�

	PLAYER_ID                  m_NowSelectPlayer;                    //  ���삵�Ă���v���C���[
	
	int                        m_CharactorMaxNum;

	int                        m_SelectCharactor;
};