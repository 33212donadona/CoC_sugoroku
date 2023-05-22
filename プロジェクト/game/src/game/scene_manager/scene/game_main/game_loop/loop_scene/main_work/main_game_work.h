#pragma once
#include "aqua.h"

class CCommonData;
class CCharactorInfo;

class CMainGameWork
	:public aqua::IGameObject
{
public:
	/*!
	*  @brief �R���X�g���N�^
	*/
	CMainGameWork(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CMainGameWork() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize()override;

	/*!
	 *  @brief �X�V
	 */
	void Update()override;

	/*!
	 *  @brief �`��
	 */
	void Draw()override;

	/*!
	 *  @brief ���
	 */
	void Finalize()override;

private:

	CCommonData* m_CommonData;

	std::vector<CCharactorInfo>  m_CharaList;

	aqua::CSprite  m_TextBoxSprite;

};