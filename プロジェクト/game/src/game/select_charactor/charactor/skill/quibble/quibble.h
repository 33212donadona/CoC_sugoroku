#pragma once
#include "../skill.h"
class CQuibble
	:public ISkill
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CQuibble(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CQuibble() = default;

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
	void InvokeSkill(STATUS_LIST& m_SubjectChara);

private:
	static const int   m_quibble_damage;
	static const float m_quibble_down_rate;


};