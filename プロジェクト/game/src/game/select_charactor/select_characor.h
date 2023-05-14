#pragma once
#include "aqua.h"

class CSelectCharactor
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CSelectCharactor(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CSelectCharactor() = default;

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