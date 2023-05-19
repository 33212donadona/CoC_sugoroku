#pragma once
#include "aqua.h"
#include "../charactor/charactor_id.h"

using ParamVector = std::vector<aqua::CBoxPrimitive>;

class CParameter :
	public aqua::IGameObject
{
public:

	/*!
	 *  @brief �R���X�g���N�^
	 */
	CParameter(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CParameter() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize
	(
		STATUS& parameter,
		aqua::CVector2 position = aqua::CVector2::ZERO,
		aqua::CVector2 size = aqua::CVector2(aqua::GetWindowSize().x, aqua::GetWindowSize().y / 2)
	);

	/*!
	 *  @brief �X�V
	 */
	void Update()override;

	/*!
	 *  @brief �`��
	 */
	void Draw()override;

	/*!
	 *  @brief ���
	 */
	void Finalize()override;

private:

	void ParamSetUp(ParamVector* param_box, int parameter, int max_parameter,aqua::CVector2 position);

private:
	static const aqua::CPoint m_division;
	static const aqua::CPoint m_param_start_division;
	static const aqua::CVector2 m_param_box_size;
	static const unsigned int m_param_color;
	static const unsigned int m_param_color_overe;

	STATUS m_Parameter;        // �p�����[�^�[
	aqua::CVector2 m_Position; // ���W
	aqua::CVector2 m_Size;	   // �傫��
	aqua::CVector2 m_Scale;	   // �傫��

	ParamVector m_ParamBoxHp;  // HP�̃p�����[�^�[������
	ParamVector m_ParamBoxStr; // STR�̃p�����[�^�[������
	ParamVector m_ParamBoxDex; // DEX�̃p�����[�^�[������


};