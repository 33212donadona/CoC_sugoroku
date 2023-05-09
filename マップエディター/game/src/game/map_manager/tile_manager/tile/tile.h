#pragma once
#include "aqua.h"

class ITile :
	public aqua::IGameObject
{
public:
	ITile(aqua::IGameObject* parent,std::string name);
	~ITile() = default;

	/*!
	 *   @brief  初期化
	 * 
	 *   @param[in] position 座標
	 */
	virtual void Initialize(aqua::CVector2 position);

	/*!
	 *   @brief  初期化
	 * 
	 *   @param[in] block_name 画像名
	 *   @param[in] position   座標
	 */
	virtual void Initialize(std::string block_name,aqua::CVector2 position);

	/*!
	 *   @brief  更新
	 */
	virtual void Update()override;

	/*!
	 *   @brief  描画
	 */
	virtual void Draw()override;

	/*!
	 *   @brief  解放
	 */
	virtual void Finalize()override;

	/*!
	 *   @brief  タイル座標の加減
	 */
	void SetPosition(aqua::CVector2& move);

	/*!
	 *   @brief  タイル座標の取得
	 * 
	 *   @return タイル座標
	 */
	aqua::CVector2 GetPosition();

	/*!
	 *   @brief  タイル中心座標の取得
	 *
	 *   @return タイル中心座標
	 */
	aqua::CVector2* GetCenterPosition();

	/*!
	 *   @brief  進めるタイル番号を設定
	 * 
	 *   @param[in] vector_num       配列番号
	 *   @param[in] next_tile_number タイル番号
	 */
	void SetNextTileID(int vector_num,ITile* next_tile_number);

	/*!
	 *   @brief  タイル番号を設定
	 * 
	 *   @param[in] tile_number タイル番号
	 */
	void SetTileID(int tile_number);

	/*!
	 *   @brief  自分のタイル番号を取得
	 * 
	 *   @return タイル番号
	 */
	int* GetNowTileID();

	/*!
	 *   @brief  進めるタイルの最大値を取得
	 * 
	 *   @return 進めるタイルの最大値
	 */
	int GetMaxNextTileSize();

	/*!
	 *   @brief  次に進めるタイル番号
	 * 
	 *   @param[in] vector_num 配列番号
	 * 
	 *   @return 次に進めるタイル番号
	 */
	int* GetNextTileID(int vector_num);

	/*!
	 *   @brief  生成されたタイル番号
	 */
	static int m_tile_num;

	/*!
	 *   @brief  引数との衝突判定
	 * 
	 *   @param[in] position 座標
	 * 
	 *   @return 引数との衝突判定
	 *   @retval true  入っている
	 *   @retval false 入っていない
	 */
	bool CheckOnTile(aqua::CVector2& position);

	/*!
	 *   @brief  画像の大きさを取得
	 * 
	 *   @return 画像の大きさ
	 */
	aqua::CVector2 GetTileSize();

private:

	static const float m_out_of_range;   //! 衝突判定の許容範囲

	int m_NowID;                         //! 自分のタイル番号

	std::vector<ITile*> m_NextTile;      //! 次に進めるタイル番号

	aqua::CSprite m_TileSprite;          //! タイルの画像

	aqua::CVector2 m_TileHalfSize;       //! タイルの半分の大きさ

	aqua::CVector2 m_CenterPosition;     //! タイルの中心座標

};