#pragma once
#include "aqua.h"
#include "../../../../../select_charactor/charactor/charactor_id.h"

class CTileManager;
class CMainGameWork;
class CCommonData;

class CCharactorMapMove
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief �R���X�g���N�^
	*/
	CCharactorMapMove(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CCharactorMapMove() = default;

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

	/*!
	 *  @brief �v���C���[ID�̐ݒ� 
	 */
	void SetPlayerID(PLAYER_ID id);

	/*!
	 *  @brief �v���C���[�̍��W�X�V 
	 */
	void SetPlayerPosition(int tile_id);

private:

	CTileManager* m_TileManager;

	CMainGameWork* m_MainGameWork;

	CCommonData*   m_CommonData;

	PLAYER_ID      m_PlayerID;

	aqua::CSprite  m_PlayerIcom[(int)PLAYER_ID::DUMMY];
};