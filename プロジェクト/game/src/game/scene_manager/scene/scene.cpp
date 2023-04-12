#include "scene.h"

IScene::IScene(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent, name, "IScene")
	, m_NextSceneID(Scene::ID::DUMMY)
	, ChangeFlag(false)
{
	m_SceneName.Create(40);
}

void IScene::Update()
{
	ChangeFlag = aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT);
}

void IScene::Draw()
{
#ifdef  AQUA_DEBUG
	m_SceneName.Draw();
#endif //  _DEBUG
}

void IScene::Finalize()
{
	m_SceneName.Delete();
	DeleteObject();
}

bool IScene::CheckChangeFlag()
{
	return ChangeFlag;
}

Scene::ID IScene::GetNextScene()
{
	return m_NextSceneID;
}
