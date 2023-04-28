#include "map_manager.h"
#include "back_ground_manager/back_ground_manager.h"
#include "save_manager/save_manager.h"
#include "tile_manager/tile_manager.h"

CMapManager::CMapManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "MapManager")
{
}

void CMapManager::Initialize()
{
	aqua::CreateGameObject<CBackGroundManager>(this);
	aqua::CreateGameObject<CTileManager>(this);
	aqua::CreateGameObject<CSaveManager>(this);
	aqua::IGameObject::Initialize();

}

void CMapManager::Update()
{
	aqua::IGameObject::Update();
	
}

void CMapManager::Draw()
{
	aqua::IGameObject::Draw();

}

void CMapManager::Finalize()
{
	aqua::IGameObject::Finalize();
}