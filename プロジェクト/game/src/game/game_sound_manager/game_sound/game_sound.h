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
	*  @brief 初期化
	*/
	void Initialize(Sound_ID id,std::string name,bool loop_flag);

	/*
	*  @brief 解放
	*/
	void Finalize()override;

	/*
	*  @brief 音楽IDを取得
	*/
	Sound_ID GetSoundID();

	/*
	*  @brief 再生
	*/
	void Play();

	/*
	*  @brief 停止
	*/
	void Stop();

	/*
	*  @brief 停止
	*/
	bool IsPlaying();


private:

	Sound_ID m_ID;                //! 音楽ID
	aqua::CSoundPlayer m_Sound;   //! 音楽

};