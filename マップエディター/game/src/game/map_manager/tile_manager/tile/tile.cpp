#include "tile.h"

int ITile::m_tile_num = -1;                //! �����̃^�C���ԍ� �T���v���Ƃ���2�������Ă����̂�-1�������l�Ƃ���

const float ITile::m_out_of_range = 10;   //! �Փ˔���̋��e�͈�

ITile::ITile(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"Block")
{
	m_NowID = m_tile_num;
	m_tile_num++; // 0�ȏ�̐��l
}

/*!
 *   @brief  ������
 */
void ITile::Initialize(aqua::CVector2 position)
{
	Initialize("data\\block\\normal_block.png", position);
}

/*!
 *   @brief  ������
 */
void ITile::Initialize(std::string block_name, aqua::CVector2 position)
{

	m_TileSprite.Create(block_name);
	m_TileSprite.position = position;

	m_TileHalfSize.x = m_TileSprite.GetTextureWidth()  / 2.0f;
	m_TileHalfSize.y = m_TileSprite.GetTextureHeight() / 2.0f;

	m_CenterPosition = m_TileSprite.position + m_TileHalfSize;
}

/*!
 *   @brief  �X�V
 */
void ITile::Update()
{
}

/*!
 *   @brief  �`��
 */
void ITile::Draw()
{
	m_TileSprite.Draw();
}

/*!
 *   @brief  ���
 */
void ITile::Finalize()
{
	m_TileSprite.Delete();
}

/*!
 *   @brief  �^�C�����W�̉���
 */
void ITile::SetPosition(aqua::CVector2& position)
{
	m_TileSprite.position = position - m_TileHalfSize;
	m_CenterPosition = position;

}

/*!
 *   @brief  �^�C�����W�̎擾
 */
aqua::CVector2 ITile::GetPosition()
{
	return m_TileSprite.position;
}

/*!
 *   @brief  �^�C�����W�̎擾
 */
aqua::CVector2* ITile::GetCenterPosition()
{
	return &m_CenterPosition;
}

/*!
 *   @brief  �i�߂�^�C���ԍ���ݒ�
 */
void ITile::SetNextTileID(int vector_num, int next_tile_number)
{
	if (next_tile_number < 0) return;

	int max = (int)m_NextTileNumber.size();

	if (max > vector_num)
	{
		m_NextTileNumber[vector_num] = next_tile_number;
	}
	else
	{
		m_NextTileNumber.push_back(next_tile_number);
	}
}
/*! 
 *   �^�C���ԍ����Đݒ�
 */
void ITile::SetTileID(int tile_number)
{
	if (tile_number <= 0 || m_NowID == tile_number)return;

	m_NowID = tile_number;
}

/*!
 *   @brief  �����̃^�C���ԍ����擾
 */
int ITile::GetNowTileID()
{
	return m_NowID;
}

/*!
 *   @brief  ������
 */
int ITile::GetMaxNextTileSize()
{
	return (int)m_NextTileNumber.size();
}

/*!
 *   @brief  �i�߂�^�C���̍ő�l���擾
 */
int ITile::GetNextTileID(int vector_num)
{
	if (vector_num < 0 && vector_num >= GetMaxNextTileSize())return NULL;

	return m_NextTileNumber[vector_num];
}

/*!
 *   @brief  �����Ƃ̏Փ˔���
 */
bool ITile::CheckOnTile(aqua::CVector2& position)
{
	aqua::CVector2 distance = m_CenterPosition - position;
	distance.x = abs(distance.x);
	distance.y = abs(distance.y);
	float dis_float = sqrt(distance.x * distance.x + distance.y * distance.y);

	return dis_float <= m_TileHalfSize.x + m_out_of_range;
}

aqua::CVector2 ITile::GetTileSize()
{
	return m_TileHalfSize * 2.0f;
}
