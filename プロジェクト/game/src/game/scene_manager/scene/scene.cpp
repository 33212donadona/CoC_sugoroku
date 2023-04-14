#include "scene.h"

IScene::IScene(aqua::IGameObject* parent, std::string name, Scene::ID next_scene)
	:aqua::IGameObject(parent, name, "IScene")
	, m_NextSceneID(Scene::ID::DUMMY)
	, ChangeFlag(false)
{
	m_SceneName.Create(40);
	m_SceneName.text = name;
	m_NextSceneID = next_scene;
}

// �X�V
void IScene::Update()
{
	ChangeFlag = aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT);
}

// �`��
void IScene::Draw()
{
#ifdef  AQUA_DEBUG
	m_SceneName.Draw();
#endif
}

// ���
void IScene::Finalize()
{
	m_SceneName.Delete();
	DeleteObject();
}

// �؂�ւ��t���O�̎擾
bool IScene::CheckChangeFlag()
{
	return ChangeFlag;
}

// ���̃V�[���̎擾
Scene::ID IScene::GetNextScene()
{
	return m_NextSceneID;
}
