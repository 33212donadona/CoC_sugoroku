#pragma once
#include "../tile.h"

class CIventTile :
	public ITile
{
public:

	CIventTile(aqua::IGameObject* parent);
	~CIventTile() = default;

	/*!
	 *   @brief  初期化
	 *
	 *   @param[in] position 座標
	 */
	void Initialize(TileInfo* info)override;

	void Update()override;
	void Draw()override;
	void Finalize()override;

	/*
	 *  @brief タイル名を取得
	 */
	static std::string GetTileName() { return m_tile_name; };

private:

	static const std::string m_tile_name;

};