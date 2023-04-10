#include "title.h"

const std::string CTitle::scene_name = "Title";

CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, scene_name)
{
	m_NextSceneID = Scene::ID::GAME;
	m_SceneName.text = scene_name;
}

void CTitle::Update()
{
}

void CTitle::Draw()
{
	IScene::Draw();
}

void CTitle::Finalize()
{
	IScene::Finalize();
}
