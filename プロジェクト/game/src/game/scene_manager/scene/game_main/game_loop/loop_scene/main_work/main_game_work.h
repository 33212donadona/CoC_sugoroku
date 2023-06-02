#pragma once
#include "aqua.h"

enum class PLAYER_ID;
struct STATUS;

class CCharactorMapMove;
class CGameCommand;
class CCommonData;
class CStage;

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


	PLAYER_ID GetNowPlayerID();

private:

	/*
	 *  @brief  キャラクターのステータス更新
	 */
	void CharaStatusUpdate();

	/*
	 *  @brief  キャラクターのステータス描画を設定
	 */
	void SetUpStatus();

private:
	
	static const aqua::CPoint m_text_box_space;      //! キャラクターアイコンの座標
	static const int          m_font_size;           //! キャラクターアイコンの座標

	CCommonData*              m_CommonData;          //! 共有データクラス
	STATUS*                   m_Status;
	CGameCommand*             m_GameCommand;
	CCharactorMapMove*        m_CharactorMapMove;

	aqua::CLabel              m_LabelHP	;               //! HPラベル
	aqua::CLabel              m_LabelSTR;               //! STRラベル
	aqua::CLabel              m_LabelDEX;               //! DEXラベル

	aqua::CSprite             m_TextBoxSprite;	        //! テキストボックス画像

	PLAYER_ID                 m_NowPlayerID;		    //! 操作中のプレイヤーID
};