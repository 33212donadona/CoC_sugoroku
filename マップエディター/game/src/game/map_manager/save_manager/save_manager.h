#pragma once
#include "aqua.h"

class CBackGroundManager;
class CTileManager;

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

	/*
	 *  @brief ボタンのサイズ変更
	 */
	void ButtonChangeSize();

	/*
	 *  @brief メッセージの表示時間 
	 */
	void MessageUpdata();

private:

	static const float m_min_button_size;	   //  
	static const float m_max_button_size;	   //  
	static const float m_max_size_easing_time; //  
	static const float m_max_message_time;     //  
	static const int   m_message_font_size;    //  
	static const int   m_message_box_space;    //  

	CBackGroundManager* m_BackGroundClass;     //  背景管理クラス
	CTileManager*       m_TileManagerClass;    //  タイル管理クラス

	aqua::CSprite m_SaveButtonSprite;          //  
	aqua::CTimer m_SizeEasingTime;			   //  
	aqua::CTimer m_MessageTime;			       //  

	aqua::CLabel m_MessageLabel;               //  

	aqua::CBoxPrimitive m_MessageBox;		   //  

	float m_SaveButtonSize;                    //  

	bool m_CursorOnButton;                     //  
	bool m_PrivCursorOnButton;				   //  
	bool m_SaveMessageFlag;  				   //  セーブ時のメッセージフラグ

};