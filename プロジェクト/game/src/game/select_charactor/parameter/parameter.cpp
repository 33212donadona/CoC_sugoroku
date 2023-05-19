#include "parameter.h"
const aqua::CPoint   CParameter::m_division(4,10);
const aqua::CPoint   CParameter::m_param_start_division(3, 2);
const aqua::CVector2 CParameter::m_param_box_size(30,30);
const unsigned int CParameter::m_param_color = 0xffdfdf00;
const unsigned int CParameter::m_param_color_overe = 0xff7f7f7f;

CParameter::CParameter(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Parameter")
{
}

void CParameter::Initialize(STATUS& parameter, aqua::CVector2 position, aqua::CVector2 size)
{
	// ‘ã“ü
	m_Parameter = parameter;
	m_Position = position;
	m_Size = size;
	m_Scale = size / aqua::CVector2(aqua::GetWindowSize().x, aqua::GetWindowSize().y / 2);

	aqua::CVector2 base_pos = (m_Position + m_Size / m_division * m_param_start_division) * m_Scale;
	aqua::CVector2 param_pos = base_pos;

	param_pos.y += base_pos.y;

	ParamSetUp(&m_ParamBoxHp, (int)m_Parameter.m_Hp, m_max_hp, param_pos);

	param_pos.y += base_pos.y;

	ParamSetUp(&m_ParamBoxStr, (int)m_Parameter.m_Str, m_max_str, param_pos);

	param_pos.y += base_pos.y;

	ParamSetUp(&m_ParamBoxDex, (int)m_Parameter.m_Dex, m_max_dex, param_pos);

}

void CParameter::Update()
{
}

void CParameter::Draw()
{
	for (auto& hp_it : m_ParamBoxHp)
		hp_it.Draw();

	for (auto& str_it : m_ParamBoxStr)
		str_it.Draw();

	for (auto& dex_it : m_ParamBoxDex)
		dex_it.Draw();
}

void CParameter::Finalize()
{
}

void CParameter::ParamSetUp(ParamVector* param_box, int parameter, int max_parameter, aqua::CVector2 position)
{
	aqua::CVector2 pos = position;

	for (int i = 0; i < max_parameter; ++i)
	{
		aqua::CBoxPrimitive box;
		unsigned int color = m_param_color_overe;

		if (i <= parameter)
		{
			color = m_param_color;
		}

		if (i)
			pos.x += m_param_box_size.x * 2 * m_Scale.x;

		box.Setup
		(
			pos,
			m_param_box_size.x * m_Scale.x,
			m_param_box_size.y * m_Scale.y,
			color
		);

		param_box->push_back(box);
	}
}
