#include "circle.h"
CCircle::CCircle(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Circle")
{
}
// 丸の形
shape_button::Shape CCircle::SetShape
(
	float scale,
	std::string square_file_name, 
	aqua::CVector2 position
)
{
	// 戻り値
	shape_button::Shape info;

	// 画像アドレス
	info.m_file_name = square_file_name;
	// 画像の生成
	info.m_sprite.Create(info.m_file_name);

	info.m_sprite.position = position;

	info.width = info.m_sprite.GetTextureWidth() * scale;

	info.height = info.m_sprite.GetTextureHeight() * scale;

	info.scale = scale;

	// 分割数
	info.m_max_button_sprite = 1;

	info.m_shape_id = shape_button::SHAPE_ID::CIRCLE;

	info.m_mouse_over = [=](aqua::CVector2 mouse_pos)
	{
		float PosX = position.x + info.width / 2.0f;
		float PosY = position.y + info.height/ 2.0f;

		float x = (PosX - mouse_pos.x);

		float y = (PosY - mouse_pos.y);

		float r = info.width / 2.0f;

		return sqrt (x * x + y * y) <= r;
	};

	return info;
}
