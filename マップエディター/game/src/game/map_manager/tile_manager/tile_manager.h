#pragma once
#include "aqua.h"
#include "tile/tile.h"
#include "line/line.h"
#include <fstream>

enum class TILE_ID
{
	NORMAL,
	IVENT,

	MAX
};

class CTileManager:
	public aqua::IGameObject
{
public:

	CTileManager(aqua::IGameObject* parent);
	~CTileManager() = default;

	/*
	 * @brief 初期化
	 */
	void Initialize()override;

	/*
	 * @brief 更新
	 */
	void Update()override;

	/*
	 * @brief 描画
	 */
	void Draw()override;

	/*
	 * @brief 解放
	 */
	void Finalize()override;

	/*
	 * @brief タイル生成
	 */
	void CreateTile(TILE_ID tile_id,aqua::CVector2 position);

	/*
	 * @brief タイルの保存
	 */
	void SaveTile();

private:

	/*
	 * @brief テキストに書き込む
	 * 
	 * @param[in] w  文字列
	 */
	void WritingText(std::string w);

	/*
	 * @brief テキストの改行
	 */
	void WritingTextCollEnd();

	/*
	 * @brief タイルのカーソル移動
	 */
	void MoveTile();

	/*
	 * @brief タイルを押したらタイルを生成
	 */
	void SampleTile();

	/*
	 * @brief タイルを消す
	 */
	void DeleteTile();

	/*
	 * @brief タイルに道を引く 
	 */
	void CreateLine();

private:
	static const float        m_menu_space;              //! メニューのスペース
	static const int          m_menu_font_size;          //! メニュー文字の太さ

	std::ofstream             m_TileDataText;            //! 

	std::list<ITile*>         m_TileList;	             //! 
	std::list<ITile*>         m_TileMenu;	             //! 
	std::list<CLine*>         m_LineList;	             //! 
	std::list<ITile*>::iterator::value_type m_FromTile;  //! 

	CLine*                    m_LineClass;               //! 

	std::vector<bool>         m_MoveFlag;                //! 

	aqua::CBoxPrimitive       m_MenuBox;                 //! メニューボックス
	aqua::CLabel              m_MenuLabel;               //! メニューラベル

	int                       m_SelectTileID;            //! 

};