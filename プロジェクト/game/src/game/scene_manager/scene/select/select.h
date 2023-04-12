#pragma once
#include "../scene.h"

class CSelect :
    public IScene
{
public:
    CSelect(aqua::IGameObject* parent);
    void Update()override;
    void Draw()override;
    void Finalize()override;
private:
    static const std::string scene_name;
};