#pragma once
#include "../scene.h"
class CTitle :
    public IScene
{
public:
    CTitle(aqua::IGameObject* parent);
    void Update()override;
    void Draw()override;
    void Finalize()override;
private:
    static const std::string scene_name;
};

