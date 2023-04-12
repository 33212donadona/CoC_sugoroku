#include "scene_manager.h"
#include "scene_channel.h"

CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SceneManager")
	, m_Scene(nullptr)
	, m_NectID(Scene::ID::TITLE)
{
}

// 初期化
void CSceneManager::Initialize()
{
	ChageScene(m_NectID);
}

// 更新
void CSceneManager::Update()
{
	// シーンの切り替え
	if (m_Scene->CheckChangeFlag())
	{
		m_NectID = m_Scene->GetNextScene();

		// シーンの終了処理
		m_Scene->Finalize();
		m_Scene = nullptr;
			
		// シーンの切り替え
		ChageScene(m_NectID);
	}
	
	IGameObject::Update();
}

// シーン切り替え
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
