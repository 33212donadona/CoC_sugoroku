#pragma once
#include "../skill.h"
class CFinale
	:public ISkill
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
	void InvokeSkill( STATUS_LIST& m_SubjectChara);

private:

	static const float m_finale_rate;

};