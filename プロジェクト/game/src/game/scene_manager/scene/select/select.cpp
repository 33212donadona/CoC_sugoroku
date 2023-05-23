#include "select.h"
#include "../../../select_charactor/select_characor.h"
const std::string CSelect::scene_name = "Select";
const SceneID   CSelect::m_next_scene = SceneID::GAME;

/*
 *  ������
 */
CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
	, m_SelectChara(nullptr)
{
}

/*
 *  ������ 
 */
void CSelect::Initialize()
{
	m_SelectChara = (CSelectCharactor*)aqua::CreateGameObject<CSelectCharactor>(this);

	IGameObject::Initialize();
}

/*
 *  ������
 */
void CSelect::Update()
{
	if (m_SelectChara)
		m_ChangeFlag = m_SelectChara->GetFinishedFlag();

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
