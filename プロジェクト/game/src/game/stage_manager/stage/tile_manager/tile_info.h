#pragma once
#include "aqua.h"

struct TileInfo
{
	int id = 0;                 //! ������ID
	aqua::CVector2 position;	//! ���W
	std::string tile_name = "";	//! ���O
	std::vector<int> m_FromID;	//! �s���ID
};