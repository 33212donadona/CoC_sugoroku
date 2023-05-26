#pragma once
#include "aqua.h"

struct TileInfo
{
	int id = 0;                 //! 自分のID
	aqua::CVector2 position;	//! 座標
	std::string tile_name = "";	//! 名前
	std::vector<int> m_FromID;	//! 行先のID
};