#pragma once
#include "aqua.h"
#include "../select_charactor/charactor/charactor_id.h"

class CCharactorInfo;

class CCommonData
	:public aqua::IGameObject
{
public:
	/*!
	*  @brief �R���X�g���N�^
	*/
	CCommonData(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CCommonData() = default;

	/*!
	*  @brief ���
	*/
	void Finalize()override;

	void PushBack_Chara(CCharactorInfo info);

	void EraseBackChara();

	bool EmptyChara();

	CCharactorInfo* RefarenceChara(PLAYER_ID player_id);

private:

	std::vector<CCharactorInfo>  m_CharaList;

};