#pragma once
#include "aqua.h"

class CGameLoop
	:public aqua::IGameObject
{
public:
	/*!
	*  @brief コンストラクタ
	*/
	CGameLoop(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CGameLoop() = default;

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

};