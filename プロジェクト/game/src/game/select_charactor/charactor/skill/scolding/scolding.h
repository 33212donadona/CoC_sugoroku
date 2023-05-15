#pragma once
#include "../skill.h"
class CScolding
	:ISkill
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CScolding(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CScolding() = default;

	/*!
	 *   @brief 初期化
	 */
	void Update()override;

	/*!
	*   @brief 解放
	*/
	void Finalize()override;

	/*!
	 *  @brief スキルの発動
	 */
	void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara);

private:
	static const int m_strength_up;
	STATUS* m_MyStatus;
};