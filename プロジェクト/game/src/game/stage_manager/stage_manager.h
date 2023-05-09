#pragma once
#include "aqua.h"

class CStage;

class CStageManager
	: public aqua::IGameObject
{
public:
	/*!
	*  @brief コンストラクタ
	*/
	CStageManager(aqua::IGameObject* parent);

	/*!
	*  @brief デストラクタ
	*/
	~CStageManager() = default;

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

	/*!
	*  @brief ステージを生成
	*/
	void CreateStage(int stage_id);
private:

	/*
	*   @brief 存在するファイルの個数を求める
	*/
	void CountExistsFile();

private:

	static const std::string m_tile_data;     //! タイル情報の共通したファイル名
										      
	CStage*                  m_Stage;         //! ステージクラス

	int                      m_ExistsFileNum; //! 存在するファイルの数

	int                      m_SelectFile;    //! 選択したファイル
};