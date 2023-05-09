#include "result.h"
const std::string CResult::scene_name = "Result";
const SceneID CResult::m_next_scene = SceneID::TITLE;

// コンストラクタ
CResult::CResult(aqua::IGameObject* parent)
	:IScene(parent,scene_name, m_next_scene)
{
}

/*
 *  初期化 
 */
void CResult::Initialize()
{
}

// 更新
void CResult::Update()
{
	IScene::Update();
}

// 描画
void CResult::Draw()
{
	IScene::Draw();
}

// 解放
void CResult::Finalize()
{
	IScene::Finalize();
}
