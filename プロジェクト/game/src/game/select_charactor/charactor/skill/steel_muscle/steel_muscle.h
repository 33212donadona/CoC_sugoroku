#pragma once
#include "../skill.h"
class CSteelMuscle
	:public ISkill
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CSteelMuscle(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CSteelMuscle() = default;

	/*!
	 *   @brief 更新
	 */
	void Update()override;

	/*!
	*   @brief 解放
	*/
	void Finalize()override {};

	/*!
	 *  @brief スキルの発動
	 */
	void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara);
};