#pragma once
#include "aqua.h"
#include "tile_manager/tile_manager.h"

class CStage
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CStage(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CStage() = default;

	/*!
	 *  @brief 初期化
	 */
	bool Initialize(std::string file_name);

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

	aqua::CSprite m_BackGoundSprite;

	CTileManager* m_TileManager;

	TileInfo*     m_TileData;
};