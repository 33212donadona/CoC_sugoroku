#pragma once
#include "aqua.h"
#include "scene/scene.h"

class CSceneManager :
	public aqua::IGameObject
{
public:

	CSceneManager(aqua::IGameObject* parent);
	~CSceneManager() = default;

	/*!
	*  @brief 初期化
	*/
	void Initialize()override;

	/*!
	*  @brief 更新
	*/
	void Update()override;

private:

	/*!
	*  @brief シーンの切り替え
	*/
	void ChageScene(Scene::ID scene_id);

private:

	IScene* m_Scene;           //! シーンの基底クラス
	Scene::ID m_NectID;		   //! 次のシーンID
};

