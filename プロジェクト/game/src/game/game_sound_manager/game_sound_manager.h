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

private:

	/*
	 *  @brief BGMの読み込み 
	 */
	void LoadBGM();

	/*
	 *  @brief SEの読み込み
	 */
	void LoadSE();

private:

	static const std::string m_bgm_list_file;
	static const std::string m_se_list_file;

	std::vector<std::pair<Scene::ID,aqua::CSoundPlayer*>> m_SoundBGM;
	std::vector<std::pair<Scene::ID,aqua::CSoundPlayer*>> m_SoundSE;



};