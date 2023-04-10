#include "button.h"

const int CButton::m_corner_size = 12;
const int CButton::m_min_button_size = CButton::m_corner_size * 2;
const int CButton::m_default_font_size = 10;
const int CButton::m_Shape_sprite_mini = (int)shape_button::LAYOUT_ID::UPPER_LEFT;
const int CButton::m_default_texture_size = 64;
const unsigned int CButton::m_default_color = 0xffffffff;
const unsigned int CButton::m_select_color = 0xffeeeeee;
const unsigned int CButton::m_clicked_color = 0xffeeffff;
const unsigned int CButton::m_text_color = 0xff000000;

CButton::CButton(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Button")
	, m_ButtonFlag(false)
{
}

void CButton::Initialize(
	int font_size,
	std::string font_name,
	shape_button::Shape button_shape,
	std::function<void()> function,
	aqua::mouse::BUTTON_ID function_flag,
	shape_button::INPUT_MODE input_mode
)
{
	m_Shape_sprite_count = button_shape.m_max_button_sprite;

	m_Shape = AQUA_NEW aqua::CSprite[m_Shape_sprite_count];

	for (int s_i = m_Shape_sprite_mini; s_i < m_Shape_sprite_count; ++s_i)
	{
		m_Shape[s_i] = button_shape.m_sprite;
	}

	m_Label.Create(font_size);

	m_Label.text = font_name;
	m_Label.color = 0xff000000;

	if (button_shape.m_shape_id == shape_button::SHAPE_ID::SQUARE)
	{
		SetRect();
		SetSize(button_shape.width, button_shape.height);
		SetPosition(button_shape.m_sprite.position);
	}
	else
		m_Shape[0].scale = aqua::CVector2::ONE * button_shape.scale;

	m_Button = button_shape;
	m_MouseKey = function_flag;
	m_InputMode = input_mode;
	m_Function = function;

	int center;

	if (button_shape.m_shape_id == shape_button::SHAPE_ID::SQUARE)
		center = (int)shape_button::LAYOUT_ID::MAX / 2;
	else
		center = 0;

	float w = m_Shape[center].position.x + button_shape.width / 2.0f - (float)m_Label.GetTextWidth() / 2.0f;
	float h = m_Shape[center].position.y + button_shape.height / 2.0f - (float)m_Label.GetFontHeight() / 2.0f;

	m_Label.position = aqua::CVector2(w, h);

}

void CButton::Update()
{
	bool flag = m_Button.m_mouse_over(aqua::CVector2((float)aqua::mouse::GetCursorPos().x, (float)aqua::mouse::GetCursorPos().y));

	bool input = false;

	if (m_InputMode == shape_button::INPUT_MODE::IN_MODE)
		input = aqua::mouse::Trigger(m_MouseKey);

	if (m_InputMode == shape_button::INPUT_MODE::KEEP_MODE)
	{
		input = aqua::mouse::Button(m_MouseKey);
	}

	if (m_InputMode == shape_button::INPUT_MODE::OUT_MODE)
		input = aqua::mouse::Released(m_MouseKey);

	if (flag && aqua::mouse::Trigger(m_MouseKey))
		m_ButtonFlag = true;

	if (!flag)
		m_ButtonFlag = false;

	if (m_ButtonFlag && input)
		m_Function();

}

void CButton::Draw()

{
	for (int s_i = m_Shape_sprite_mini; s_i < m_Shape_sprite_count; ++s_i)
		m_Shape[s_i].Draw();

	m_Label.Draw();
}

void CButton::Finalize()
{
	m_Label.Delete();

	for (int s_i = m_Shape_sprite_mini; s_i < m_Shape_sprite_count; ++s_i)
		m_Shape[s_i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_Shape);
}
void CButton::SetPosition(const aqua::CVector2& position)
{
	m_Position = position;

	float cw = (float)(m_Width - m_corner_size);
	float ch = (float)(m_Height - m_corner_size);

	m_Shape[(int)shape_button::LAYOUT_ID::UPPER_LEFT].position =
		m_Position;
	m_Shape[(int)shape_button::LAYOUT_ID::UPPER_RIGHT].position =
		m_Position + aqua::CVector2(cw, 0.0f);
	m_Shape[(int)shape_button::LAYOUT_ID::LOWER_LEFT].position =
		m_Position + aqua::CVector2(0.0f, ch);
	m_Shape[(int)shape_button::LAYOUT_ID::LOWER_RIGHT].position =
		m_Position + aqua::CVector2(cw, ch);
	m_Shape[(int)shape_button::LAYOUT_ID::LEFT].position =
		m_Position + aqua::CVector2(0.0f, (float)m_corner_size);
	m_Shape[(int)shape_button::LAYOUT_ID::UPPER].position =
		m_Position + aqua::CVector2((float)m_corner_size, 0.0f);
	m_Shape[(int)shape_button::LAYOUT_ID::RIGHT].position =
		m_Position + aqua::CVector2(cw, (float)m_corner_size);
	m_Shape[(int)shape_button::LAYOUT_ID::LOWER].position =
		m_Position + aqua::CVector2((float)m_corner_size, ch);
	m_Shape[(int)shape_button::LAYOUT_ID::CENTER].position =
		m_Position + aqua::CVector2((float)m_corner_size, (float)m_corner_size);

	m_Label.position = m_Position;
	m_Label.position.x += (float)m_Width / 2.0f - (float)m_Label.GetTextWidth() / 2.0f;
	m_Label.position.y += (float)m_Height / 2.0f - (float)m_Label.GetFontHeight() / 2.0f;
}

void CButton::SetSize(int width, int height)
{
	m_Width = max(width, m_min_button_size);
	m_Height = max(height, m_min_button_size);

	float cs = m_corner_size * 2.0f;

	float sw = (float)(m_Width - cs) / (float)(m_default_texture_size - cs);
	float sh = (float)(m_Height - cs) / (float)(m_default_texture_size - cs);

	m_Shape[(int)shape_button::LAYOUT_ID::LEFT].scale = aqua::CVector2(1.0f, sh);
	m_Shape[(int)shape_button::LAYOUT_ID::UPPER].scale = aqua::CVector2(sw, 1.0f);
	m_Shape[(int)shape_button::LAYOUT_ID::RIGHT].scale = aqua::CVector2(1.0f, sh);
	m_Shape[(int)shape_button::LAYOUT_ID::LOWER].scale = aqua::CVector2(sw, 1.0f);
	m_Shape[(int)shape_button::LAYOUT_ID::CENTER].scale = aqua::CVector2(sw, sh);

	if (m_Label.GetTextWidth() > m_Width)
		m_Label.visible = false;
	else
		m_Label.visible = true;

	SetPosition(m_Position);
}

void CButton::SetRect(void)
{
	int cs = m_default_texture_size - m_corner_size;

	m_Shape[(int)shape_button::LAYOUT_ID::UPPER_LEFT].rect =
		aqua::CRect(0, 0, m_corner_size, m_corner_size);

	m_Shape[(int)shape_button::LAYOUT_ID::UPPER_RIGHT].rect =
		aqua::CRect(cs, 0, m_default_texture_size, m_corner_size);

	m_Shape[(int)shape_button::LAYOUT_ID::LOWER_LEFT].rect =
		aqua::CRect(0, cs, m_corner_size, m_default_texture_size);

	m_Shape[(int)shape_button::LAYOUT_ID::LOWER_RIGHT].rect =
		aqua::CRect(cs, cs, m_default_texture_size, m_default_texture_size);

	m_Shape[(int)shape_button::LAYOUT_ID::LEFT].rect =
		aqua::CRect(0, m_corner_size, m_corner_size, cs);

	m_Shape[(int)shape_button::LAYOUT_ID::UPPER].rect =
		aqua::CRect(m_corner_size, 0, cs, m_corner_size);

	m_Shape[(int)shape_button::LAYOUT_ID::RIGHT].rect =
		aqua::CRect(cs, m_corner_size, m_default_texture_size, cs);

	m_Shape[(int)shape_button::LAYOUT_ID::LOWER].rect =
		aqua::CRect(m_corner_size, cs, cs, m_default_texture_size);

	m_Shape[(int)shape_button::LAYOUT_ID::CENTER].rect =
		aqua::CRect(m_corner_size, m_corner_size, cs, cs);
}