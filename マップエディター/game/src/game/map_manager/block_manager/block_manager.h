#pragma once
#include "aqua.h"

class CBlockManager :
	public aqua::IGameObject
{
public:

	CBlockManager(aqua::IGameObject* parent);
	~CBlockManager() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:



};