#include "game_main.h"

const std::string CGameMain::scene_name = "Game";
const Scene::ID CGameMain::m_next_scene= Scene::ID::RESULT;

// �R���X�g���N�^
CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

// �X�V
void CGameMain::Update()
{
	IScene::Update();
}

// �`��
void CGameMain::Draw()
{
	IScene::Draw();
}

// ���
void CGameMain::Finalize()
{
	IScene::Finalize();
}
