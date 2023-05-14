#pragma once
#include "aqua.h"
#include "charactor_id.h"

class CCharactor
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CCharactor(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CCharactor() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize();

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