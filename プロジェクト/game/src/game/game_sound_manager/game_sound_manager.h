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
	*  @brief ‰Šú‰»
	*/
	void Initialize()override;

	/*
	*  @brief XV
	*/
	void Update()override;

	/*
	*  @brief ‰ğ•ú
	*/
	void Finalize()override;

private:

	/*
	 *  @brief BGM‚Ì“Ç‚İ‚İ 
	 */
	void LoadBGM();

	/*
	 *  @brief SE‚Ì“Ç‚İ‚İ
	 */
	void LoadSE();

private:

	static const std::string m_bgm_list_file;
	static const std::string m_se_list_file;

	std::vector<std::pair<Scene::ID,aqua::CSoundPlayer*>> m_SoundBGM;
	std::vector<std::pair<Scene::ID,aqua::CSoundPlayer*>> m_SoundSE;



};