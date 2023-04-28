#pragma once
#include "../tile.h"

class CNormalTile :
	public ITile
{
public:

	CNormalTile(aqua::IGameObject* parent);
	~CNormalTile() = default;

	void Initialize(aqua::CVector2 position)override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:



};