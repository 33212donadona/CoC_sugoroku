#pragma once
#include "../tile.h"

class CNormalTile :
	public ITile
{
public:

	CNormalTile(aqua::IGameObject* parent);
	~CNormalTile() = default;

	/*!
	 *   @brief  ‰Šú‰»
	 *
	 *   @param[in] position À•W
	 */
	void Initialize(TileInfo* info)override;

	void Update()override;
	void Draw()override;
	void Finalize()override;

	/*
	 *  @brief ƒ^ƒCƒ‹–¼‚ğæ“¾
	 */
	static std::string GetTileName() { return m_tile_name; };

private:

	static const std::string m_tile_name;

};