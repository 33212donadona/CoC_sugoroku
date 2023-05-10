#include "title.h"

const std::string CTitle::scene_name = "Title";
const SceneID   CTitle::m_next_scene = SceneID::SELECT;
const int CTitle::m_baund_speed = 7;
const int CTitle::m_font_size = 80;
const float CTitle::m_easing_time = 5.0f;

/*
 *  コンストラクタ
 */
CTitle::CTitle(aqua::IGameObject* parent)
	:IScene(parent, scene_name, m_next_scene)
	, m_Frame(0)
	, m_Rotation(0.0f)
{
}

/*
 *  初期化
 */
void CTitle::Initialize()
{
	m_StartLabel.Create(m_font_size);
	m_StartLabel.text = "～左クリックでスタート～";
	m_StartLabel.position.x = (aqua::GetWindowWidth()  - m_StartLabel.GetTextWidth()) / 2.0f;
	m_StartLabel.position.y = aqua::GetWindowWidth() * 0.7f - m_StartLabel.GetTextWidth() / 2.0f;
	m_StartLabel.color = 0xff7f7f7f;

	m_LeftBilldingSprite.Create("data\\title\\back_ground\\タイトル_ビル1.png");
	m_RightBilldingSprite.Create("data\\title\\back_ground\\タイトル_ビル2.png");
	m_GroundSprite.Create("data\\title\\back_ground\\タイトル_地面.png");
	m_GroundLineSprite.Create("data\\title\\back_ground\\タイトル_地面_ライン.png");
	m_LabelSprite.Create("data\\title\\back_ground\\タイトル_リボン.png");
	
	m_BackGround.Create("data\\title\\back_ground\\タイトル_空.png");

	m_LeftBilldingSprite.anchor.x = m_LeftBilldingSprite.GetTextureWidth() / 2.0f;
	m_LeftBilldingSprite.anchor.y = m_LeftBilldingSprite.GetTextureHeight() / 5.0f * 3.0f;

	m_RightBilldingSprite.anchor.x = m_RightBilldingSprite.GetTextureWidth() / 2.0f;
	m_RightBilldingSprite.anchor.y = m_RightBilldingSprite.GetTextureHeight() / 5.0f * 3.0f;

	m_BackGround.position.x -= m_BackGround.GetTextureWidth() / 4.0f;
	m_BackGround.position.y -= m_BackGround.GetTextureHeight() / 5.0f;
	
	m_BackGround.anchor.x = m_BackGround.GetTextureWidth() / 2.0f;
	m_BackGround.anchor.y = m_BackGround.GetTextureHeight() / 2.0f;

	m_FlashBackGround = m_BackGround;

	m_FlashBackGround.blend_mode = aqua::ALPHABLEND::ADD;

	m_EasingTime.Setup(m_easing_time);

}

/*
 *  更新
 */
void CTitle::Update()
{
	SpriteScale();

	m_Rotation -= 0.1f;
	m_FlashBackGround.rotation = 
	m_BackGround.rotation = aqua::DegToRad(m_Rotation);

	IScene::Update();
}

/*
 *  描画
 */
void CTitle::Draw()
{
	m_BackGround.Draw();
	m_FlashBackGround.Draw();
	m_LeftBilldingSprite.Draw();
	m_RightBilldingSprite.Draw();
	m_GroundSprite.Draw();
	m_GroundLineSprite.Draw();
	m_LabelSprite.Draw();
	m_StartLabel.Draw();

	IScene::Draw();
}

/*
 *  解放
 */
void CTitle::Finalize()
{
	m_BackGround.Delete();
	m_FlashBackGround.Delete();
	m_LeftBilldingSprite.Delete();
	m_RightBilldingSprite.Delete();
	m_GroundSprite.Delete();
	m_GroundLineSprite.Delete();
	m_LabelSprite.Delete();
	m_StartLabel.Delete();

	IScene::Finalize();
}

void CTitle::SpriteScale()
{
	m_Frame += m_baund_speed;
	m_EasingTime.Update();

	if (m_EasingTime.Finished())
		m_EasingTime.Reset();

	m_LeftBilldingSprite.scale.y =
		sin(aqua::DegToRad((float)m_Frame)) * 0.125f + 1.25f;

	m_RightBilldingSprite.scale.y =
		cos(aqua::DegToRad((float)m_Frame)) * 0.125f + 1.25f;

	m_FlashBackGround.color.alpha =
		(unsigned char)aqua::easing::InBack
		(
			m_EasingTime.GetTime(),
			m_EasingTime.GetLimit(),
			0.0f,
			155.0f
		);

}
