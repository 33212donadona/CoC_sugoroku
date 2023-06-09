#include "battle_scene.h"
#include "turn/turn.h"

CBattleScene::CBattleScene(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BattleScene")
{
}

/*
*  初期化
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
*  更新
*/
void CBattleScene::Update()
{
	IGameObject::Update();
}

/*
*  描画
*/
void CBattleScene::Draw()
{
	m_BackGround.Draw();
	aqua::IGameObject::Draw();
}

/*
*  解放
*/
void CBattleScene::Finalize()
{
	m_BackGround.Delete();
	aqua::IGameObject::Finalize();
}