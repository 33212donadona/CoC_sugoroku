#include "back_ground_manager.h"
#include <filesystem>
#include <fstream>

namespace file_sys = std::filesystem;

const std::string CBackGroundManager::m_DirectyoryName = "map_data";

CBackGroundManager::CBackGroundManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "BackGroundManager")
{
}

void CBackGroundManager::Initialize()
{
	// ディレクトリを生成
	file_sys::create_directory(m_DirectyoryName);

	m_BackGroundFile.Create(20);
	m_FileNum.Create(20);

	m_FileNum.text = "ドラックアンドドロップ : " + std::to_string(0);
}

void CBackGroundManager::Update()
{
	DropSprite();
}

void CBackGroundManager::Draw()
{
	if (m_BackGroundSprite.GetResourceHandle() != -1)
	{

		m_BackGroundSprite.Draw();
		m_BackGroundFile.Draw();

	}

	m_FileNum.Draw();
}

void CBackGroundManager::Finalize()
{
	if (m_BackGroundSprite.GetResourceHandle() != -1)
	{
		m_BackGroundSprite.Delete();
	}

	m_BackGroundFile.Delete();
	m_FileNum.Delete();
}

void CBackGroundManager::DropSprite()
{
	// 左クリックでファイルデータをスプライトに読み込む
	if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
	{
		// ドラックアンドドロップしたファイルの個数（ファイルを読み込んだら0リセット）
		m_DropSpiteNum = GetDragFileNum();

		// ファイル数を文字列に
		m_FileNum.text = "ドラックアンドドロップ : " + std::to_string(m_DropSpiteNum);

		// ドラックアンドドロップしたファイルの絶対パス
		GetDragFilePath(buffer);

		if (m_DropSpiteNum >= 1)
		{
			if (m_BackGroundSprite.GetResourceHandle() != -1)
				m_BackGroundSprite.Delete();

			m_BackGroundFile.text = buffer;

			m_BackGroundFile.position.y = (float)m_FileNum.GetFontHeight();

			m_BackGroundSprite.Create(buffer);
		}

	}
}
/*
 *  画像の保存
 */
bool CBackGroundManager::SaveSprite()
{
	if (m_BackGroundSprite.GetResourceHandle() == -1)return false;

	int file_buffer_num = 0;

	// ファイル名を取得
	for (int i = MAX_PATH; i > 0; i--)
	{
		if (buffer[i] == '\\')
		{
			file_buffer_num = i + 1;
			break;
		}
	}

	m_FilePath = m_DirectyoryName + "\\";

	// コピー先の参照パスを作成
	for (int i = file_buffer_num; i < MAX_PATH; i++)
	{

		if (buffer[i] != '\0') // パスの終端
			m_FilePath += buffer[i];
		else
			break;

	}

	// ファイルが存在しなけれはコピー先に保存する
	if (!file_sys::exists(m_FilePath))
		file_sys::copy_file(buffer, m_FilePath);

	return true;
}

std::string CBackGroundManager::GetSpritePath()
{
	return m_FilePath;
}
