#pragma once
#include "aqua.h"

struct TileInfo
{
	int id = 0;                 //! ©•ª‚ÌID
	aqua::CVector2 position;	//! À•W
	std::string tile_name = "";	//! –¼‘O
	std::vector<int> m_FromID;	//! sæ‚ÌID
};