#pragma once
#include "aqua.h"

class CTurn
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief コンストラクタ
	*/
	CTurn(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CTurn() = default;

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

	aqua::CSprite m_BackGround;

};