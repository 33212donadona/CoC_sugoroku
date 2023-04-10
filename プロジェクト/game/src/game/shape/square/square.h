#pragma once
#include "aqua.h"
#include "../../button/button_info.h"
class CSquare : public aqua::IGameObject
{
public:
	CSquare(aqua::IGameObject* parent);
	~CSquare() = default;

	shape_button::Shape SetShape
	(
		int width,
		int height,
		std::string square_file_name,
		aqua::CVector2 position
	);

};