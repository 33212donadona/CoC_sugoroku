#pragma once
#include "../scene.h"

class CGameMain :
    public IScene
{
public:
    CGameMain(aqua::IGameObject* parent);
    void Update()override;
    void Draw()override;
    void Finalize()override;
private:
    static const std::string scene_name;
};

