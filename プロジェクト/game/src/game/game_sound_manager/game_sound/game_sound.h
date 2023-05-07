#pragma once
#include "aqua.h"
#include "../sound_id.h"

class CGameSound
	:public aqua::IGameObject
{
public:

	CGameSound(aqua::IGameObject parent);
	~CGameSound() = default;

	/*
	*  @brief ‰Šú‰»
	*/
	void Initialize(Sound_ID id,std::string name,bool loop_flag);

	/*
	*  @brief ‰ğ•ú
	*/
	void Finalize()override;

	/*
	*  @brief ‰¹ŠyID‚ğæ“¾
	*/
	Sound_ID GetSoundID();

	/*
	*  @brief Ä¶
	*/
	void Play();

	/*
	*  @brief ’â~
	*/
	void Stop();

	/*
	*  @brief ’â~
	*/
	bool IsPlaying();


private:

	Sound_ID m_ID;                //! ‰¹ŠyID
	aqua::CSoundPlayer m_Sound;   //! ‰¹Šy

};