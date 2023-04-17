#pragma once
#include "aqua.h"

class CMapManager :
	public aqua::IGameObject
{
public:

	CMapManager(aqua::IGameObject* parent);
	~CMapManager() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:

	char buffer[MAX_PATH];

	aqua::CSprite s;

};