#pragma once
#include "../skill.h"
class CFinale
	:public ISkill
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CFinale(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CFinale() = default;

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
	void InvokeSkill( STATUS_LIST& m_SubjectChara);

private:

	static const float m_finale_rate;

};