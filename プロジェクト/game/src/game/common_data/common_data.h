#pragma once
#include "aqua.h"
#include "../select_charactor/charactor/charactor_id.h"

class CCharactorInfo;

class CCommonData
	:public aqua::IGameObject
{
public:
	/*!
	*  @brief コンストラクタ
	*/
	CCommonData(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CCommonData() = default;

	/*!
	*  @brief 解放
	*/
	void Finalize()override;

	void PushBack_Chara(CCharactorInfo info);

	void EraseBackChara();

	bool EmptyChara();

	CCharactorInfo* RefarenceChara(PLAYER_ID player_id);

private:

	std::vector<CCharactorInfo>  m_CharaList;

};