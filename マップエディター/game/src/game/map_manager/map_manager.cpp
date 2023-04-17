#include "map_manager.h"
#include <string.h>

CMapManager::CMapManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "MapManager")
{
}

void CMapManager::Initialize()
{
}

void CMapManager::Update()
{
	GetDragFilePath(buffer);

	if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
	{
		if (s.GetResourceHandle() != -1)
			s.Delete();

		s.Create(buffer);
	}
}

void CMapManager::Draw()
{
	if (s.GetResourceHandle() != -1)
	{
		s.Draw();
	}
}

void CMapManager::Finalize()
{
	if (s.GetResourceHandle() != -1)
		s.Delete();
}
