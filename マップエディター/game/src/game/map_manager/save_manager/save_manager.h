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
	 *  @brief �{�^���̃N���b�N���� 
	 */
	void ClickHitButton(aqua::CVector2& position);

	/*
	 *  @brief �{�^���̃T�C�Y�ύX
	 */
	void ButtonChangeSize();

private:

	static const float m_min_button_size;	   //  
	static const float m_max_button_size;	   //  
	static const float m_max_size_easing_time; //  
	static const float m_max_massage_time;     //  

	CBackGroundManager* m_BackGroundClass;     //  �w�i�N���X

	aqua::CSprite m_SaveButtonSprite;          //  
	aqua::CTimer m_SizeEasingTime;			   //  
	aqua::CTimer m_MassageTime;			       //  

	float m_SaveButtonSize;                    //  

	bool m_CursorOnButton;                     //  
	bool m_PrivCursorOnButton;				   //  
	bool m_SaveMassageFlag;  				   //  �Z�[�u���̃��b�Z�[�W�t���O

};