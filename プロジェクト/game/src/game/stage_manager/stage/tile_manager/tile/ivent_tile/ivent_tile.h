#pragma once
#include "../tile.h"

class CIventTile :
	public ITile
{
public:

	CIventTile(aqua::IGameObject* parent);
	~CIventTile() = default;

	void Initialize(aqua::CVector2 position)override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

	/*
	 *  @brief ƒ^ƒCƒ‹–¼‚ðŽæ“¾
	 */
	static std::string GetTileName() { return m_tile_name; };

private:

	static const std::string m_tile_name;

};