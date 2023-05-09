#pragma once
#include "aqua.h"

class CStage;

class CStageManager
	: public aqua::IGameObject
{
public:
	/*!
	*  @brief �R���X�g���N�^
	*/
	CStageManager(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CStageManager() = default;

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
	*  @brief �X�e�[�W�𐶐�
	*/
	void CreateStage(int stage_id);
private:

	/*
	*   @brief ���݂���t�@�C���̌������߂�
	*/
	void CountExistsFile();

private:

	static const std::string m_tile_data;     //! �^�C�����̋��ʂ����t�@�C����
										      
	CStage*                  m_Stage;         //! �X�e�[�W�N���X

	int                      m_ExistsFileNum; //! ���݂���t�@�C���̐�

	int                      m_SelectFile;    //! �I�������t�@�C��
};