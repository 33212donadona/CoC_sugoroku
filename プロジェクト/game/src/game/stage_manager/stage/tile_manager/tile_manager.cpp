#include "tile_manager.h"
#include "tile/normal_tile/normal_tile.h"
#include "tile/ivent_tile/ivent_tile.h"
#include <filesystem>

namespace fs = std::filesystem;

CTileManager::CTileManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "TileManager")
	,m_LineFlag(false)
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
		AQUA_SAFE_DELETE(it);
	}
}

/*
 * �^�C������
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
 * �^�C�����Ȃ���
 */
void CTileManager::TileLine()
{
	if (m_LineFlag)return;
	m_LineFlag = true;



}
