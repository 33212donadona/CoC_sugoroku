#include "result.h"
const std::string CResult::scene_name = "Result";

CResult::CResult(aqua::IGameObject* parent)
	:IScene(parent,scene_name)
{
	m_NextSceneID = Scene::ID::TITLE;
	m_SceneName.text = scene_name;
}

void CResult::Update()
{
	IScene::Update();
}

void CResult::Draw()
{
	IScene::Draw();
}

void CResult::Finalize()
{
	IScene::Finalize();
}
