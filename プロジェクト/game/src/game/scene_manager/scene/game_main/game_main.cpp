#include "game_main.h"
#include "../../../stage_manager/stage_manager.h"
#include "game_loop/game_loop.h"

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
	m_GameLoop = aqua::CreateGameObject<CGameLoop>(this);

	m_StageManager->CreateStage(0);
	m_GameLoop->Initialize();

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
