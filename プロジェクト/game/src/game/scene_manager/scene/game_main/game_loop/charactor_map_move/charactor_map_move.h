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
	*  @brief コンストラクタ
	*/
	CCharactorMapMove(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CCharactorMapMove() = default;

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

	/*!
	 *  @brief プレイヤーIDの設定 
	 */
	void SetPlayerID(PLAYER_ID id);

	/*!
	 *  @brief プレイヤーの座標更新 
	 */
	void SetPlayerPosition(int tile_id);

private:

	CTileManager* m_TileManager;

	CMainGameWork* m_MainGameWork;

	CCommonData*   m_CommonData;

	PLAYER_ID      m_PlayerID;

	aqua::CSprite  m_PlayerIcom[(int)PLAYER_ID::DUMMY];
};