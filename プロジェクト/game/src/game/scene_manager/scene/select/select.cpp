#include "select.h"

const std::string CSelect::scene_name = "Select";

CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, scene_name)
{
	m_NextSceneID = Scene::ID::GAME;
	m_SceneName.text = scene_name;
}

void CSelect::Update()
{
	IScene::Update();
}

void CSelect::Draw()
{
	IScene::Draw();
}

void CSelect::Finalize()
{
	IScene::Finalize();
}
