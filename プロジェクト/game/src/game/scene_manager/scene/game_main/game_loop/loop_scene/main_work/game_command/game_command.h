#pragma once
#include "aqua.h"

enum class CommandID
{
	DICE,
	TEAM,

	MAX
};

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
	static const int m_rand_pattern;
	static const int m_max_dice;
	static const int m_rand_dice[2][6];
	static const float m_change_dice_time;

	std::vector<aqua::CLabel> m_CommandLabel;
	
	aqua::CSprite             m_DiceSprite[6];                   //! サイコロ一面ずつの画像
	std::vector<aqua::CSprite*> m_DrawDiceSprite;

	aqua::CTimer  m_ChangeDiceTimer;

	CommandID    m_NowSelectCommand;

	bool m_UpdateCommand;

};
