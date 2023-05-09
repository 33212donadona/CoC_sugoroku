#include "game_main.h"
#include "../../../stage_manager/stage_manager.h"
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

	m_StageManager->CreateStage(0);
}

// �X�V
void CGameMain::Update()
{
	m_StageManager->Update();
	IScene::Update();
}

// �`��
void CGameMain::Draw()
{
	m_StageManager->Draw();
	IScene::Draw();
}

// ���
void CGameMain::Finalize()
{
	m_StageManager->Finalize();
	IScene::Finalize();
}
