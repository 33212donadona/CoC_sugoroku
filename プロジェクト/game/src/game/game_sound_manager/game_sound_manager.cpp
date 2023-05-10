#include "game_sound_manager.h"

const std::string CGameSoundManager::m_bgm_list_file = "data\\sound\\sound_bgm_list.csv";
const std::string CGameSoundManager::m_se_list_file = "data\\sound\\sound_se_list.csv";

/*
 *  コンストラクト
 */
CGameSoundManager::CGameSoundManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GameSoundManager")
	, m_PlayingSceneID(Sound_ID::DUMMY)
{
}

/*
 *  初期化
 */
void CGameSoundManager::Initialize()
{
	LoadSound(m_bgm_list_file,&m_InfoBGM, &m_SoundBGM, true);

	LoadSound(m_se_list_file,&m_InfoSE, &m_SoundSE, false);
}

/*
 *  更新
 */
void CGameSoundManager::Update()
{
	for (auto& bgm_iterotar : m_SoundBGM)
	{
		if ((*bgm_iterotar).second.IsPlaying())break;

		if ((*bgm_iterotar).first == m_PlayingSceneID)
		{
			(*bgm_iterotar).second.Play();
			m_PlayingSceneID = Sound_ID::DUMMY;
		}
	}
}

/*
 *  解放
 */
void CGameSoundManager::Finalize()
{
	DeleteSound(&m_InfoBGM, &m_SoundBGM);
	DeleteSound(&m_InfoSE, &m_SoundSE);
}

/*
 *  BGMを再生
 */
void CGameSoundManager::PlayBGM(Sound_ID id)
{
	if ((int)id >= (int)Sound_ID::DUMMY)return;

	for (auto& se_iterator : m_SoundBGM)
	{
		if ((*se_iterator).second.IsPlaying())
			(*se_iterator).second.Stop();
	}

	m_PlayingSceneID = id;
}

/*
 *   SEを再生
 */
void CGameSoundManager::PlaySE(Sound_ID id)
{
	if ((int)id <= (int)Sound_ID::DUMMY && id == Sound_ID::MAX)return;

	for (auto& se_iterator : m_SoundSE)
	{
		if ((*se_iterator).first == id)
			(*se_iterator).second.Play();
	}

}

/*
 *  音楽の読み込み
 */
void CGameSoundManager::LoadSound(const std::string& file_name, SoundInfo** info, SoundVector* vector, bool loop)
{
	aqua::CCSVLoader loader;
	loader.Load(file_name);

	int se_add = (int)Sound_ID::DUMMY * !loop;

	int row = loader.GetRows();

	(*info) = AQUA_NEW SoundInfo[row];

	for (int i = 0; i < row; i++)
	{
		(*info)[i].first = Sound_ID(loader.GetInteger(i, 0) + se_add);
		(*info)[i].second.Create(loader.GetString(i, 2), loop);

		(*vector).push_back(&(*info)[i]);
	}

	loader.Unload();
}

void CGameSoundManager::DeleteSound(SoundInfo** info, SoundVector* vector)
{
	for (auto& iterotar : (*vector))
	{
		(*iterotar).second.Delete();
		iterotar = nullptr;
	}
	AQUA_SAFE_DELETE_ARRAY((*info));
	(*vector).clear();
}
