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
	 */
	void SaveSprite();

private:

	/*
	 *  @brief ドラックアンドドロップで画像読み込み
	 */
	void DropSprite();

private:

	static const std::string m_DirectyoryName;

	char buffer[MAX_PATH];

	aqua::CSprite m_BackGroundSprite;

	aqua::CLabel  m_BackGroundFile;
	aqua::CLabel  m_FileNum;
	aqua::CLabel  m_ExePath;

	int m_DropSpiteNum;

};