#include "square.h"

CSquare::CSquare(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Square")
{
}

shape_button::Shape CSquare::SetShape
(
	int width,
	int height,
	std::string square_file_name,
	aqua::CVector2 position
)
{
	shape_button::Shape info;

	info.m_file_name = square_file_name;

	info.width = width;

	info.height = height;

	info.m_max_button_sprite = (int)shape_button::LAYOUT_ID::MAX;

	info.m_sprite.Create(square_file_name);

	info.m_sprite.position = position;

	info.m_mouse_over = [=](aqua::CVector2 mouse_pos)
	{
		float PosX = position.x;
		float PosY = position.y;

		bool x = (PosX < mouse_pos.x) && (mouse_pos.x <= PosX + info.width);

		bool y = (PosY < mouse_pos.y) && (mouse_pos.y <= PosY + info.height);

		return (x && y);

	};

	return info;
}
