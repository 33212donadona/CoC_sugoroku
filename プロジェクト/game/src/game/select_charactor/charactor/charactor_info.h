#pragma once
#include "aqua.h"
#include "charactor_id.h"
#include "skill/skill.h"

class CCharactorInfo
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CCharactorInfo(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CCharactorInfo() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize(std::string file_name, std::string text_file_name, JOB_ID job_id, SKILL_ID skill_id, STATUS status);
	
	/*!
	 *  @brief 描画
	 */
	void Update()override;

	/*!
	 *  @brief 描画
	 */
	void Draw()override;

	/*!
	 *  @brief 描画
	 */
	void TextBoxCharaDraw();

	/*!
	 *  @brief 解放
	 */
	void Finalize()override;

	/*!
	 *  @brief ステータスのポインタ取得
	 */
	STATUS* GetStatus();

	/*!
	 *  @brief スキルの発動
	 */
	void  InvokeSkill(STATUS& m_SubjectChara);

	/*!
	 *  @brief スキルの発動
	 */
	void  InvokeSkill(STATUS_LIST& m_SubjectChara);

	/*
	 *  @brief 画像サイズの取得
	 */
	aqua::CVector2 GetSpriteSize();

	aqua::CVector2 m_Position;
	aqua::CVector2 m_Scale;

private:

	/*!
	 *  @brief スキルの設定
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