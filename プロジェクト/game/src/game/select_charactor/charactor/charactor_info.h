#pragma once
#include "aqua.h"
#include "charactor_id.h"

class CCharactorInfo
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CCharactorInfo(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CCharactorInfo() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize(std::string file_name, JOB_ID job_id, SKILL_ID skill_id, STATUS status)
	{
		m_CharactorSprite.Create(file_name);
		m_JobID = job_id;
		m_SkillID = skill_id;
		m_Status = status;
	};

	/*!
	 *  @brief �`��
	 */
	void Draw()override;

	/*!
	 *  @brief ���
	 */
	void Finalize()override;

	/*
	 *
	 */
	STATUS* GetStatus();

private:

	STATUS m_Status;

	aqua::CSprite m_CharactorSprite;

	JOB_ID  m_JobID;

	SKILL_ID m_SkillID;

};