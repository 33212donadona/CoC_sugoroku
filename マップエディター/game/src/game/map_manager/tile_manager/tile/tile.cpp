#include "tile.h"
int ITile::m_tile_num = 0;

ITile::ITile(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"Block")
{
	m_tile_num++; // 0à»è„ÇÃêîíl
	m_NowID = m_tile_num;
}

void ITile::Initialize(aqua::CVector2 position)
{
	Initialize("data\\block\\normal_block.png", position);
}

void ITile::Initialize(std::string block_name, aqua::CVector2 position)
{

	m_TileSprite.Create(block_name);
	m_TileSprite.position = position;

	m_TileSize.x = m_TileSprite.GetTextureWidth();
	m_TileSize.y = m_TileSprite.GetTextureHeight();
}

void ITile::Update()
{
}

void ITile::Draw()
{
	m_TileSprite.Draw();
}

void ITile::Finalize()
{
	m_TileSprite.Delete();
}

void ITile::SetPosition(aqua::CVector2& position)
{
	m_TileSprite.position = position;
}

aqua::CVector2 ITile::GetPosition()
{
	return m_TileSprite.position;
}

int ITile::GetNowTileID()
{
	return m_NowID;
}

void ITile::SetNextTileNumber(int tile_number)
{
	if (tile_number < 0) return;

	m_NextTileNumber.push_back(tile_number);
}

int ITile::GetMaxNextTileSize()
{
	return (int)m_NextTileNumber.size();
}

int ITile::GetNextTile(int next_tile_number)
{
	if (next_tile_number < 0 && next_tile_number >= GetMaxNextTileSize())return NULL;

	return m_NextTileNumber[next_tile_number];
}

bool ITile::CheckOnTile(aqua::CVector2& position) // TODO
{
	return false;
}
