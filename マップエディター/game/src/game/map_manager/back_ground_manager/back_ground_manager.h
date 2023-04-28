#pragma once
#include "aqua.h"


class CBackGroundManager :
	public aqua::IGameObject
{
public:

	CBackGroundManager(aqua::IGameObject* parent);
	~CBackGroundManager() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

	/*
	 *  @brief 画像の保存
	 * 
	 *  @return 保存の成功
	 *  @retval     true    保存成功
     *  @retval     false   保存失敗またはすでに存在している
	 */
	bool SaveSprite();

	/*
	 *  @brief 背景のファイル名のポインタ 
	 */
	std::string* GetBackGround();

private:

	/*
	 *  @brief ドラックアンドドロップで画像読み込み
	 */
	void DropSprite();

private:

	static const std::string m_directyory_name;
	static const int         m_drop_file_label_size;

	char buffer[MAX_PATH];

	std::string m_BackGround;

	aqua::CSprite m_BackGroundSprite;

	aqua::CLabel  m_BackGroundFile;
	aqua::CLabel  m_FileNum;

	aqua::CLabel  m_DropFileLabel;

	int m_DropSpiteNum;

};