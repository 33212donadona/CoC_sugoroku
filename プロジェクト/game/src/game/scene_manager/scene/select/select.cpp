#include "select.h"

const std::string CSelect::scene_name = "Select";
const SceneID   CSelect::m_next_scene = SceneID::GAME;

// コンストラクタ
CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

// 更新
void CSelect::Update()
{
	IScene::Update();
}

// 描画
void CSelect::Draw()
{
	IScene::Draw();
}

// 解放
void CSelect::Finalize()
{
	IScene::Finalize();
}
