#pragma once
#include "../skill.h"
class CFinale
	:ISkill
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CFinale(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CFinale() = default;

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