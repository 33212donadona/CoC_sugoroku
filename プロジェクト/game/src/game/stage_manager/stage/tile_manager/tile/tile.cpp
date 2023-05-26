#include "tile.h"

int ITile::m_tile_num = -1;                //! 自分のタイル番号 サンプルとして2つ生成しておくので-1を初期値とする

const float ITile::m_out_of_range = 10;   //! 衝突判定の許容範囲

ITile::ITile(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"Block")
{
	m_NowID = m_tile_num;
	m_tile_num++; // 0以上の数値
}

/*!
 *   @brief  初期化
 */
void ITile::Initialize(TileInfo* info)
{
	Initialize("data\\block\\normal_block.png", info);
}

/*!
 *   @brief  初期化
 */
void ITile::Initialize(std::string block_name, TileInfo* info)
{
	m_TileInfo = info;

	m_TileSprite.Create(block_name);
	m_TileSprite.position = (*info).position;

	m_NowID = (*info).id;

	m_TileHalfSize.x = m_TileSprite.GetTextureWidth()  / 2.0f;
	m_TileHalfSize.y = m_TileSprite.GetTextureHeight() / 2.0f;

	m_CenterPosition = m_TileSprite.position + m_TileHalfSize;
}

/*!
 *   @brief  更新
 */
void ITile::Update()
{
}

/*!
 *   @brief  描画
 */
void ITile::Draw()
{
	m_TileSprite.Draw();
}

/*!
 *   @brief  解放
 */
void ITile::Finalize()
{
	m_TileSprite.Delete();
}

/*!
 *   @brief  タイル座標の加減
 */
void ITile::SetPosition(aqua::CVector2& position)
{
	m_TileSprite.position = position - m_TileHalfSize;
	m_CenterPosition = position;

}

/*!
 *   @brief  タイル座標の取得
 */
aqua::CVector2 ITile::GetPosition()
{
	return m_TileSprite.position;
}

/*!
 *   @brief  タイル座標の取得
 */
aqua::CVector2* ITile::GetCenterPosition()
{
	return &m_CenterPosition;
}

/*!
 *   @brief  進めるタイル番号を設定
 */
void ITile::SetFromTileID(int vector_num,ITile* next_tile)
{
	if (next_tile == nullptr) return;

	int max = (int)m_NextTile.size();

	if (max > vector_num)
	{
		m_NextTile[vector_num] = next_tile;
	}
	else
	{
		m_NextTile.push_back(next_tile);
	}
}

/*! 
 *   タイル番号を再設定
 */
void ITile::SetTileID(int tile_number)
{
	if (tile_number <= 0 || m_NowID == tile_number)return;

	m_NowID = tile_number;
}

/*!
 *  自分のタイル番号を取得
 */
int* ITile::GetMyTileID()
{
	return &m_NowID;
}

/*!
 *  初期化
 */
int ITile::GetMaxFromTileSize()
{
	if (m_TileInfo->m_FromID.empty())return NULL;

	return (int)m_TileInfo->m_FromID.size();
}

/*!
 *  進めるタイルの最大値を取得
 */
int* ITile::GetFromTileID(int vector_num)
{
	if (vector_num < 0 && vector_num >= GetMaxFromTileSize())return NULL;

	return &m_TileInfo->m_FromID[vector_num];
}

/*!
 *  引数との衝突判定
 */
bool ITile::CheckOnTile(aqua::CVector2& position)
{
	aqua::CVector2 distance = m_CenterPosition - position;
	distance.x = abs(distance.x);
	distance.y = abs(distance.y);
	float dis_float = sqrt(distance.x * distance.x + distance.y * distance.y);

	return dis_float <= m_TileHalfSize.x + m_out_of_range;
}

/*!
 *  タイルの大きさ
 */
aqua::CVector2 ITile::GetTileSize()
{
	return m_TileHalfSize * 2.0f;
}