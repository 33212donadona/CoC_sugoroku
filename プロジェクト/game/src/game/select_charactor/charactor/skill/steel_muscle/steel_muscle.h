#pragma once
#include "../skill.h"
class CSteelMuscle
	:public ISkill
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CSteelMuscle(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CSteelMuscle() = default;

	/*!
	 *   @brief �X�V
	 */
	void Update()override;

	/*!
	*   @brief ���
	*/
	void Finalize()override {};

	/*!
	 *  @brief �X�L���̔���
	 */
	void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara);
};