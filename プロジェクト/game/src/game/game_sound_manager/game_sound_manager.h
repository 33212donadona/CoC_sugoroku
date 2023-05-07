#pragma once
#include "aqua.h"
#include "game_sound//game_sound.h"

using SoundVector = std::vector<CGameSound*>;

class CGameSoundManager : 
	public aqua::IGameObject
{
public:
	CGameSoundManager(aqua::IGameObject* parent);
	~CGameSoundManager() = default;

	/*
	*  @brief 初期化
	*/
	void Initialize()override;

	/*
	*  @brief 更新
	*/
	void Update()override;

	/*
	*  @brief 解放
	*/
	void Finalize()override;

	/*
	*  @brief BGMを再生
	* 
	*  @param[in] id  シーンID
	*/
	void PlayBGM(Sound_ID id);

	/*
	*  @brief SEを再生
	* 
	*  @param[in] id　SEのID
	*/
	void PlaySE(Sound_ID id);

private:

	/*
	*  @brief  音楽の読み込み
	*/
	void LoadSound(const std::string& file_name,SoundVector& vector,bool loop = true);

private:

	static const std::string m_bgm_list_file;
	static const std::string m_se_list_file;

	SoundVector m_SoundBGM;
	SoundVector m_SoundSE;

	Sound_ID          m_PlayingSceneID;          // 再生中のBGMのID

};