#pragma once
#include "aqua.h"
#include <functional>
#include "button_info.h"

class CButton :public aqua::IGameObject
{
public:

	CButton(aqua::IGameObject* parent);
	~CButton() = default;

	void Initialize
	(
		int font_size,
		std::string font_name,
		shape_button::Shape button_shape, // å`ÇÃê›íË
		std::function<void()> function = []() {} ,// è’ìÀèàóù
		aqua::mouse::BUTTON_ID function_flag = aqua::mouse::BUTTON_ID::LEFT,// è’ìÀÉtÉâÉO
		shape_button::INPUT_MODE input_mode = shape_button::INPUT_MODE::KEEP_MODE
	);

	void Update()override;

	void Draw()override;

	void Finalize()override;

private:

	void SetPosition(const aqua::CVector2& position = aqua::CVector2::ZERO);

	void SetSize(int width, int height);

	void SetRect();

private:

	aqua::CSprite* m_Shape; // âÊëú
	aqua::CLabel m_Label;
	aqua::CVector2 m_Position;
	shape_button::Shape m_Button;
	aqua::mouse::BUTTON_ID m_MouseKey;
	shape_button::INPUT_MODE m_InputMode;
	std::function<void()> m_Function;
	int m_Width;
	int m_Height;

	shape_button::Shape m_ShapeData;
	bool                m_ButtonFlag;

	static const int			m_min_button_size;			//
	static const int			m_default_font_size;		//
	static const int            m_Shape_sprite_mini;        //
	static const int			m_corner_size;				//
	static const int			m_default_texture_size;     //
	static const unsigned int	m_default_color;		    //
	static const unsigned int	m_select_color;			    //
	static const unsigned int	m_clicked_color;		    //
	static const unsigned int	m_text_color;			    //
	int							m_Shape_sprite_count;		//

};