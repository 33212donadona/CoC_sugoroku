#include "game_sound_manager.h"

const std::string CGameSoundManager::m_bgm_list_file = "data\\sound\\sound_bgm_list.csv";
const std::string CGameSoundManager::m_se_list_file = "data\\sound\\sound_se_list.csv";

/*
*  �R���X�g���N�g
*/
CGameSoundManager::CGameSoundManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GameSoundManager")
	, m_PlayingSceneID(Sound_ID::DUMMY)
{
}

/*
*  ������
*/
void CGameSoundManager::Initialize()
{
	LoadSound(m_bgm_list_file,m_SoundBGM,true);

	LoadSound(m_se_list_file, m_SoundSE,false);
}

/*
 *  �X�V 
 */
void CGameSoundManager::Update()
{
	for (auto& bgm_iterotar : m_SoundBGM)
	{
		if (bgm_iterotar->IsPlaying())break;

		if (bgm_iterotar->GetSoundID() == m_PlayingSceneID)
		{
			bgm_iterotar->Play();
			m_PlayingSceneID = Sound_ID::DUMMY;
		}
	}
}

/*
*  ���
*/
void CGameSoundManager::Finalize()
{
	for (auto& bgm_iterotar : m_SoundBGM)
	{
		bgm_iterotar->Finalize();
	}

	for (auto& se_iterator : m_SoundSE)
	{
		se_iterator->Finalize();
	}
}

/*
*  BGM���Đ�
*/
void CGameSoundManager::PlayBGM(Sound_ID id)
{
	if ((int)id >= (int)Sound_ID::DUMMY)return;

	if (m_PlayingSceneID != Sound_ID::DUMMY)
		m_SoundBGM[(int)m_PlayingSceneID]->Stop();

	m_PlayingSceneID = id;
}

/*
*   SE���Đ�
*/
void CGameSoundManager::PlaySE(Sound_ID id)
{
	if ((int)id <= (int)Sound_ID::DUMMY && id == Sound_ID::MAX)return;

	for (auto& se_iterator : m_SoundSE)
	{
		if (se_iterator->GetSoundID() == id)
			se_iterator->Play();
	}

}

/*
*  ���y�̓ǂݍ���
*/
void CGameSoundManager::LoadSound(const std::string& file_name,SoundVector& vector, bool loop)
{
	aqua::CCSVLoader loader;
	loader.Load(file_name);

	int se_add = (int)Sound_ID::DUMMY * !loop;

	int row = loader.GetRows();

	for (int i = 0; i <= row; i++)
	{
		CGameSound* s;

		s->Initialize(Sound_ID(loader.GetInteger(i, 0) + se_add), loader.GetString(i, 2), loop);

		vector.push_back(s);
	}

	loader.Unload();
}
