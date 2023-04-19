#include "save_manager.h"
#include "../back_ground_manager/back_ground_manager.h"

const float CSaveManager::m_min_button_size = 1.0f;
const float CSaveManager::m_max_button_size = 1.5f;
const float CSaveManager::m_max_size_easing_time = 1.0f;
const float CSaveManager::m_max_massage_time = 2.5f;

CSaveManager::CSaveManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SaveManager")
{
}

/*
 *  初期化
 */
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

	// メッセージ時間
	m_MassageTime.Setup(m_max_massage_time);

}

/*
 *  更新
 */
void CSaveManager::Update()
{
	ClickHitButton(aqua::CVector2(aqua::mouse::GetCursorPos()));

	ButtonChangeSize();

	m_SaveButtonSize = aqua::Limit(m_SaveButtonSize, m_min_button_size, m_max_button_size);
}

/*
 *  描画
 */
void CSaveManager::Draw()
{
	m_SaveButtonSprite.Draw();
}

/*
 *  解放
 */
void CSaveManager::Finalize()
{
	m_SaveButtonSprite.Delete();
}

/*
 *  ボタン処理
 */
void CSaveManager::ClickHitButton(aqua::CVector2& position)
{
	// 前フレームのフラグを保存
	m_PrivCursorOnButton = m_CursorOnButton;

	// ボタンの原点
	aqua::CVector2 origin = m_SaveButtonSprite.position;

	// ボタンの衝突判定
	if (
		position.x >= origin.x &&
		position.y >= origin.y &&
		position.x < origin.x + m_SaveButtonSprite.GetTextureWidth() * m_SaveButtonSprite.scale.x &&
		position.y < origin.y + m_SaveButtonSprite.GetTextureHeight() * m_SaveButtonSprite.scale.y
		)
	{

		if (aqua::mouse::Button(aqua::mouse::BUTTON_ID::LEFT))
			m_SaveButtonSprite.color = (aqua::CColor)0xff5f5f5f;

		// 左クリックでセーブ
		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT) && m_BackGroundClass)
		{
			m_SaveMassageFlag = m_BackGroundClass->SaveSprite();

			m_SaveButtonSprite.color = (aqua::CColor)0xffffffff;
		}

		// カーソルフラグを真
		m_CursorOnButton = true;

	}
	else
	{
		// カーソルフラグを偽
		m_CursorOnButton = false;
	}
}

/*
 *  ボタンのサイズ変更
 */
void CSaveManager::ButtonChangeSize()
{
	// 拡大処理
	if (!m_SizeEasingTime.Finished())
	{
		// カーソルが中に入ったら真
		if (m_CursorOnButton)
		{
			// 拡大
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
			// 縮小
			m_SaveButtonSprite.scale = aqua::CVector2::ONE *
				aqua::easing::OutCubic
				(
					m_SizeEasingTime.GetTime(),
					m_SizeEasingTime.GetLimit(),
					m_max_button_size,
					m_min_button_size
				);
		}
	}
	else
	{
		// 時間を過ぎたら最大時間で固定
		m_SizeEasingTime.SetTime(m_SizeEasingTime.GetLimit());

		// 拡大時間のリセット
		if (m_CursorOnButton == !m_PrivCursorOnButton)
		{
			m_SizeEasingTime.SetTime(m_SizeEasingTime.GetLimit() - m_SizeEasingTime.GetTime());
		}
	}


	// 時間の更新
	m_SizeEasingTime.Update();

	// 大きさの分だけ画像移動
	m_SaveButtonSprite.position = aqua::GetWindowSize();
	m_SaveButtonSprite.position.x -= m_SaveButtonSprite.GetTextureWidth() * m_SaveButtonSprite.scale.x;
	m_SaveButtonSprite.position.y -= m_SaveButtonSprite.GetTextureHeight() * m_SaveButtonSprite.scale.y;

}
