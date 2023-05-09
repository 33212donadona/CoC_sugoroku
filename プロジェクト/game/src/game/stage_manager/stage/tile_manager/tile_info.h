#pragma once
#include "aqua.h"

struct TileInfo
{
	int id = 0;
	aqua::CVector2 position;
	std::string tile_name = "";
	std::list<int> m_FromID;
};