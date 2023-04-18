#include "save_manager.h"
#include "../back_ground_manager/back_ground_manager.h"

const float CSaveManager::m_min_button_size = 1.0f;
const float CSaveManager::m_max_button_size = 3.5f;
const float CSaveManager::m_max_size_easing_time = 1.0f;

CSaveManager::CSaveManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"SaveManager")
{
}

void CSaveManager::Initialize()
{
	// ボタン画像の読み込み
	m_SaveButtonSprite.Create("data\\button\\Buttom.png");

	// ボタン画像の座標を設定
	m_SaveButtonSprite.position = aqua::GetWindowSize();

	m_SaveButtonSprite.position.x -= m_SaveButtonSprite.GetTextureWidth();
	m_SaveButtonSprite.position.y -= m_SaveButtonSprite.GetTextureHeight();

	// 背景クラス
	m_BackGroundClass = (CBackGroundManager*)aqua::FindGameObject("BackGroundManager");

	// イージング時間
	m_SizeEasingTime.Setup(m_max_size_easing_time);

}

void CSaveManager::Update()
{
	ClickHitButton(aqua::CVector2(aqua::mouse::GetCursorPos()));

	m_SaveButtonSize = aqua::Limit(m_SaveButtonSize, m_min_button_size, m_max_button_size);
}

void CSaveManager::Draw()
{
	m_SaveButtonSprite.Draw();
}

void CSaveManager::Finalize()
{
	m_SaveButtonSprite.Delete();
}

void CSaveManager::ClickHitButton(aqua::CVector2& position)
{

	m_PrivNowButton = m_NowButton;

	aqua::CVector2 origin = m_SaveButtonSprite.position;

	if (
		position.x >= origin.x &&
		position.y >= origin.y &&
		position.x < origin.x + m_SaveButtonSprite.GetTextureWidth() &&
		position.y < origin.y + m_SaveButtonSprite.GetTextureHeight()
		)
	{
		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT) && m_BackGroundClass)
			m_BackGroundClass->SaveSprite();

		m_NowButton = true;

		// 時間を過ぎたら最大時間で固定
		if (m_SizeEasingTime.Finished())
			m_SizeEasingTime.SetTime(m_SizeEasingTime.GetLimit());

		// 座標が合ったら拡大
		m_SaveButtonSprite.scale = aqua::CVector2::ONE *
			aqua::easing::InCubic
			(
				m_SizeEasingTime.GetTime(),
				m_SizeEasingTime.GetLimit(),
				m_min_button_size,
				m_max_button_size
			);
	}
	else
	{
		// 座標が合ったら拡大
		m_SaveButtonSprite.scale = aqua::CVector2::ONE *
			aqua::easing::OutCubic
			(
				m_SizeEasingTime.GetTime(),
				m_SizeEasingTime.GetLimit(),
				m_max_button_size,
				m_min_button_size
			);
	}

	// 大きさの分だけ移動
	m_SaveButtonSprite.position = aqua::GetWindowSize();
	m_SaveButtonSprite.position.x -= m_SaveButtonSprite.GetTextureWidth() * m_SaveButtonSprite.scale.x;
	m_SaveButtonSprite.position.y -= m_SaveButtonSprite.GetTextureHeight() * m_SaveButtonSprite.scale.y;

	// 時間の更新
	m_SizeEasingTime.Update();
}
