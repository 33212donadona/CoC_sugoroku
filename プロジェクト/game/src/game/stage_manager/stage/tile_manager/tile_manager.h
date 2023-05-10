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

private:

	/*
	 * @brief �^�C�����Ȃ���
	 * 
	 */
	void TileLine();

private:

	std::list<ITile*>        m_TileList;   //!  �^�C�����X�g

	bool                     m_LineFlag;   //!  �������������ǂ���

};