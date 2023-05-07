#include "game_main.h"

const std::string CGameMain::scene_name = "Game";
const SceneID CGameMain::m_next_scene= SceneID::RESULT;

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
