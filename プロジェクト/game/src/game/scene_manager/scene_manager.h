#pragma once
#include "aqua.h"
#include "scene/scene.h"

class CSceneManager :
	public aqua::IGameObject
{
public:

	/*!
	*  @brief コンストラクタ
	*/
	CSceneManager(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CSceneManager() = default;

	/*!
	*  @brief 初期化
	*/
	void Initialize()override;

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

	/*!
	*  @brief シーンの切り替え
	*/
	void ChageScene( SceneID scene_id);

private:

	/*!
	 *  @brief      状態ID
	 */
	enum class STATE
	{
		SCENE_IN,
		SCENE_UPDATA,
		SCENE_OUT,
		SCENE_CHANGE,
	};

	/*!
	 *  @brief      色ID 
	 */
	enum class COLOR
	{
		BLACK,
		GREEN,
		BLUE,
		YELLOW,
		CYAN,
		MAGENT,

		MAX
	};

	static const unsigned int m_fade_color[(int)COLOR::MAX]; //! フェードの色
	static const float        m_fade_time;                   //! フェードの最大時間
	static const float        m_max_alpha;                   //! 透過度の最大
	static const float        m_min_alpha;                   //! 透過度の最小
											                 
	IScene* m_Scene;                                         //! シーンの基底クラス
											                 
	SceneID m_NextID;		                                 //! 次のシーンID
	STATE   m_SceneState;                                    //! シーンの状態
											                 
	aqua::CBoxPrimitive m_FadeBox;                           //! 画面フェード
	aqua::CTimer        m_FadeTime;                          //! フェードの時間

};