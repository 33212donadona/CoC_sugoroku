#pragma once
#include "aqua.h"

enum class PLAYER_ID;
struct STATUS;

class CCommonData;
class CCharactorInfo;

class CMainGameWork
	:public aqua::IGameObject
{
public:
	/*!
	*  @brief �R���X�g���N�^
	*/
	CMainGameWork(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CMainGameWork() = default;

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

	/*
	 *  @brief  
	 */

private:
	
	static const aqua::CPoint m_text_box_space;//! �L�����N�^�[�A�C�R���̍��W
	static const int          m_font_size;              //! �L�����N�^�[�A�C�R���̍��W

	CCommonData*              m_CommonData;             //! ���L�f�[�^�N���X
	STATUS*                   m_Status;

	aqua::CLabel              m_LabelHP	;               //! HP���x��
	aqua::CLabel              m_LabelSTR;               //! STR���x��
	aqua::CLabel              m_LabelDEX;               //! DEX���x��

	aqua::CSprite             m_TextBoxSprite;	        //! �e�L�X�g�{�b�N�X�摜

	PLAYER_ID                 m_NowPlayerID;		    //! ���쒆�̃v���C���[ID
};