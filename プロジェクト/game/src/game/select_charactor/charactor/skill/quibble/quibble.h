#pragma once
#include "../skill.h"
class CQuibble
	:public ISkill
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CQuibble(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CQuibble() = default;

	/*!
	 *   @brief ������
	 */
	void Update()override;

	/*!
	*   @brief ���
	*/
	void Finalize()override;

	/*!
	 *  @brief �X�L���̔���
	 */
	void InvokeSkill(STATUS_LIST& m_SubjectChara);

private:
	static const int   m_quibble_damage;
	static const float m_quibble_down_rate;


};