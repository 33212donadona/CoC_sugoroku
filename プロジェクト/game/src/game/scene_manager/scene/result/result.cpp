#include "result.h"

const std::string CResult::scene_name = "Result";
const SceneID CResult::m_next_scene = SceneID::TITLE;

// �R���X�g���N�^
CResult::CResult(aqua::IGameObject* parent)
	:IScene(parent,scene_name, m_next_scene)
{
}

/*
 *  ������ 
 */
void CResult::Initialize()
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
