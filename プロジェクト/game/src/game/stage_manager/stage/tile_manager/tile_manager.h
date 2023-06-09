#pragma once
#include "aqua.h"
#include "tile/tile.h"
#include "line/line.h"
#include <fstream>
#include "tile_info.h"

enum class TILE_ID
{
	NORMAL,
	IVENT,

	MAX
};

class CLine;

class CTileManager :
	public aqua::IGameObject
{
public:

	CTileManager(aqua::IGameObject* parent);
	~CTileManager() = default;

	/*
	 * @brief �X�V
	 */
	void Update()override;

	/*
	 * @brief �`��
	 */
	void Draw()override;

	/*
	 * @brief ���
	 */
	void Finalize()override;

	/*
	 * @brief �^�C������
	 */
	void CreateTile(TileInfo* info);

	/*
	 * @brief �^�C�����Ȃ���
	 * 
	 */
	void CreateTileLine();

	/*
	 * @brief �^�C���̍��W�擾
	 */
	aqua::CVector2* GetTilePosition(int tile_id);

	/*
	 *  @brief ���ɐi�߂�^�C����ID 
	 */
	std::vector<int>* GetNextTileID(int tile_id); 

	/*
	 *  @brief ���ɐi�߂�^�C����ID 
	 */
	int GetTileSize(); 

	/*
	 *  @brief ���̕\���̔��]
	 */
	void LineVisible(int tile_id,int from_id);

private:

	std::vector<ITile*>               m_TileList;   //!  �^�C�����X�g

	std::list<CLine*>                 m_LineList;   //!  ���N���X���X�g

	bool                              m_LineFlag;   //!  �������������ǂ���

};