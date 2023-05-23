#pragma once
#include "../scene.h"

class CSelectCharactor;

class CSelect :
    public IScene
{
public:

    /*
    *  @brief �R���X�g���N�g
    */
    CSelect(aqua::IGameObject* parent);

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

    CSelectCharactor* m_SelectChara;
};