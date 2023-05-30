#pragma once
#include "../scene.h"
class CTitle :
    public IScene
{
public:
    /*
    *  @brief �R���X�g���N�g
    */
    CTitle(aqua::IGameObject* parent);

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

    void SpriteScale();



private:
    static const std::string scene_name;      //! �V�[���̖��O
    static const SceneID   m_next_scene;      //! ���̃V�[����ID
    static const int      m_baund_speed;
    static const int      m_font_size;
    static const float    m_easing_time;

    aqua::CSprite  m_GroundSprite;            //! �n�ʂ̉摜
    aqua::CSprite  m_GroundLineSprite;        //! �����̉摜
    aqua::CSprite  m_LabelSprite;             //! �^�C�g�����̉摜
    aqua::CSprite  m_LeftBilldingSprite;      //! �����r���̉摜
    aqua::CSprite  m_RightBilldingSprite;     //! �E���r���̉摜

    aqua::CSprite  m_BackGround;

    aqua::CTimer   m_EasingTime;

    aqua::CLabel   m_StartLabel;              //! 

    int            m_Frame;
    float          m_Rotation;
};