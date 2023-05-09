#include "tile_manager.h"
#include "tile/normal_tile/normal_tile.h"
#include "tile/ivent_tile/ivent_tile.h"
#include <filesystem>

namespace fs = std::filesystem;

CTileManager::CTileManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "TileManager")
{
}

/*
 * �X�V
 */
void CTileManager::Update()
{
	for (auto& it : m_TileList)
	{
		it->Update();
	}
}

/*
 * �`��
 */
void CTileManager::Draw()
{
	for (auto& it : m_TileList)
	{
		it->Draw();
	}
	
}

/*
 * ���
 */
void CTileManager::Finalize()
{
	for (auto& it : m_TileList)
	{
		it->Finalize();
	}
}

/*
 * �^�C������
 */
void CTileManager::CreateTile(TileInfo info)
{
	ITile* tile_object = nullptr;

	if(info.tile_name == CNormalTile::GetTileName())
		tile_object = aqua::CreateGameObject<CNormalTile>(this);
	else
		tile_object = aqua::CreateGameObject<CIventTile>(this);

	if (tile_object)
	{
		tile_object->Initialize(info.position);

		tile_object->SetTileID(info.id);

		m_TileList.push_back(tile_object);
	}
}