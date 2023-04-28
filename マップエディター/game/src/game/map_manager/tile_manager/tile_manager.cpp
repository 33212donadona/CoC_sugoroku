#include "tile_manager.h"
#include "tile/normal_tile/normal_tile.h"
#include "tile/ivent_tile/ivent_tile.h"

#include <filesystem>


namespace fs = std::filesystem;

const float CTileManager::m_menu_space = 20.0f;
const int   CTileManager::m_menu_font_size = 40;

CTileManager::CTileManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "TileManager")
	, m_SelectTileID(0)
	, m_TileTextFileMax(0)
	, m_LineClass(nullptr)
	, m_FromTile(nullptr)
{

}

/*
 * 初期化
 */
void CTileManager::Initialize()
{
	// メニュータイルの宣言
	m_TileMenu.push_back(aqua::CreateGameObject<CNormalTile>(this));
	m_TileMenu.push_back(aqua::CreateGameObject<CIventTile>(this));

	m_MenuBox.Setup
	(
		aqua::CVector2::ZERO,
		100.0f,
		300.0f,
		0xff4f4f4f
	);

	m_MenuLabel.Create(m_menu_font_size);

	// メニューの初期化
	int i = 0;
	const int menu_size = (int)m_TileMenu.size();

	aqua::CVector2 pos;
	for (auto& it : m_TileMenu)
	{
		pos = aqua::GetWindowSize();

		it->Initialize(pos);

		pos.x -= it->GetTileSize().x;
		pos.y = pos.y / 2.0f + (i * menu_size - menu_size / 2) * it->GetTileSize().y;

		it->SetPosition(pos);

		// メニューボックス
		m_MenuBox.width = aqua::GetWindowSize().x - it->GetPosition().x;
		m_MenuBox.height = it->GetTileSize().y * 3.0f;

		i++;
	}

	m_MenuBox.position.x = aqua::GetWindowSize().x - m_MenuBox.width;
	m_MenuBox.position.y = (aqua::GetWindowSize().y - m_MenuBox.height) / 2.0f;
	m_MenuBox.position -= aqua::CVector2::ONE * m_menu_space;

	m_MenuBox.width += m_menu_space;
	m_MenuBox.height += m_menu_space;

	// メニューラベル
	m_MenuLabel.text = "メニュー欄";
	m_MenuLabel.position.x = float(aqua::GetWindowWidth() - m_MenuLabel.GetTextWidth());
	m_MenuLabel.position.y = m_MenuBox.position.y - m_MenuLabel.GetFontHeight();

	// 初めに三つ出す
	CreateTile(TILE_ID::NORMAL, aqua::CVector2::ONE * 500);
	CreateTile(TILE_ID::NORMAL, aqua::CVector2::ONE * 600);
	CreateTile(TILE_ID::NORMAL, aqua::CVector2::ONE * 650);

}

/*
 * 更新
 */
void CTileManager::Update()
{
	MoveTile();

	SampleTile();

	DeleteTile();

	CreateLine();

	IGameObject::Update();
}

/*
 * 描画
 */
void CTileManager::Draw()
{
	m_MenuBox.Draw();

	IGameObject::Draw();

	m_MenuLabel.Draw();

	CLine::ArrowDraw();
}

/*
 * 解放
 */
void CTileManager::Finalize()
{
	m_MenuLabel.Delete();
	IGameObject::Finalize();
}

/*
 * タイル生成
 */
void CTileManager::CreateTile(TILE_ID tile_id, aqua::CVector2 position)
{
	ITile* tile_object = nullptr;

	switch (tile_id)
	{
	case TILE_ID::NORMAL:
		tile_object = aqua::CreateGameObject<CNormalTile>(this);
		break;
	case TILE_ID::IVENT:
		tile_object = aqua::CreateGameObject<CIventTile>(this);
		break;
	}

	if (tile_object)
	{
		tile_object->Initialize(position);

		m_TileList.push_back(tile_object);
		m_MoveFlag.push_back(false);
	}
}

/*
 * タイル情報を書き込む
 */
void CTileManager::SaveTile(std::string* back_ground)
{
	bool file_exists = true;
	std::error_code ec;

	// 保存先の既存ファイルを確認
	do
	{
		m_TileDataTextName = "map_data\\tile_data_" + std::to_string(m_TileTextFileMax) + ".txt";
		file_exists = fs::exists(m_TileDataTextName, ec);

		++m_TileTextFileMax;

	} while (file_exists);

	int j = 1;

	for (auto& it : m_TileList)
	{
		it->SetTileID(j);

		++j;
	}

	m_TileDataText.open(m_TileDataTextName, std::ios::out);

	int count_tiles = 0;

	WritingText(*back_ground);
	WritingTextCollEnd();

	for (auto& i : m_TileList)
	{
		// 書き込み
		WritingText(std::to_string(i->GetNowTileID()));

		WritingText(i->GetGameObjectName());

		WritingText(std::to_string(i->GetPosition().x));
		WritingText(std::to_string(i->GetPosition().y));
		WritingText(std::to_string(i->GetPosition().x));

		int max = i->GetMaxNextTileSize();

		for (int wt_i = 0; wt_i < max; wt_i++)
			WritingText(std::to_string(i->GetNextTileID(wt_i)));

		WritingTextCollEnd();

		count_tiles++;
	}

	m_TileDataText.close();
}

