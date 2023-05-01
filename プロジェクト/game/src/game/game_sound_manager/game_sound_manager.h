#pragma once
#include "aqua.h"
#include "sound_id.h"
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

private:

	/*
	 *  @brief BGM�̓ǂݍ��� 
	 */
	void LoadBGM();

	/*
	 *  @brief SE�̓ǂݍ���
	 */
	void LoadSE();

private:

	static const std::string m_bgm_list_file;
	static const std::string m_se_list_file;

	std::vector<std::pair<Scene::ID,aqua::CSoundPlayer*>> m_SoundBGM;
	std::vector<std::pair<Scene::ID,aqua::CSoundPlayer*>> m_SoundSE;



};