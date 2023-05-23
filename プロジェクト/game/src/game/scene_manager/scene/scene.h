#pragma once
#include "aqua.h"
#include "scene_id.h"
#include "../../game_sound_manager/sound_id.h"

class CGameSoundManager;

class IScene : 
	public aqua::IGameObject
{
public:

	/*
	*  @brief コンストラクト
	*/
	IScene(aqua::IGameObject* parent,std::string name,SceneID next_scene);

	/*
	*  @brief デストラクト
	*/
	virtual ~IScene() = default;
	
	/*
	*  @brief 更新
	*/
	virtual void Update()override;

	/*
	*  @brief 描画
	*/
	virtual void Draw()override;

	/*
	*  @brief 解放
	*/
	virtual void Finalize()override;

	/*
	*  @brief 切り替えフラグの取得
	* 
	*  @retval     true    切り替える
    *  @retval     false   切り替えない
	*/
	bool CheckChangeFlag();

	/*
	*  @brief 次のシーンの取得
	* 
	*  @return 次のシーン
	*/
	SceneID GetNextScene();

protected:

	bool m_ChangeFlag;                 //! 切り替えフラグ

private:

	/*
	*   @brief シーンに合った音楽IDを取得
	* 
	*   @return 音楽ID
	*/
	Sound_ID SceneSoundID(std::string& name);

private:
	SceneID m_NextSceneID;           //! 次のシーンID

	aqua::CLabel m_SceneName;        //! シーン名

	

	CGameSoundManager* m_GameSoundManager; //! 音楽管理クラス
};

