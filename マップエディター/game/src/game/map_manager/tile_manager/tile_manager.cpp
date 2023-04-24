#include "tile_manager.h"
#include "tile/normal_tile/normal_tile.h"
#include "tile/ivent_tile/ivent_tile.h"
#include <filesystem>

namespace fs = std::filesystem;

CTileManager::CTileManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "TileManager")

{

}

void CTileManager::Initialize()
{
	CreateTile(TILE_ID::NORMAL, aqua::CVector2::ONE * 500);
}

void CTileManager::Update()
{

	for (auto& it : m_TileList)
	{

		

	}

	IGameObject::Update();
}

void CTileManager::Draw()
{
	IGameObject::Draw();
}

void CTileManager::Finalize()
{
	SaveTile();

	IGameObject::Finalize();
}

void CTileManager::CreateTile(TILE_ID tile_id, aqua::CVector2 position)
{

	ITile* tile_object = nullptr;

	switch (tile_id)
	{
	case TILE_ID::NORMAL:
		tile_object = aqua::CreateGameObject<CNormalTile>(this);
		break;
	case TILE_ID::IVENT:
		tile_object = aqua::CreateGameObject<CIventTile>(this);
		break;
	}

	if (tile_object)
	{
		tile_object->Initialize(position);

		m_TileList.push_back(tile_object);
	}
}

void CTileManager::SaveTile()
{
	m_TileDataText.open("map_data\\tile_data.txt", std::ios::out);

	int count_tiles = 0;
	
	WritingTextCollEnd("tile_info");

	for (auto& i : m_TileList)
	{
		// ‘‚«ž‚Ý
		WritingText(std::to_string(i->GetNowTileID()));

		//WritingText(i->GetGameObjectName());

		WritingText(std::to_string(i->GetPosition().x));
		WritingText(std::to_string(i->GetPosition().y));
		WritingText(std::to_string(i->GetPosition().x));

		int max = i->GetMaxNextTileSize();

		for (int wt_i = 0; wt_i < max; wt_i++)
			WritingText(std::to_string(i->GetNextTile(wt_i)));

		WritingTextCollEnd();
		
		count_tiles++;
	}

	m_TileDataText.close();
}

void CTileManager::WritingText(std::string w)
{
	m_TileDataText << w << ",";
}

void CTileManager::WritingTextCollEnd(std::string w)
{
	m_TileDataText << w << ",\n";

}
