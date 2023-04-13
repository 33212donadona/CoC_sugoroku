#include "title.h"

const std::string CTitle::scene_name = "Title";
const Scene::ID   CTitle::m_next_scene = Scene::ID::SELECT;

// コンストラクタ
CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

// 更新
void CTitle::Update()
{
	IScene::Update();
}

// 描画
void CTitle::Draw()
{
	IScene::Draw();
}

// 解放
void CTitle::Finalize()
{
	IScene::Finalize();
}
