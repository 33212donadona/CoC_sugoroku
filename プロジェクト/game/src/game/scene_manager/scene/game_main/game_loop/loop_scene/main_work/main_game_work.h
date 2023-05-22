#pragma once
#include "aqua.h"

class CCommonData;
class CCharactorInfo;

class CMainGameWork
	:public aqua::IGameObject
{
public:
	/*!
	*  @brief コンストラクタ
	*/
	CMainGameWork(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CMainGameWork() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize()override;

	/*!
	 *  @brief 更新
	 */
	void Update()override;

	/*!
	 *  @brief 描画
	 */
	void Draw()override;

	/*!
	 *  @brief 解放
	 */
	void Finalize()override;

private:

	CCommonData* m_CommonData;

	std::vector<CCharactorInfo>  m_CharaList;

	aqua::CSprite  m_TextBoxSprite;

};