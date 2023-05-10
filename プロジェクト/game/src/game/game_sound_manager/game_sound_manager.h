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
	void LoadSound(const std::string& file_name, SoundInfo** info,SoundVector* vector,bool loop = true);

	/*
	 *  @brief ���y�̉��
	 */
	void DeleteSound(SoundInfo** info, SoundVector* vector);
private:

	static const std::string m_bgm_list_file;
	static const std::string m_se_list_file;

	SoundVector m_SoundBGM;
	SoundVector m_SoundSE;

	SoundInfo*  m_InfoBGM;
	SoundInfo*  m_InfoSE;

	Sound_ID          m_PlayingSceneID;          // �Đ�����BGM��ID

};