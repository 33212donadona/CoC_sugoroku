#pragma once
#include "../skill.h"
class CDose
	:public ISkill
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
	void InvokeSkill(STATUS_LIST& m_SubjectChara);
private:
	static const int m_max_heel; //! �񕜒l�̍ő�
	static const int m_min_heel; //! �񕜒l�̍ŏ�
};