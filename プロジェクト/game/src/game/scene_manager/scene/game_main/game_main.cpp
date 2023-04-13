#include "game_main.h"

const std::string CGameMain::scene_name = "Game";
const Scene::ID CGameMain::m_next_scene= Scene::ID::RESULT;

// コンストラクタ
CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

// 更新
void CGameMain::Update()
{
	IScene::Update();
}

// 描画
void CGameMain::Draw()
{
	IScene::Draw();
}

// 解放
void CGameMain::Finalize()
{
	IScene::Finalize();
}
