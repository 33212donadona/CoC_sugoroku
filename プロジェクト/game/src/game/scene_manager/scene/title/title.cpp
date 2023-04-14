#include "title.h"

const std::string CTitle::scene_name = "Title";
const Scene::ID   CTitle::m_next_scene = Scene::ID::SELECT;

// �R���X�g���N�^
CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

void CTitle::Initialize()
{
	m_LeftBilldingSprite.Create("data\\title\\back_ground\\�^�C�g��_�r��1.png");
	m_RightBilldingSprite.Create("data\\title\\back_ground\\�^�C�g��_�r��2.png");
	m_GroundSprite.Create("data\\title\\back_ground\\�^�C�g��_�n��.png");
	m_GroundLineSprite.Create("data\\title\\back_ground\\�^�C�g��_�n��_���C��.png");
	m_LabelSprite.Create("data\\title\\back_ground\\�^�C�g��_���{��.png");

}

// �X�V
void CTitle::Update()
{
	IScene::Update();
}

// �`��
void CTitle::Draw()
{
	m_LeftBilldingSprite.Draw();
	m_RightBilldingSprite.Draw();
	m_GroundSprite.Draw();
	m_GroundLineSprite.Draw();
	m_LabelSprite.Draw();

	IScene::Draw();
}

// ���
void CTitle::Finalize()
{
	m_LeftBilldingSprite.Delete();
	m_RightBilldingSprite.Delete();
	m_GroundSprite.Delete();
	m_GroundLineSprite.Delete();
	m_LabelSprite.Delete();

	IScene::Finalize();
}
