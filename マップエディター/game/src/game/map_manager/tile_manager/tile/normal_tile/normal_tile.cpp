#include "normal_tile.h"

CNormalTile::CNormalTile(aqua::IGameObject* parent)
	:ITile(parent,"NormalBlock")
{
}

void CNormalTile::Initialize(aqua::CVector2 position)
{
	ITile::Initialize("data\\block\\normal_block.png", position);
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
