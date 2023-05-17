#pragma once
#include "../skill.h"
class CEmergencySurgery
	:public ISkill
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
	void InvokeSkill(STATUS& m_SubjectChara);

private:
	static const int m_max_heel; //! 回復値の最大
	static const int m_min_heel; //! 回復値の最小

};