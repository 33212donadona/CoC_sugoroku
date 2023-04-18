#pragma once
#include "aqua.h"

class CBackGroundManager;

class CSaveManager :
	public aqua::IGameObject
{
public:

	CSaveManager(aqua::IGameObject* parent);
	~CSaveManager() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:

	/*
	 *  @brief ボタンのクリック処理 
	 */
	void ClickHitButton(aqua::CVector2& position);

private:

	static const float m_min_button_size;
	static const float m_max_button_size;
	static const float m_max_size_easing_time;

	CBackGroundManager* m_BackGroundClass; //  背景クラス

	aqua::CSprite m_SaveButtonSprite;
	aqua::CTimer m_SizeEasingTime;

	float m_SaveButtonSize;

	bool m_NowButton;
	bool m_PrivNowButton;

};