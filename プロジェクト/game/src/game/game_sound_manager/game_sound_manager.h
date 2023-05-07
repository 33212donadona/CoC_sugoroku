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
	*  @brief ������
	*/
	void Initialize()override;

	/*
	*  @brief �X�V
	*/
	void Update()override;

	/*
	*  @brief ���
	*/
	void Finalize()override;

	/*
	*  @brief BGM���Đ�
	* 
	*  @param[in] id  �V�[��ID
	*/
	void PlayBGM(Sound_ID id);

	/*
	*  @brief SE���Đ�
	* 
	*  @param[in] id�@SE��ID
	*/
	void PlaySE(Sound_ID id);

private:

	/*
	*  @brief  ���y�̓ǂݍ���
	*/
	void LoadSound(const std::string& file_name,SoundVector& vector,bool loop = true);

private:

	static const std::string m_bgm_list_file;
	static const std::string m_se_list_file;

	SoundVector m_SoundBGM;
	SoundVector m_SoundSE;

	Sound_ID          m_PlayingSceneID;          // �Đ�����BGM��ID

};