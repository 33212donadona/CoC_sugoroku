#include "charactor_info.h"
#include "skill/skill_channel.h"

CCharactorInfo::CCharactorInfo(aqua::IGameObject* parent)
	:m_SkillClass(nullptr)
{
}

void CCharactorInfo::Initialize(std::string file_name, std::string text_file_name, JOB_ID job_id, SKILL_ID skill_id, STATUS status)
{
	m_CharactorSprite.Create(file_name);
	m_CharactorSpriteText.Create(text_file_name);
	m_JobID = job_id;
	m_SkillID = skill_id;
	SkillSelect(m_SkillID);
	m_Status = status;
}

void CCharactorInfo::Update()
{
	m_CharactorSprite.position = m_Position;
	m_CharactorSpriteText.position = m_Position;
	m_CharactorSprite.scale = m_Scale;
}

void CCharactorInfo::Draw()
{
	m_CharactorSprite.Draw();
}

void CCharactorInfo::TextBoxCharaDraw()
{
	m_CharactorSpriteText.Draw();
}

void CCharactorInfo::Finalize()
{
	m_CharactorSprite.Delete();
	m_CharactorSpriteText.Delete();
	if(m_SkillClass)m_SkillClass->Finalize();
	aqua::IGameObject::Finalize();
}

STATUS* CCharactorInfo::GetStatus()
{
	return &m_Status;
}

void CCharactorInfo::InvokeSkill(STATUS& m_SubjectChara)
{
	if (!m_SkillClass)return;

	m_SkillClass = nullptr;

	switch (m_SkillID)
	{
	case SKILL_ID::FIRING:
	case SKILL_ID::SCOLDING:
	case SKILL_ID::STEEL_MUSCLE:

		m_SkillClass->InvokeSkill(m_Status,m_SubjectChara);

		break;
	case SKILL_ID::EMERGENCY_SURGERY:

		m_SkillClass->InvokeSkill(m_SubjectChara);

		break;
	}
}

void CCharactorInfo::InvokeSkill(STATUS_LIST& m_SubjectChara)
{
	if (!m_SkillClass)return;

	switch (m_SkillID)
	{
	case SKILL_ID::FINALE:
	case SKILL_ID::QUIBBLE:
	case SKILL_ID::DOSE:

		m_SkillClass->InvokeSkill(m_SubjectChara);

		break;
	case SKILL_ID::SIKOHUMI:

		m_SkillClass->InvokeSkill(m_Status, m_SubjectChara);

		break;
	}
}

aqua::CVector2 CCharactorInfo::GetSpriteSize()
{
	return aqua::CVector2(m_CharactorSprite.GetTextureWidth(), m_CharactorSprite.GetTextureHeight()) * m_Scale;
}

void CCharactorInfo::SkillSelect(SKILL_ID id)
{
	m_SkillClass = nullptr;

	switch (id)
	{
	case SKILL_ID::FIRING:

		m_SkillClass = (ISkill*)aqua::CreateGameObject<CFiring>(this);

		break;
	case SKILL_ID::SCOLDING:

		m_SkillClass = (ISkill*)aqua::CreateGameObject<CScolding>(this);

		break;
	case SKILL_ID::STEEL_MUSCLE:

		m_SkillClass = (ISkill*)aqua::CreateGameObject<CSteelMuscle>(this);

		break;
	case SKILL_ID::SIKOHUMI:

		m_SkillClass = (ISkill*)aqua::CreateGameObject<CSikohumi>(this);

		break;
	case SKILL_ID::FINALE:

		m_SkillClass = (ISkill*)aqua::CreateGameObject<CFinale>(this);

		break;
	case SKILL_ID::QUIBBLE:

		m_SkillClass = (ISkill*)aqua::CreateGameObject<CQuibble>(this);

		break;
	case SKILL_ID::EMERGENCY_SURGERY:

		m_SkillClass = (ISkill*)aqua::CreateGameObject<CEmergencySurgery>(this);

		break;
	case SKILL_ID::DOSE:

		m_SkillClass = (ISkill*)aqua::CreateGameObject<CDose>(this);

		break;
	}
}

