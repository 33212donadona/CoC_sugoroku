#include "game_sound_manager.h"

const std::string CGameSoundManager::m_bgm_list_file = "data\\sound\\sound_bgm_list.csv";
const std::string CGameSoundManager::m_se_list_file = "data\\sound\\sound_se_list.csv";

CGameSoundManager::CGameSoundManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GameSoundManager")
{
}

/*
*  初期化
*/
void CGameSoundManager::Initialize()
{
	LoadBGM();

	LoadSE();
}

/*
 *  更新 
 */
void CGameSoundManager::Update()
{
}

/*
*  解放
*/
void CGameSoundManager::Finalize()
{
}

/*
*   BGMの読み込み 
*/
void CGameSoundManager::LoadBGM()
{
	aqua::CCSVLoader loader;
	loader.Load(m_bgm_list_file);

	int row = loader.GetRows();

	for (int i = 0; i <= row; i++)
	{
		std::pair<Scene::ID, aqua::CSoundPlayer*> s;

		s.first = (Scene::ID)loader.GetInteger(i, 0);
		s.second->Create(loader.GetString(i, 2), true);

		m_SoundBGM.push_back(s);
	}

	loader.Unload();
}

/*
 *  SEの読み込み
 */
void CGameSoundManager::LoadSE()
{
	aqua::CCSVLoader loader;
	loader.Load(m_se_list_file);

	int row = loader.GetRows();

	for (int i = 0; i <= row; i++)
	{
		std::pair<Scene::ID, aqua::CSoundPlayer*> s;

		s.first = (Scene::ID)loader.GetInteger(i, 0);
		s.second->Create(loader.GetString(i, 2), false);

		m_SoundSE.push_back(s);
	}

	loader.Unload();
}
