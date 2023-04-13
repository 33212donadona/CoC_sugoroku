#pragma once
#include "../scene.h"
class CResult :
	public IScene
{
public:

	/*!
	*  @brief �R���X�g���N�g
	*/
	CResult(aqua::IGameObject* parent);

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

	static const std::string scene_name;      //! �V�[���̖��O
	static const Scene::ID   m_next_scene;    //! ���̃V�[����ID
};

