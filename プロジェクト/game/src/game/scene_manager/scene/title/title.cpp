#include "title.h"

const std::string CTitle::scene_name = "Title";

CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, scene_name)
{
	m_NextSceneID = Scene::ID::SELECT;
	m_SceneName.text = scene_name;
}

void CTitle::Update()
{
	IScene::Update();
}

void CTitle::Draw()
{
	IScene::Draw();
}

void CTitle::Finalize()
{
	IScene::Finalize();
}
