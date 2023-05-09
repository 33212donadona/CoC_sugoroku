#pragma once
#include "../tile.h"

class CNormalTile :
	public ITile
{
public:

	CNormalTile(aqua::IGameObject* parent);
	~CNormalTile() = default;

	void Initialize(aqua::CVector2 position)override;
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