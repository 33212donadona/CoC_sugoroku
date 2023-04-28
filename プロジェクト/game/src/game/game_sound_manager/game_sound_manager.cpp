#include "game_sound_manager.h"

const std::string CGameSoundManager::m_SoundListFile = "data\\sound\\sound_list.csv";

CGameSoundManager::CGameSoundManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GameSoundManager")
{
}

void CGameSoundManager::Initialize()
{
	aqua::CCSVLoader loader;
	loader.Load(m_SoundListFile);

	int row = loader.GetRows();

	for (int i = 0; i <= row; i++)
	{
		std::pair<Scene::ID, std::string> s;
		s.first = (Scene::ID)loader.GetInteger(i, 0);
		s.second = loader.GetString(i, 1);

	}
}

void CGameSoundManager::Update()
{
}

void CGameSoundManager::Finalize()
{
}
