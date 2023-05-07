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

// �X�V
void IScene::Update()
{
	ChangeFlag = aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT);
}

// �`��
void IScene::Draw()
{
#ifdef  AQUA_DEBUG
	m_SceneName.Draw();
#endif
}

// ���
void IScene::Finalize()
{
	m_SceneName.Delete();
	AQUA_SAFE_DELETE_ARRAY(m_GameSoundManager);
}

// �؂�ւ��t���O�̎擾
bool IScene::CheckChangeFlag()
{
	return ChangeFlag;
}

// ���̃V�[���̎擾
SceneID IScene::GetNextScene()
{
	return m_NextSceneID;
}

/*!
*  �V�[���ɍ��������yID���擾
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
