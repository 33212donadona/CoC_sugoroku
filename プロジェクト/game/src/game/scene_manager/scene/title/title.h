#pragma once
#include "../scene.h"
class CTitle :
    public IScene
{
public:
    /*
    *  @brief コンストラクト
    */
    CTitle(aqua::IGameObject* parent);

    /*
     * @brief 初期化
     */
    void Initialize()override;

    /*
    *  @brief 更新
    */
    void Update()override;

    /*
    *  @brief 描画
    */
    void Draw()override;

    /*
    *  @brief 解放
    */
    void Finalize()override;
private:

    void SpriteScale();



private:
    static const std::string scene_name;      //! シーンの名前
    static const SceneID   m_next_scene;      //! 次のシーンのID
    static const int      m_baund_speed;
    static const int      m_font_size;
    static const float    m_easing_time;

    aqua::CSprite  m_GroundSprite;            //! 地面の画像
    aqua::CSprite  m_GroundLineSprite;        //! 白線の画像
    aqua::CSprite  m_LabelSprite;             //! タイトル名の画像
    aqua::CSprite  m_LeftBilldingSprite;      //! 左側ビルの画像
    aqua::CSprite  m_RightBilldingSprite;     //! 右側ビルの画像

    aqua::CSprite  m_BackGround;

    aqua::CTimer   m_EasingTime;

    aqua::CLabel   m_StartLabel;              //! 

    int            m_Frame;
    float          m_Rotation;
};