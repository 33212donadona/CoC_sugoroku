#pragma once
#include "../skill.h"
class CQuibble
	:ISkill
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
	void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara);
};