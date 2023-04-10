#pragma once
#include "aqua.h"
#include "scene_enum.h"
class IScene : 
	public aqua::IGameObject
{
public:

	IScene(aqua::IGameObject* parent,std::string name);

	virtual ~IScene() = default;

	virtual void Update()override;

	virtual void Draw()override;

	virtual void Finalize()override;

	bool CheckChangeFlag();

	Scene::ID GetNextScene();

protected:

	Scene::ID m_NextSceneID;

	aqua::CLabel m_SceneName;

private:

	bool ChangeFlag;

};

