#pragma once
#include "aqua.h"
#include "scene_enum.h"
class IScene : 
	public aqua::IGameObject
{
public:

	/*!
	* @brief �R���X�g���N�g
	*/
	IScene(aqua::IGameObject* parent,std::string name);

	/*!
	* @brief �f�X�g���N�g
	*/
	virtual ~IScene() = default;
	
	/*!
	* @brief �X�V
	*/
	virtual void Update()override;

	/*!
	* @brief �`��
	*/
	virtual void Draw()override;

	/*!
	* @brief ���
	*/
	virtual void Finalize()override;

	/*!
	* @brief �؂�ւ��t���O�̎擾
	* 
	* @return �؂�ւ��t���O
	*/
	bool CheckChangeFlag();

	/*!
	* @brief ���̃V�[���̎擾
	* 
	* @return ���̃V�[��
	*/
	Scene::ID GetNextScene();

protected:

	Scene::ID m_NextSceneID;         //! ���̃V�[��ID

	aqua::CLabel m_SceneName;        //! �V�[����

private:

	bool ChangeFlag;                 //! �؂�ւ��t���O

};

