#pragma once
#include "../skill.h"
class CEmergencySurgery
	:ISkill
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CEmergencySurgery(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CEmergencySurgery() = default;

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