#include "game_main.h"

const std::string CGameMain::scene_name = "Game";

CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent, scene_name)
{
	m_NextSceneID = Scene::ID::RESULT;
	m_SceneName.text = scene_name;
}

void CGameMain::Update()
{
	IScene::Update();
}

void CGameMain::Draw()
{
	IScene::Draw();
}

void CGameMain::Finalize()
{
	IScene::Finalize();
}
