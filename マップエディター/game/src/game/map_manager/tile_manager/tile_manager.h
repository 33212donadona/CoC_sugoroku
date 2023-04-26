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

	std::ofstream m_TileDataText;

	std::list<ITile*> m_TileList;
	std::list<ITile*> m_SampleTile;

	std::list<CLine*> m_LineList;
	CLine*            m_LineClass;

	aqua::CLabel label;

	std::vector<bool> m_MoveFlag;

	int m_SelectTileID;

};