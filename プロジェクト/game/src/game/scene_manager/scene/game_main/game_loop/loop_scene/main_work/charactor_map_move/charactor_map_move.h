#pragma once
#include "aqua.h"
#include "../../../../../../../select_charactor/charactor/charactor_id.h"
#include "../game_command/dice/dice_info.h"

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
	 *  @brief �v���C���[�̗����Ă���^�C��ID
	 */
	int GetPlayerTileID(PLAYER_ID id);

	/*!
	 *  @brief �v���C���[�̍��W�X�V 
	 */
	bool SetPlayerTileID(int tile_id);

	/*!
	 *  @brief �^�C���̈ړ���̐� 
	 */
	int GetFromTileSize(int tile_id);

private:
	static const float m_max_easing_time;

	CTileManager* m_TileManager;

	CMainGameWork* m_MainGameWork;

	CCommonData*   m_CommonData;

	PLAYER_ID      m_PlayerID;

	aqua::CSprite  m_PlayerIcom[(int)PLAYER_ID::DUMMY];

	int            m_PlayerTileID[(int)PLAYER_ID::DUMMY];

	aqua::CVector2 m_Position[(int)PLAYER_ID::DUMMY];
	aqua::CVector2 m_FromPosition[(int)PLAYER_ID::DUMMY];

	aqua::CTimer   m_EasingTime[(int)PLAYER_ID::DUMMY];
};