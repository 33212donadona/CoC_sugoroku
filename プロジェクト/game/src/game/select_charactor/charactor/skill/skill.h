#pragma once
#include "aqua.h"
#include "../charactor_id.h"

class ISkill
	:aqua::IGameObject
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	ISkill(aqua::IGameObject* parent,std::string name);

	/*!
	 *  @brief デストラクタ
	 */
	~ISkill() = default;

	/*!
	*   @brief 初期化
	*/
	virtual void Update()override {};

	/*!
	*   @brief 解放
	*/
	virtual void Finalize()override {};

	/*!
	 *  @brief スキルの発動
	 */
	virtual void InvokeSkill(STATUS& m_MyChara, STATUS& m_SubjectChara) {};

	/*!
	 *  @brief スキルの発動
	 */
	virtual void InvokeSkill(STATUS& m_MyChara) {};

	/*!
	 *  @brief スキルの発動
	 */
	virtual void InvokeSkill(STATUS_LIST& m_SubjectChara) {};

	/*!
	 *  @brief スキルの発動
	 */
	virtual void InvokeSkill(STATUS& m_MyChara,STATUS_LIST& m_SubjectChara) {};
};