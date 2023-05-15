#pragma once
#include "../skill.h"
class CScolding
	:ISkill
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CScolding(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CScolding() = default;

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
	static const int m_strength_up;
	STATUS* m_MyStatus;
};