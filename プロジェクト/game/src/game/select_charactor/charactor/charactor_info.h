#pragma once
#include "aqua.h"
#include "charactor_id.h"
#include "skill/skill.h"

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
	void Initialize(std::string file_name, std::string text_file_name, JOB_ID job_id, SKILL_ID skill_id, STATUS status);
	
	/*!
	 *  @brief �`��
	 */
	void Update()override;

	/*!
	 *  @brief �`��
	 */
	void Draw()override;

	/*!
	 *  @brief �`��
	 */
	void TextBoxCharaDraw();

	/*!
	 *  @brief ���
	 */
	void Finalize()override;

	/*!
	 *  @brief �X�e�[�^�X�̃|�C���^�擾
	 */
	STATUS* GetStatus();

	/*!
	 *  @brief �X�L���̔���
	 */
	void  InvokeSkill(STATUS& m_SubjectChara);

	/*!
	 *  @brief �X�L���̔���
	 */
	void  InvokeSkill(STATUS_LIST& m_SubjectChara);

	/*
	 *  @brief �摜�T�C�Y�̎擾
	 */
	aqua::CVector2 GetSpriteSize();

	aqua::CVector2 m_Position;
	aqua::CVector2 m_Scale;

private:

	/*!
	 *  @brief �X�L���̐ݒ�
	 */
	void SkillSelect(SKILL_ID id);

private:

	STATUS m_Status;

	aqua::CSprite m_CharactorSprite;
	aqua::CSprite m_CharactorSpriteText;

	JOB_ID  m_JobID;

	SKILL_ID m_SkillID;

	ISkill* m_SkillClass;

};