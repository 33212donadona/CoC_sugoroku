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
	void SaveTile(std::string* back_ground);

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

	std::ofstream             m_TileDataText;            //! タイル保存ファイル変数 

	std::string               m_TileDataTextName;        //! タイル保存ファイル名

	std::list<ITile*>         m_TileList;	             //! タイルクラスのリスト
	std::list<ITile*>         m_TileMenu;	             //! メニュータイルクラスのリスト
	std::list<CLine*>         m_LineList;	             //! ラインクラスのリスト
	std::list<ITile*>::iterator::value_type m_FromTile;  //! ラインの始点

	CLine*                    m_LineClass;               //! ラインクラス

	std::vector<bool>         m_MoveFlag;                //! タイルクラスの移動フラグ

	aqua::CBoxPrimitive       m_MenuBox;                 //! メニューボックス
	aqua::CLabel              m_MenuLabel;               //! メニューラベル

	int                       m_SelectTileID;            //! 操作したいタイル番号
	int                       m_TileTextFileMax;         //! タイル保存ファイルの個数

};