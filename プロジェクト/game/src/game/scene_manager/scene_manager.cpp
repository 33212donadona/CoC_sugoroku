#include "scene_manager.h"
#include "scene_channel.h"

CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SceneManager")
	, m_Scene(nullptr)
	, m_NectID(Scene::ID::TITLE)
{
}

// ������
void CSceneManager::Initialize()
{
	ChageScene(m_NectID);
}

// �X�V
void CSceneManager::Update()
{
	// �V�[���̐؂�ւ�
	if (m_Scene->CheckChangeFlag())
	{
		m_NectID = m_Scene->GetNextScene();

		// �V�[���̏I������
		m_Scene->Finalize();
		m_Scene = nullptr;
			
		// �V�[���̐؂�ւ�
		ChageScene(m_NectID);
	}
	
	IGameObject::Update();
}

// �V�[���؂�ւ�
void CSceneManager::ChageScene(Scene::ID scene_id)
{
	if (scene_id == Scene::ID::DUMMY)return;

	switch (scene_id)
	{
	case Scene::ID::TITLE:
		m_Scene = (IScene*)aqua::CreateGameObject<CTitle>(this);
		break;
	case Scene::ID::SELECT:
		m_Scene = (IScene*)aqua::CreateGameObject<CSelect>(this);
		break;
	case Scene::ID::GAME:
		m_Scene = (IScene*)aqua::CreateGameObject<CGameMain>(this);
		break;
	case Scene::ID::RESULT:
		m_Scene = (IScene*)aqua::CreateGameObject<CResult>(this);
		break;
	}
}
