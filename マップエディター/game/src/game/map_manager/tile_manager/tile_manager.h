#pragma once
#include "aqua.h"
#include "tile/tile.h"
#include <fstream>

enum class TILE_ID
{
	NORMAL,
	IVENT,

	MAX
};

class CTileManager:
	public aqua::IGameObject
{
public:

	CTileManager(aqua::IGameObject* parent);
	~CTileManager() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

	void CreateTile(TILE_ID tile_id,aqua::CVector2 position);
	void SaveTile();

private:

	void WritingText(std::string w);

	void WritingTextCollEnd(std::string w = "");

private:

	std::ofstream m_TileDataText;

	std::list<ITile*> m_TileList;
};