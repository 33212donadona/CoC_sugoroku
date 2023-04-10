#pragma once
#include "aqua.h"
#include <functional>
namespace shape_button 
{
	enum class LAYOUT_ID
	{
		UPPER_LEFT,
		UPPER_RIGHT,
		LOWER_LEFT,
		LOWER_RIGHT,
		LEFT,
		RIGHT,
		UPPER,
		LOWER,
		CENTER,

		MAX
	};

	enum class SHAPE_ID
	{
		SQUARE,
		CIRCLE,
		MAX
	};

	enum class INPUT_MODE
	{
		IN_MODE,
		KEEP_MODE,
		OUT_MODE
	};

	struct Shape
	{
		int width = 64;
		int height = 64;
		float scale = 1.0f;
		aqua::CSprite m_sprite;
		std::string m_file_name;
		int m_max_button_sprite = (int)LAYOUT_ID::MAX;
		std::function<bool(aqua::CVector2 mouse_pos)> m_mouse_over;
		SHAPE_ID m_shape_id = SHAPE_ID::SQUARE;
	};

}