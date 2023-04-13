#pragma once
#include "aqua.h"
#include "scene/scene.h"

class CSceneManager :
	public aqua::IGameObject
{
public:

	/*!
	*  @brief �R���X�g���N�^
	*/
	CSceneManager(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CSceneManager() = default;

	/*!
	*  @brief ������
	*/
	void Initialize()override;

	/*!
	*  @brief �X�V
	*/
	void Update()override;

private:

	/*!
	*  @brief �V�[���̐؂�ւ�
	*/
	void ChageScene(Scene::ID scene_id);

private:

	IScene* m_Scene;           //! �V�[���̊��N���X
	Scene::ID m_NectID;		   //! ���̃V�[��ID
};

