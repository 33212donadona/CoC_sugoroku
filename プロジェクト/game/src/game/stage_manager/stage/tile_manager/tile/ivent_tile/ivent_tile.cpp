#include "ivent_tile.h"

const std::string CIventTile::m_tile_name = "IventTile";

CIventTile::CIventTile(aqua::IGameObject* parent)
	:ITile(parent, m_tile_name)
{
}

void CIventTile::Initialize(aqua::CVector2 position)
{
	ITile::Initialize("data\\tile\\ivent_tile.png", position);
}

void CIventTile::Update()
{
	ITile::Update();
}

void CIventTile::Draw()
{
	ITile::Draw();
}

void CIventTile::Finalize()
{
	ITile::Finalize();
}