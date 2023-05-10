#include "normal_tile.h"

const std::string CNormalTile::m_tile_name = "NormalTile";

CNormalTile::CNormalTile(aqua::IGameObject* parent)
	:ITile(parent, m_tile_name)
{
}

void CNormalTile::Initialize(TileInfo* info)
{
	ITile::Initialize("data\\tile\\normal_tile.png", info);
}

void CNormalTile::Update()
{
	ITile::Update();
}

void CNormalTile::Draw()
{
	ITile::Draw();
}

void CNormalTile::Finalize()
{
	ITile::Finalize();
}
