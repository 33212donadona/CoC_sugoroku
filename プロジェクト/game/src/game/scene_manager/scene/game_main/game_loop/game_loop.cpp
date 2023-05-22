#include "game_loop.h"
#include "loop_scene/main_work/main_game_work.h"

CGameLoop::CGameLoop(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"GameLoop")
{
}

void CGameLoop::Initialize()
{
	aqua::CreateGameObject<CMainGameWork>(this);

	aqua::IGameObject::Initialize();
}

void CGameLoop::Update()
{
	aqua::IGameObject::Update();
}

void CGameLoop::Draw()
{
	aqua::IGameObject::Draw();
}

void CGameLoop::Finalize()
{
	aqua::IGameObject::Finalize();
}
