#pragma once
#include "aqua.h"
#include "../../button/button_info.h"
class CCircle : public aqua::IGameObject
{
public:

	CCircle(aqua::IGameObject* parent);
	~CCircle() = default;
	// �ی^�̏��
	shape_button::Shape SetShape
	(
		float scale,
		std::string square_file_name,
		aqua::CVector2 position
	);

};