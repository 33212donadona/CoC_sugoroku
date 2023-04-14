#include "title.h"

const std::string CTitle::scene_name = "Title";
const Scene::ID   CTitle::m_next_scene = Scene::ID::SELECT;

// コンストラクタ
CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

void CTitle::Initialize()
{
	m_LeftBilldingSprite.Create("data\\title\\back_ground\\タイトル_ビル1.png");
	m_RightBilldingSprite.Create("data\\title\\back_ground\\タイトル_ビル2.png");
	m_GroundSprite.Create("data\\title\\back_ground\\タイトル_地面.png");
	m_GroundLineSprite.Create("data\\title\\back_ground\\タイトル_地面_ライン.png");
	m_LabelSprite.Create("data\\title\\back_ground\\タイトル_リボン.png");

}

// 更新
void CTitle::Update()
{
	IScene::Update();
}

// 描画
void CTitle::Draw()
{
	m_LeftBilldingSprite.Draw();
	m_RightBilldingSprite.Draw();
	m_GroundSprite.Draw();
	m_GroundLineSprite.Draw();
	m_LabelSprite.Draw();

	IScene::Draw();
}

// 解放
void CTitle::Finalize()
{
	m_LeftBilldingSprite.Delete();
	m_RightBilldingSprite.Delete();
	m_GroundSprite.Delete();
	m_GroundLineSprite.Delete();
	m_LabelSprite.Delete();

	IScene::Finalize();
}
