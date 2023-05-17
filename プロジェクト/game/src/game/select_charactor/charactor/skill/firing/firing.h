#pragma once
#include "../skill.h"
class CFiring
	:public ISkill
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CFiring(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CFiring() = default;

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
	static const float m_firing_damage_rate;
};