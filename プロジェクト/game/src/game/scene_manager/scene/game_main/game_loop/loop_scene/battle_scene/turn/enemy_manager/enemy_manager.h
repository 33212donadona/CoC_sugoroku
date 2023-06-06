#pragma once
#include "aqua.h"
#include "../../../../../../../../select_charactor/charactor/charactor_id.h"

class CEnemyManager
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief コンストラクタ
	*/
	CEnemyManager(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CEnemyManager() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize(std::string enemy_file);

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

	std::vector<std::pair<aqua::CSprite*,STATUS*>> m_EnemyVector;

};