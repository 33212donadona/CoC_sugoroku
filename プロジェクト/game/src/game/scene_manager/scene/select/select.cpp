#include "select.h"

const std::string CSelect::scene_name = "Select";
const Scene::ID   CSelect::m_next_scene = Scene::ID::GAME;

// �R���X�g���N�^
CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

// �X�V
void CSelect::Update()
{
	IScene::Update();
}

// �`��
void CSelect::Draw()
{
	IScene::Draw();
}

// ���
void CSelect::Finalize()
{
	IScene::Finalize();
}
