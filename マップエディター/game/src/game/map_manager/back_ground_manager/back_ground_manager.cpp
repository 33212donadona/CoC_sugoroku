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

void CBackGroundManager::SaveSprite()
{
	if (m_BackGroundSprite.GetResourceHandle() == -1)return;

	int min_buffer = 0;

	for (int i = MAX_PATH; i > 0; i--)
	{
		if (buffer[i] == '\\')
		{
			min_buffer = i + 1;
			break;
		}
	}

	std::string m_buffer;
	bool        not_file = false;

	for (int i = min_buffer; i < MAX_PATH; i++)
		m_buffer += buffer[i];

	m_buffer = m_DirectyoryName + "\\" + m_buffer;

	for (const auto& f_it : file_sys::directory_iterator(m_DirectyoryName + "\\"))
	{
		if (f_it.path() == m_buffer)
			not_file = true;
	}

	if (not_file)
		file_sys::copy_file(buffer, m_buffer);
}
