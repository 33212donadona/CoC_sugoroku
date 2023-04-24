#pragma once
#include "../tile.h"

class CIventTile :
	public ITile
{
public:

	CIventTile(aqua::IGameObject* parent);
	~CIventTile() = default;

	void Initialize(aqua::CVector2 position)override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:
};