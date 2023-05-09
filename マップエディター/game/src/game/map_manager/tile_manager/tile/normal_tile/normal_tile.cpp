#include "normal_tile.h"

CNormalTile::CNormalTile(aqua::IGameObject* parent)
	:ITile(parent,"NormalTile")
{
}

void CNormalTile::Initialize(aqua::CVector2 position)
{
	ITile::Initialize("data\\tile\\normal_tile.png", position);
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
