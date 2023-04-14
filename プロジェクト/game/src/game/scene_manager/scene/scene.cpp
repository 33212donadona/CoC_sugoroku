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

// 更新
void IScene::Update()
{
	ChangeFlag = aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT);
}

// 描画
void IScene::Draw()
{
#ifdef  AQUA_DEBUG
	m_SceneName.Draw();
#endif
}

// 解放
void IScene::Finalize()
{
	m_SceneName.Delete();
	DeleteObject();
}

// 切り替えフラグの取得
bool IScene::CheckChangeFlag()
{
	return ChangeFlag;
}

// 次のシーンの取得
Scene::ID IScene::GetNextScene()
{
	return m_NextSceneID;
}
