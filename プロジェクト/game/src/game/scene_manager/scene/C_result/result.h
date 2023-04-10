#pragma once
#include "../scene.h"
class CResult :
	public IScene
{
public:
	CResult(aqua::IGameObject* parent);
	void Update()override;
	void Draw()override;
	void Finalize()override;
private:
	static const std::string scene_name;
};

