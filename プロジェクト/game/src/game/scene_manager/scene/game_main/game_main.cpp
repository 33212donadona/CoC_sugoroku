#include "game_main.h"
#include "../../../stage_manager/stage_manager.h"
const std::string CGameMain::scene_name = "Game";
const SceneID CGameMain::m_next_scene= SceneID::RESULT;

// コンストラクタ
CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

/*
 *  初期化 
 */
void CGameMain::Initialize()
{
	m_StageManager = aqua::CreateGameObject<CStageManager>(this);

	m_StageManager->CreateStage(0);
}

// 更新
void CGameMain::Update()
{
	m_StageManager->Update();
	IScene::Update();
}

// 描画
void CGameMain::Draw()
{
	m_StageManager->Draw();
	IScene::Draw();
}

// 解放
void CGameMain::Finalize()
{
	m_StageManager->Finalize();
	IScene::Finalize();
}
