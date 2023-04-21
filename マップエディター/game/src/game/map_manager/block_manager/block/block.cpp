#include "block.h"

IBlock::IBlock(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"Block")
{
}

void IBlock::Initialize(std::string block_name)
{

	m_BlockSprite.Create(block_name);

	m_BlockSize.x = m_BlockSprite.GetTextureWidth();
	m_BlockSize.y = m_BlockSprite.GetTextureHeight();

}

void IBlock::Update()
{
}

void IBlock::Draw()
{
	m_BlockSprite.Draw();
}

void IBlock::Finalize()
{
	m_BlockSprite.Delete();
}

void IBlock::HitBlock()
{



}
