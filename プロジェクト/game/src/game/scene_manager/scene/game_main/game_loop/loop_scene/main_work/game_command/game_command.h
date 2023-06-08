#pragma once
#include "aqua.h"

enum class CommandID
{
	DICE,
	TEAM,

	MAX
};

class CDice;
class CCharactorMapMove;
class CTileManager;
class CSelectTileText;

enum class PLAYER_ID;

class CGameCommand
	:public aqua::IGameObject
{
public:

	/*!
	 *  @brief コンストラクタ
	 */
	CGameCommand(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CGameCommand() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize(aqua::CVector2 position);

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
	 *  @brief 
	 */
	void SetPlayerID(PLAYER_ID id);

private:

	/*
	 *  @brief コマンドを選ぶ 
	 */
	void SelectCommand();

	/*
	 *  @brief サイコロのコマンド 
	 */
	void DiceCommand();

	/*
	 *  @brief チームを組むコマンド 
	 */
	void TeamCommand();

private:
	static const std::string m_CommandName[(int)CommandID::MAX];
	
	std::vector<aqua::CLabel> m_CommandLabel;

	CommandID    m_NowSelectCommand;

	bool m_UpdateCommand;

	CDice* m_DiceClass;                       //! 
	CCharactorMapMove* m_CharactorMapMove;    //! 
	CTileManager*      m_TileManager;         //! 
	std::vector<CSelectTileText*> m_SelectTextVector;
	
	PLAYER_ID m_PlayerID;

	int m_MoveTile;
	int m_MaxFromTile;
	int m_SelectFromTile;
};