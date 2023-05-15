#pragma once
#include "../skill.h"
class CFiring
	:ISkill
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
};