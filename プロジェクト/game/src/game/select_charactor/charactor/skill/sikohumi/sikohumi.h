#pragma once
#include "../skill.h"
class CSikohumi
	:ISkill
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CSikohumi(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CSikohumi() = default;

	/*!
	 *   @brief 初期化
	 */
	void Update()override;

	/*!
	*   @brief 解放
	*/
	void Finalize()override {};

	/*!
	 *  @brief スキルの発動
	 */
	void InvokeSkill(STATUS& m_MyChara, STATUS_LIST& m_SubjectChara);

};