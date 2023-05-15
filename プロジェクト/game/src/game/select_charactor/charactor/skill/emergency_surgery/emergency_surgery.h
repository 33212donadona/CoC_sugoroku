#pragma once
#include "../skill.h"
class CEmergencySurgery
	:ISkill
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CEmergencySurgery(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CEmergencySurgery() = default;

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
};