#include "select.h"
#include "../../../select_charactor/select_characor.h"
const std::string CSelect::scene_name = "Select";
const SceneID   CSelect::m_next_scene = SceneID::GAME;

/*
 *  ‰Šú‰»
 */
CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
	, m_SelectChara(nullptr)
{
}

/*
 *  ‰Šú‰» 
 */
void CSelect::Initialize()
{
	m_SelectChara = (CSelectCharactor*)aqua::CreateGameObject<CSelectCharactor>(this);

	IGameObject::Initialize();
}

/*
 *  ‰Šú‰»
 */
void CSelect::Update()
{
	if (m_SelectChara)
		m_ChangeFlag = m_SelectChara->GetFinishedFlag();

	IScene::Update();
}

/*
 *  ‰Šú‰»
 */
void CSelect::Draw()
{
	IScene::Draw();
}

/*
 *  ‰Šú‰»
 */
void CSelect::Finalize()
{
	IScene::Finalize();
}
