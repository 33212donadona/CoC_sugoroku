#pragma once
#include "../skill.h"
class CDose
	:ISkill
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CDose(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CDose() = default;

	/*!
	 *   @brief ������
	 */
	void Update()override;

	/*!
	*   @brief ���
	*/
	void Finalize()override ;

	/*!
	 *  @brief �X�L���̔���
	 */
	void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara);

};