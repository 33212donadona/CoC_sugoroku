#pragma once
#include "aqua.h"
#include "turn_id.h"
#include "../../../../../../../select_charactor/charactor/charactor_id.h"

class CCommonData;

class CTurn
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief コンストラクタ
	*/
	CTurn(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CTurn() = default;

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

	void SelectCommand();

private:
	static const int            m_menu_font_size;
	static const float          m_box_thickness;
	static const unsigned char  m_box_alpha;
	static const aqua::CVector2 m_player_box_pos;
	static const std::string    m_menu_name[(int)MENU_ID::MAX];

	aqua::CSprite m_BackGround;

	aqua::CBoxPrimitive m_PlayerBox[(int)PLAYER_ID::DUMMY];
	aqua::CBoxPrimitive m_SelectBox;

	aqua::CLabel  m_MenuLabel[(int)MENU_ID::MAX];

	CCommonData*  m_CommonData;

	std::vector<STATUS*> m_Player;

	STATUS*		  m_Status;      // 対象のステータス
	STATUS_LIST*  m_StatusLIST;  // 対象の全体ステータス

	TURN_ID       m_NowTurnID;
	MENU_ID       m_NowMenuID;

	int m_TurnNum;

	int m_MaxTurn;

	bool m_ChangeTurn;
};