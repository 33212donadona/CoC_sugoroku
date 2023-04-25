#pragma once
#include "aqua.h"

class ITile :
	public aqua::IGameObject
{
public:
	ITile(aqua::IGameObject* parent,std::string name);
	~ITile() = default;

	virtual void Initialize(aqua::CVector2 position);
	virtual void Initialize(std::string block_name,aqua::CVector2 position);
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Finalize()override;

	void SetPosition(aqua::CVector2& position);

	aqua::CVector2 GetPosition();

	void SetNextTileNumber(int tile_number);

	int GetNowTileID();

	int GetMaxNextTileSize();

	int GetNextTile(int next_tile_number);

	static int m_tile_num;

	bool CheckOnTile(aqua::CVector2& position);

private:

	int m_NowID;

	std::vector<int> m_NextTileNumber;

	aqua::CSprite m_TileSprite;

	aqua::CVector2 m_TileSize;

	aqua::CVector2 m_CenterPosition;

};