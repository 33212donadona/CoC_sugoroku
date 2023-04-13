#pragma once
#include "../scene.h"
class CResult :
	public IScene
{
public:

	/*!
	*  @brief コンストラクト
	*/
	CResult(aqua::IGameObject* parent);

	/*!
	*  @brief 更新
	*/
	void Update()override;

	/*!
	*  @brief 描画
	*/
	void Draw()override;

	/*!
	*  @brief 解放
	*/
	void Finalize()override;
private:

	static const std::string scene_name;      //! シーンの名前
	static const Scene::ID   m_next_scene;    //! 次のシーンのID
};

