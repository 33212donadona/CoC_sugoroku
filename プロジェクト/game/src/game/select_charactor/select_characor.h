#pragma once
#include "aqua.h"
#include "charactor/charactor_id.h"

class CCharactorInfo;
class CParameter;

using CHARACTOR_VECTOR = std::vector<CCharactorInfo>;

class CSelectCharactor
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief コンストラクタ
	 */
	CSelectCharactor(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CSelectCharactor() = default;

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

	void SelectCharactor();

	void DecideCharactor();

private:

	static const float          m_box_thickness;                     //  ボックスの線の太さ
	static const unsigned int   m_box_color[(int)PLAYER_ID::DUMMY];  //  ボックスの線の色
												        
	std::vector<CCharactorInfo*> m_Charactor;                        //　キャラクターリスト
	CHARACTOR_VECTOR             m_SelectChara;                      //  選んだキャラクター
	std::vector<CParameter*>     m_Parameter;                        //　パラメーターリスト
	std::vector<aqua::CSprite>   m_CharactorSpriteList;              //  キャラクター画像リスト

	aqua::CSprite              m_BackgroudSprite;                    //  背景


	aqua::CBoxPrimitive        m_SelectBox;                          //  選択中の枠
	aqua::CBoxPrimitive        m_SelectBlendBox;                     //  選択中の箱

	PLAYER_ID                  m_NowSelectPlayer;                    //  操作しているプレイヤー
	
	int                        m_CharactorMaxNum;

	int                        m_SelectCharactor;
};