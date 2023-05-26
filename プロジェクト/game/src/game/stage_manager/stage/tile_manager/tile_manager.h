#pragma once
#include "aqua.h"
#include "tile/tile.h"
#include "line/line.h"
#include <fstream>
#include "tile_info.h"

enum class TILE_ID
{
	NORMAL,
	IVENT,

	MAX
};

class CLine;

class CTileManager :
	public aqua::IGameObject
{
public:

	CTileManager(aqua::IGameObject* parent);
	~CTileManager() = default;

	/*
	 * @brief 更新
	 */
	void Update()override;

	/*
	 * @brief 描画
	 */
	void Draw()override;

	/*
	 * @brief 解放
	 */
	void Finalize()override;

	/*
	 * @brief タイル生成
	 */
	void CreateTile(TileInfo* info);

	/*
	 * @brief タイルをつなげる
	 * 
	 */
	void CreateTileLine();

private:

	std::list<ITile*>        m_TileList;   //!  タイルリスト

	std::list<CLine*>        m_LineList;   //!  道クラスリスト

	bool                     m_LineFlag;   //!  線を引いたかどうか

};