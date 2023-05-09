#include "select.h"

const std::string CSelect::scene_name = "Select";
const SceneID   CSelect::m_next_scene = SceneID::GAME;

/*
 *  初期化
 */
CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

/*
 *  初期化 
 */
void CSelect::Initialize()
{
}

/*
 *  初期化
 */
void CSelect::Update()
{
	IScene::Update();
}

/*
 *  初期化
 */
void CSelect::Draw()
{
	IScene::Draw();
}

/*
 *  初期化
 */
void CSelect::Finalize()
{
	IScene::Finalize();
}
