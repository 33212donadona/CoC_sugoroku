#include "ivent_tile.h"

CIventTile::CIventTile(aqua::IGameObject* parent)
	:ITile(parent,"IventTile")
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
