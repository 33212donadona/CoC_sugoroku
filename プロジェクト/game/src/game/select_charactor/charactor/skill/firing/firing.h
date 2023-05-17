#pragma once
#include "../skill.h"
class CFiring
	:public ISkill
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CFiring(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CFiring() = default;

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
	void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara);

private:
	static const float m_firing_damage_rate;
};