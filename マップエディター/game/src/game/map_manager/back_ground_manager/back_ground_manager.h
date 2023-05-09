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
	 *  @retval     true    保存成功
     *  @retval     false   保存失敗またはすでに存在している
	 */
	bool SaveSprite();

	/*
	 *  @brief 画像のパス
	 * 
	 *  @return 画像のパス
	 */
	std::string GetSpritePath();

private:

	/*
	 *  @brief ドラックアンドドロップで画像読み込み
	 */
	void DropSprite();

private:

	static const std::string m_DirectyoryName;

	char buffer[MAX_PATH];
	std::string m_FilePath;

	aqua::CSprite m_BackGroundSprite;

	aqua::CLabel  m_BackGroundFile;
	aqua::CLabel  m_FileNum;
	aqua::CLabel  m_ExePath;

	int m_DropSpiteNum;

};