#include "tile_manager.h"
#include "tile/normal_tile/normal_tile.h"
#include "tile/ivent_tile/ivent_tile.h"
#include "line/line.h"
#include <filesystem>

namespace fs = std::filesystem;

CTileManager::CTileManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "TileManager")
	, m_LineFlag(false)
{
}

/*
 * 更新
 */
void CTileManager::Update()
{
	for (auto& it : m_TileList)
	{
		it->Update();
	}
}

/*
 * 描画
 */
void CTileManager::Draw()
{

	for (auto& it : m_LineList)
	{
		it->Draw();
	}

	for (auto& it : m_TileList)
	{
		it->Draw();
	}

	CLine::ArrowDraw();
}

/*
 * 解放
 */
void CTileManager::Finalize()
{
	for (auto& it : m_TileList)
	{
		it->Finalize();
		AQUA_SAFE_DELETE(it);
	}
}

/*
 * タイル生成
 */
void CTileManager::CreateTile(TileInfo* info)
{
	ITile* tile_object = nullptr;

	if ((*info).tile_name == CNormalTile::GetTileName())
		tile_object = (ITile*)aqua::CreateGameObject<CNormalTile>(this);
	else
		tile_object = (ITile*)aqua::CreateGameObject<CIventTile>(this);

	if (tile_object)
	{
		tile_object->Initialize(info);

		m_TileList.push_back(tile_object);
	}
}

/*
 * タイルをつなげる
 */
void CTileManager::CreateTileLine()
{
	for (auto& tile_it : m_TileList)
	{
		int from_size = tile_it->GetMaxFromTileSize();

		for (int i = 0; i < from_size; ++i)
		{
			int from_id = (*tile_it->GetFromTileID(i));

			if (from_id != 0) // タイルIDが0なら処理しない
			{
				for (auto& from_it : m_TileList)
				{
					if (from_id == *from_it->GetMyTileID())
					{
						tile_it->SetFromTileID(i, from_it);

						CLine* line = aqua::CreateGameObject<CLine>(this);
						
						line->Initialize(tile_it->GetCenterPosition(),from_it->GetCenterPosition());

						m_LineList.push_back(line);

						break;
					}
				}
			}
		}

	}
}
