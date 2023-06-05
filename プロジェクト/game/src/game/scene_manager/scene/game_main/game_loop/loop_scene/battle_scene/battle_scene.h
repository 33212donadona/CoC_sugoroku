#pragma once
#include "aqua.h"


class CBattleScene
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief コンストラクタ
	*/
	CBattleScene(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CBattleScene() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize(std::string back_ground_name);

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

	aqua::CSprite m_BackGround;

};