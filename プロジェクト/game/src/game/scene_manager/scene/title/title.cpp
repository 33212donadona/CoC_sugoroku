#include "title.h"

const std::string CTitle::scene_name = "Title";
const Scene::ID   CTitle::m_next_scene = Scene::ID::SELECT;

// �R���X�g���N�^
CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

// �X�V
void CTitle::Update()
{
	IScene::Update();
}

// �`��
void CTitle::Draw()
{
	IScene::Draw();
}

// ���
void CTitle::Finalize()
{
	IScene::Finalize();
}
