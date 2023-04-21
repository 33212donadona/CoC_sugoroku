#pragma once
#include "aqua.h"

class IBlock :
	public aqua::IGameObject
{
public:
	IBlock(aqua::IGameObject* parent,std::string category);
	~IBlock() = default;

	virtual void Initialize(std::string block_name);
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Finalize()override;

	bool m_HitBlock;

private:

	void HitBlock();

	aqua::CSprite m_BlockSprite;

	aqua::CVector2 m_BlockSize;

};