/*
 * テキストに書き込む
 */
void CTileManager::WritingText(std::string w)
{
	m_TileDataText << w << ",";
}

/*
 * テキストの改行
 */
void CTileManager::WritingTextCollEnd()
{
	m_TileDataText << "\n";

}

/*
 *  タイルのカーソル移動
 */
void CTileManager::MoveTile()
{
	// マウス座標
	aqua::CVector2 pos = aqua::mouse::GetCursorPos();

	int i = 0;

	// 生成順から判断
	for (auto& it : m_TileList)
	{

		if (it->CheckOnTile(pos) && aqua::mouse::Button(aqua::mouse::BUTTON_ID::LEFT) && !m_MoveFlag[i] && m_SelectTileID == 0)
		{
			m_SelectTileID = i;
			m_MoveFlag[m_SelectTileID] = true;
		}

		if (m_MoveFlag[m_SelectTileID] && m_SelectTileID == i)
		{
			it->SetPosition(pos);
			break;
		}

		i++;
	}

	// 押すのを辞めたらリセット
	if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
	{
		m_MoveFlag[m_SelectTileID] = false;
		m_SelectTileID = 0;
	}
}

/*
 * タイルを押したらタイルを生成
 */
void CTileManager::SampleTile()
{
	aqua::CVector2 pos = aqua::mouse::GetCursorPos();

	int i = 0;

	for (auto& it : m_TileMenu)
	{
		if (it->CheckOnTile(pos) && aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
			CreateTile((TILE_ID)i, aqua::GetWindowSize() / 2.0f);

		i++;
	}
}

/*
 * タイルを消す
 */
void CTileManager::DeleteTile()
{
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::RIGHT))
	{
		aqua::CVector2 pos = aqua::mouse::GetCursorPos();

		int ID = -1;

		std::list<ITile*>::iterator tile_it = m_TileList.begin();
		std::list<ITile*>::iterator tile_end = m_TileList.end();

		// タイルを削除
		while (tile_it != tile_end)
		{
			if ((*tile_it)->CheckOnTile(pos))
			{
				ID = (*tile_it)->GetNowTileID();

				(*tile_it)->Finalize();

				m_TileList.erase(tile_it);

				break;
			}

			++tile_it;
		}

		tile_it = m_TileList.begin();
		tile_end = m_TileList.end();

		// 削除タイルを参照している別タイルから削除タイルの番号を削除
		while (tile_it != tile_end)
		{
			int max = (*tile_it)->GetMaxNextTileSize();

			for (int tile_i = 0; tile_i < max; tile_i++)
			{
				if ((*tile_it)->GetNextTileID(tile_i) == ID)
				{
					(*tile_it)->SetNextTileID(tile_i, 0);
				}
			}

			++tile_it;

		}

		std::list<CLine*>::iterator	line_it = m_LineList.begin();
		std::list<CLine*>::iterator line_end = m_LineList.end();

		while (line_it != line_end)
		{
			if ((*line_it)->GetLineWayFlag(ID))
			{
				(*line_it)->Finalize();

				m_ChildObjectList.erase(std::find(m_ChildObjectList.begin(), m_ChildObjectList.end(), *line_it));

				line_it = m_LineList.erase(line_it);


			}
			else
				++line_it;
		}
	}
}

/*
 *  タイルに道を引く
 */
void CTileManager::CreateLine()
{
	aqua::CVector2 pos = aqua::mouse::GetCursorPos();

	// ラインクラスを生成と始点の保存
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::MIDDLE))
	{
		for (auto& it : m_TileList)
		{
			if (it->CheckOnTile(pos))
			{
				m_LineClass = aqua::CreateGameObjectF<CLine>(this);

				m_LineClass->Initialize(it->GetCenterPosition());

				m_LineClass->SetLineWay(it->GetNowTileID());

				m_FromTile = it; // イテレーターを保存
			}
		}
	}

	// 終点の保存
	if (m_LineClass)
	{
		m_LineClass->m_TergetPosition = &pos;

		for (auto& it : m_TileList)
		{
			if (it->CheckOnTile(pos))
			{
				m_LineClass->m_TergetPosition = it->GetCenterPosition();

				// ボタンを離したらそこにラインクラスをリストにプッシュバック
				if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::MIDDLE))
				{
					if (!m_LineClass->GetLineWayFlag(it->GetNowTileID()))
					{
						m_LineClass->SetLineWay(it->GetNowTileID());

						if (m_FromTile)
							m_FromTile->SetNextTileID(m_FromTile->GetMaxNextTileSize() + 1, it);

						m_LineList.push_back(m_LineClass);

					}
					else
					{
						m_LineClass->Finalize();

						m_ChildObjectList.erase(std::find(m_ChildObjectList.begin(), m_ChildObjectList.end(), m_LineClass));
					}

					m_FromTile = nullptr;
					m_LineClass = nullptr;
				}

				break;
			}
		}

	}
}