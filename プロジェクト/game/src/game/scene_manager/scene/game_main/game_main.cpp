#include "game_main.h"
#include "../../../stage_manager/stage_manager.h"
#include "game_loop/game_loop.h"

const std::string CGameMain::scene_name = "Game";
const SceneID CGameMain::m_next_scene= SceneID::RESULT;

// �R���X�g���N�^
CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

/*
 *  ������ 
 */
void CGameMain::Initialize()
{
	m_StageManager = aqua::CreateGameObject<CStageManager>(this);
	m_GameLoop = aqua::CreateGameObject<CGameLoop>(this);

	m_StageManager->CreateStage(0);
	m_GameLoop->Initialize();

}

// �X�V
void CGameMain::Update()
{
	m_StageManager->Update();
	m_GameLoop->Update();
	IScene::Update();
}

// �`��
void CGameMain::Draw()
{
	m_StageManager->Draw();
	m_GameLoop->Draw();
	IScene::Draw();
}

// ���
void CGameMain::Finalize()
{
	m_StageManager->Finalize();
	m_GameLoop->Finalize();
	IScene::Finalize();
}
