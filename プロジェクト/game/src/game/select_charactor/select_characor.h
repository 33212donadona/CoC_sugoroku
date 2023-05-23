#pragma once
#include "aqua.h"
#include "charactor/charactor_id.h"

class CCharactorInfo;
class CCommonData;
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

	/*!
	*   @brief �I���I���t���O�̎擾
	*/
	bool GetFinishedFlag();

private:

	void SelectCharactor();

	void DecideCharactor();

private:

	static const float          m_box_thickness;                     //  �{�b�N�X�̐��̑���
	static const unsigned int   m_box_color[(int)PLAYER_ID::DUMMY];  //  �{�b�N�X�̐��̐F
												        
	std::vector<CCharactorInfo*> m_Charactor;                        //�@�L�����N�^�[���X�g

	std::vector<CParameter*>     m_Parameter;                        //�@�p�����[�^�[���X�g
	std::vector<aqua::CSprite>   m_CharactorSpriteList;              //  �L�����N�^�[�摜���X�g

	aqua::CSprite              m_BackgroudSprite;                    //  �w�i

	aqua::CBoxPrimitive        m_SelectBox;                          //  �I�𒆂̘g
	aqua::CBoxPrimitive        m_SelectBlendBox;                     //  �I�𒆂̔�
	aqua::CBoxPrimitive        m_SelectParamBox;                     //  �p�����[�^���̐F

	PLAYER_ID                  m_NowSelectPlayer;                    //  ���삵�Ă���v���C���[

	CCommonData*               m_CommonDataClass;                    //  ���L�f�[�^�N���X
	
	int                        m_CharactorMaxNum;                    //  

	int                        m_SelectCharactor;

	bool                       m_FinishedSelect;
};