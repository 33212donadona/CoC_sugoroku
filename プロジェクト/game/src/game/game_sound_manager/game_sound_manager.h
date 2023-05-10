#pragma once
#include "aqua.h"
#include "sound_id.h"

using SoundInfo = std::pair<Sound_ID, aqua::CSoundPlayer>;
using SoundVector = std::vector<SoundInfo*>;

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
	void LoadSound(const std::string& file_name, SoundInfo** info,SoundVector* vector,bool loop = true);

	/*
	 *  @brief 音楽の解放
	 */
	void DeleteSound(SoundInfo** info, SoundVector* vector);
private:

	static const std::string m_bgm_list_file;
	static const std::string m_se_list_file;

	SoundVector m_SoundBGM;
	SoundVector m_SoundSE;

	SoundInfo*  m_InfoBGM;
	SoundInfo*  m_InfoSE;

	Sound_ID          m_PlayingSceneID;          // 再生中のBGMのID

};