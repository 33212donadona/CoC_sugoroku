#pragma once
#include "../skill.h"
class CFinale
	:ISkill
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
	void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara);

};