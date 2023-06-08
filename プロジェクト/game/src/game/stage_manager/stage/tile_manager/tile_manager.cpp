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
	for (auto& line_it : m_LineList)
	{
		line_it->Draw();
	}

	for (auto& tile_it : m_TileList)
	{
		tile_it->Draw();
	}

	CLine::ArrowDraw();
}

/*
 * 解放
 */
void CTileManager::Finalize()
{
	for (auto& tile_it : m_TileList)
	{
		tile_it->Finalize();
		AQUA_SAFE_DELETE(tile_it);
	}

	m_TileList.clear();

	for (auto& line_it : m_LineList)
	{
		line_it->Finalize();
		AQUA_SAFE_DELETE(line_it);
	}

	m_LineList.clear();

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
 * タイルを道でつなげる
 */
void CTileManager::CreateTileLine()
{
	for (auto& tile_it : m_TileList)
	{
		int from_size = tile_it->GetMaxFromTileSize();

		std::vector<int>* from_id_vector = tile_it->GetFromTileID();

		for (int i = 0; i < from_size; ++i)
		{
			int from_id = (*from_id_vector)[i];

			if (from_id != 0) // タイルIDが0なら処理しない
			{
				for (auto& from_it : m_TileList)
				{
					if (from_id == *from_it->GetMyTileID())
					{
						CLine* line;

						tile_it->SetFromTileID(i, from_it);

						line = aqua::CreateGameObject<CLine>(this);
						
						line->Initialize(tile_it->GetCenterPosition(),from_it->GetCenterPosition(), *tile_it->GetMyTileID(),from_id);

						m_LineList.push_back(line);

						break;
					}
				}
			}
		}

	}
}

/*
 * タイルの座標 
 */
aqua::CVector2* CTileManager::GetTilePosition(int tile_id)
{

	if (tile_id < 0 || tile_id >= m_TileList.size())
		return m_TileList[0]->GetCenterPosition();

	return m_TileList[tile_id]->GetCenterPosition();
}

/*
 * タイルの行先の情報
 */
std::vector<int>* CTileManager::GetNextTileID(int tile_id)
{
	int id = tile_id - 1;

	if (id <= 0)id = 0;
	if (id >= (int)m_TileList.size())id = (int)m_TileList.size() - 1;

	return  m_TileList[id]->GetFromTileID();
}

/*
 * タイルリストの大きさ
 */
int CTileManager::GetTileSize()
{
	return (int)m_TileList.size();
}

/*
 * 道の表示フラグを反転
 */
void CTileManager::LineVisible(int tile_id)
{
	for (auto& line_it : m_LineList)
	{
		if (line_it->GetWayTileID(LineWay::TO) == tile_id)
			line_it->visible = !line_it->visible;
	}
}