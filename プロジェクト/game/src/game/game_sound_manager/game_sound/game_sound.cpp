#include "game_sound.h"

CGameSound::CGameSound(aqua::IGameObject parent)
	:aqua::IGameObject(parent)
{
}


void CGameSound::Initialize(Sound_ID id, std::string name, bool loop_flag)
{
	m_ID = id;
	m_Sound.Create(name, loop_flag);
}

void CGameSound::Finalize()
{
	m_Sound.Delete();
}

Sound_ID CGameSound::GetSoundID()
{
	return m_ID;
}

void CGameSound::Play()
{
	m_Sound.Play();
}

void CGameSound::Stop()
{
	m_Sound.Stop();
}

bool CGameSound::IsPlaying()
{
	return m_Sound.IsPlaying();
}
