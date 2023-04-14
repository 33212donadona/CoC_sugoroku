#pragma once
#include "../scene.h"
class CTitle :
    public IScene
{
public:
    /*!
    *  @brief �R���X�g���N�g
    */
    CTitle(aqua::IGameObject* parent);

    /*!
     * @brief ������
     */
    void Initialize()override;

    /*!
    *  @brief �X�V
    */
    void Update()override;

    /*!
    *  @brief �`��
    */
    void Draw()override;

    /*!
    *  @brief ���
    */
    void Finalize()override;
private:

    static const std::string scene_name;      //! �V�[���̖��O
    static const Scene::ID   m_next_scene;    //! ���̃V�[����ID

    aqua::CSprite  m_GroundSprite;            //! �n�ʂ̉摜
    aqua::CSprite  m_GroundLineSprite;        //! �����̉摜
    aqua::CSprite  m_LabelSprite;             //! �^�C�g�����̉摜
    aqua::CSprite  m_LeftBilldingSprite;      //! �����r���̉摜
    aqua::CSprite  m_RightBilldingSprite;     //! �E���r���̉摜
};