#include "battle_scene.h"
#include "turn/turn.h"

CBattleScene::CBattleScene(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BattleScene")
{
}

/*
*  ������
*/
void CBattleScene::Initialize(std::string back_ground_name)
{

	m_BackGround.Create(back_ground_name);
	m_BackGround.scale.x = (float)(m_BackGround.GetTextureWidth()  / aqua::GetWindowSize().x);
	m_BackGround.scale.y = (float)(m_BackGround.GetTextureHeight() / aqua::GetWindowSize().y);

	aqua::CreateGameObject<CTurn>(this);
	IGameObject::Initialize();

}

/*
*  �X�V
*/
void CBattleScene::Update()
{
	IGameObject::Update();
}

/*
*  �`��
*/
void CBattleScene::Draw()
{
	m_BackGround.Draw();
	IGameObject::Update();
}

/*
*  ���
*/
void CBattleScene::Finalize()
{
	m_BackGround.Delete();
	IGameObject::Update();
}