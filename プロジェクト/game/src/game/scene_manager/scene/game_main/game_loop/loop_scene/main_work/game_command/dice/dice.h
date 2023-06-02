#pragma once
#include "aqua.h"
#include "dice_info.h"


class CCharactorMapMove;

class CDice
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CDice(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CDice() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize();

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
	 *  @brief 出たサイコロの目を取得 
	 */
	int GetDice();

private:

	/*
	 *  @brief サイコロの順番を再設置
	 */
	void SetUpDice();

private:
	static const int m_aftertaste_max_count;
	static const int m_rand_dice[dice::rand_pattern][dice::max_dice];
	static const float m_change_dice_time;
	static const float m_add_dice_time;
	static const float m_emphasis_dice_time;
	static const float m_emphasis_dice_max_size;
	static const float m_emphasis_dice_min_size;

	aqua::CSprite               m_DiceSprite[dice::max_dice];      //! サイコロ一面ずつの画像
	std::vector<aqua::CSprite*> m_DrawDiceSprite;

	aqua::CBoxPrimitive       m_BackGround;

	aqua::CTimer  m_ChangeDiceTimer;
	aqua::CTimer  m_EmphasisDiceTimer;     // 出た出目の強調

	bool m_ReturnDice;

	int  m_DiceNumber;
	int  m_DiceAftertasteCount;
};