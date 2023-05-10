#pragma once
#include "../tile.h"

class CNormalTile :
	public ITile
{
public:

	CNormalTile(aqua::IGameObject* parent);
	~CNormalTile() = default;

	/*!
	 *   @brief  ������
	 *
	 *   @param[in] position ���W
	 */
	void Initialize(TileInfo* info)override;

	void Update()override;
	void Draw()override;
	void Finalize()override;

	/*
	 *  @brief �^�C�������擾
	 */
	static std::string GetTileName() { return m_tile_name; };

private:

	static const std::string m_tile_name;

};