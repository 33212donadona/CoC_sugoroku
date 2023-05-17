#include "select.h"
#include "../../../select_charactor/select_characor.h"
const std::string CSelect::scene_name = "Select";
const SceneID   CSelect::m_next_scene = SceneID::GAME;

/*
 *  ������
 */
CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
{
}

/*
 *  ������ 
 */
void CSelect::Initialize()
{
	aqua::CreateGameObject<CSelectCharactor>(this);

	IGameObject::Initialize();
}

/*
 *  ������
 */
void CSelect::Update()
{
	IScene::Update();
}

/*
 *  ������
 */
void CSelect::Draw()
{
	IScene::Draw();
}

/*
 *  ������
 */
void CSelect::Finalize()
{
	IScene::Finalize();
}
