#pragma once
#include "aqua.h"
#include "scene_enum.h"
class IScene : 
	public aqua::IGameObject
{
public:

	/*!
	* @brief コンストラクト
	*/
	IScene(aqua::IGameObject* parent,std::string name);

	/*!
	* @brief デストラクト
	*/
	virtual ~IScene() = default;
	
	/*!
	* @brief 更新
	*/
	virtual void Update()override;

	/*!
	* @brief 描画
	*/
	virtual void Draw()override;

	/*!
	* @brief 解放
	*/
	virtual void Finalize()override;

	/*!
	* @brief 切り替えフラグの取得
	* 
	* @return 切り替えフラグ
	*/
	bool CheckChangeFlag();

	/*!
	* @brief 次のシーンの取得
	* 
	* @return 次のシーン
	*/
	Scene::ID GetNextScene();

protected:

	Scene::ID m_NextSceneID;         //! 次のシーンID

	aqua::CLabel m_SceneName;        //! シーン名

private:

	bool ChangeFlag;                 //! 切り替えフラグ

};

