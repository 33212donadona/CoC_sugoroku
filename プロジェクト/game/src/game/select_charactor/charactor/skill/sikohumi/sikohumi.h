#pragma once
#include "../skill.h"
class CSikohumi
	:ISkill
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CSikohumi(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CSikohumi() = default;

	/*!
	 *   @brief ������
	 */
	void Update()override;

	/*!
	*   @brief ���
	*/
	void Finalize()override {};

	/*!
	 *  @brief �X�L���̔���
	 */
	void InvokeSkill(STATUS& m_MyChara, STATUS_LIST& m_SubjectChara);

};