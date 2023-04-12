#pragma once
#include "aqua.h"
#include "scene/scene.h"
class CSceneManager :
	public aqua::IGameObject
{
public:

	CSceneManager(aqua::IGameObject* parent);
	~CSceneManager() = default;

	void Initialize()override;
	void Update()override;

private:

	void ChageScene(Scene::ID scene_id);

private:
	IScene* m_Scene;
	Scene::ID m_NectID;
};

