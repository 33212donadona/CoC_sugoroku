#pragma once
#include "../scene.h"

class CStageManager;

class CGameMain :
    public IScene
{
public:

    /*
    *  @brief �R���X�g���N�g
    */
    CGameMain(aqua::IGameObject* parent);

    /*
     * @brief ������
     */
    void Initialize()override;

    /*
    *  @brief �X�V
    */
    void Update()override;

    /*
    *  @brief �`��
    */
    void Draw()override;

    /*
    *  @brief ���
    */
    void Finalize()override;

private:
    static const std::string scene_name;      //! �V�[���̖��O
    static const SceneID   m_next_scene;      //! ���̃V�[����ID

    CStageManager*       m_StageManager;      //! �X�e�[�W�Ǘ��N���X
};