#include "scene.h"
#include "../../game_sound_manager/game_sound_manager.h"

IScene::IScene(aqua::IGameObject* parent, std::string name, SceneID next_scene)
	:aqua::IGameObject(parent, name, "IScene")
	, m_NextSceneID(SceneID::DUMMY)
	, ChangeFlag(false)
{
	m_SceneName.Create(40);
	m_SceneName.text = name;
	m_NextSceneID = next_scene;

	m_GameSoundManager = (CGameSoundManager*)aqua::FindGameObject("GameSoundManager");

	if(m_GameSoundManager)
		m_GameSoundManager->PlayBGM(SceneSoundID(name));

}

// 更新
void IScene::Update()
{
	ChangeFlag = aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT);
}

// 描画
void IScene::Draw()
{
#ifdef  AQUA_DEBUG
	m_SceneName.Draw();
#endif
}

// 解放
void IScene::Finalize()
{
	m_SceneName.Delete();
	AQUA_SAFE_DELETE_ARRAY(m_GameSoundManager);
}

// 切り替えフラグの取得
bool IScene::CheckChangeFlag()
{
	return ChangeFlag;
}

// 次のシーンの取得
SceneID IScene::GetNextScene()
{
	return m_NextSceneID;
}

/*!
*  シーンに合った音楽IDを取得
*/
Sound_ID IScene::SceneSoundID(std::string& name)
{
	Sound_ID id = Sound_ID::DUMMY;

	if (name == "Title")
		id = Sound_ID::TITLE;

	if (name == "Select")
		id = Sound_ID::SELECT;

	if (name == "Game")
		id = Sound_ID::GAME;

	if (name == "Result")
		id = Sound_ID::RESULT;

	return id;
}
