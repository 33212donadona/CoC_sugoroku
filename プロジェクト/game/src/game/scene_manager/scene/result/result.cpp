#include "result.h"
const std::string CResult::scene_name = "Result";
const Scene::ID CResult::m_next_scene = Scene::ID::TITLE;

// �R���X�g���N�^
CResult::CResult(aqua::IGameObject* parent)
	:IScene(parent,scene_name, m_next_scene)
{
}

// �X�V
void CResult::Update()
{
	IScene::Update();
}

// �`��
void CResult::Draw()
{
	IScene::Draw();
}

// ���
void CResult::Finalize()
{
	IScene::Finalize();
}
