#include "save_manager.h"
#include "../back_ground_manager/back_ground_manager.h"
#include "../tile_manager/tile_manager.h"

const float CSaveManager::m_min_button_size = 1.0f;
const float CSaveManager::m_max_button_size = 1.5f;
const float CSaveManager::m_max_size_easing_time = 1.0f;
const float CSaveManager::m_max_message_time = 2.5f;
const int   CSaveManager::m_message_font_size = 100;
const int   CSaveManager::m_message_box_space = 10;

CSaveManager::CSaveManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SaveManager")
	, m_SaveMessageFlag(false)
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

	// メッセージラベルの設定
	m_MessageLabel.Create(m_message_font_size);
	m_MessageLabel.text = "保存しました";
	m_MessageLabel.position = aqua::GetWindowSize() / 2.0f;
	m_MessageLabel.position.x -= m_MessageLabel.GetTextWidth() / 2.0f;
	m_MessageLabel.position.y -= m_MessageLabel.GetFontHeight() / 2.0f;
	m_MessageLabel.color.alpha = 0x00;

	// メッセージボックスの設定
	m_MessageBox.Setup
	(
		m_MessageLabel.position - aqua::CVector2::ONE * m_message_box_space / 2.0f,
		float(m_MessageLabel.GetTextWidth() + m_message_box_space),
		float(m_MessageLabel.GetFontHeight() + m_message_box_space),
		0x00000000
	);

	// 背景管理クラス
	m_BackGroundClass = (CBackGroundManager*)aqua::FindGameObject("BackGroundManager");
	// タイル管理クラス
	m_TileManagerClass = (CTileManager*)aqua::FindGameObject("TileManager");

	// イージング時間
	m_SizeEasingTime.Setup(m_max_size_easing_time);

	// メッセージ時間
	m_MessageTime.Setup(m_max_message_time);

	m_MessageTime.SetTime(m_max_message_time);
}

/*
 *  更新
 */
void CSaveManager::Update()
{
	ClickHitButton(aqua::CVector2(aqua::mouse::GetCursorPos()));

	ButtonChangeSize();

	MessageUpdata();

	m_SaveButtonSize = aqua::Limit(m_SaveButtonSize, m_min_button_size, m_max_button_size);
}

/*
 *  描画
 */
void CSaveManager::Draw()
{
	m_SaveButtonSprite.Draw();

	m_MessageBox.Draw();
	m_MessageLabel.Draw();
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
		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT) 
			&& m_BackGroundClass && m_TileManagerClass)
		{

			m_SaveMessageFlag = m_BackGroundClass->SaveSprite();

			m_TileManagerClass->SaveTile();

			m_SaveButtonSprite.color = (aqua::CColor)0xffffffff;

		}

		// カーソルフラグを真
		m_CursorOnButton = true;

	}
	else
	{
		if (m_CursorOnButton)
			m_SaveButtonSprite.color = (aqua::CColor)0xffffffff;

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

/*
 *   メッセージの表示時間
 */
void CSaveManager::MessageUpdata()
{
	if (m_SaveMessageFlag && m_MessageTime.Finished())
		m_MessageTime.Reset();

	if (m_SaveMessageFlag || !m_MessageTime.Finished())
	{
		m_SaveMessageFlag = false;

		m_MessageLabel.color.alpha =
			(unsigned char)aqua::easing::InCubic
			(
				m_MessageTime.GetTime(),
				m_MessageTime.GetLimit(),
				255,
				0
			);

		m_MessageBox.color.alpha = m_MessageLabel.color.alpha;

		m_MessageTime.Update();
	}
}
