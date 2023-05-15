#pragma once
#include "aqua.h"
#include "../charactor_id.h"

class ISkill
	:aqua::IGameObject
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	ISkill(aqua::IGameObject* parent,std::string name);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~ISkill() = default;

	/*!
	*   @brief ������
	*/
	virtual void Update()override {};

	/*!
	*   @brief ���
	*/
	virtual void Finalize()override {};

	/*!
	 *  @brief �X�L���̔���
	 */
	virtual void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara) {};

	/*!
	 *  @brief �X�L���̔���
	 */
	virtual void InvokeSkill(STATUS& m_MyChara) {};

	/*!
	 *  @brief �X�L���̔���
	 */
	virtual void InvokeSkill(STATUS_LIST& m_SubjectChara) {};

	/*!
	 *  @brief �X�L���̔���
	 */
	virtual void InvokeSkill(STATUS& m_MyChara,STATUS_LIST& m_SubjectChara) {};
};