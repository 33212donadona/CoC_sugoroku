#include "tile_manager.h"
#include "tile/normal_tile/normal_tile.h"
#include "tile/ivent_tile/ivent_tile.h"

#include <filesystem>

namespace fs = std::filesystem;

CTileManager::CTileManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "TileManager")
	, m_SelectTileID(0)
	, m_LineClass(nullptr)
{

}

/*
 * ������
 */
void CTileManager::Initialize()
{
	m_SampleTile.push_back(aqua::CreateGameObject<CNormalTile>(this));
	m_SampleTile.push_back(aqua::CreateGameObject<CIventTile>(this));

	int i = 0;
	for (auto& it : m_SampleTile)
	{
		aqua::CVector2 pos = aqua::GetWindowSize();

		it->Initialize(pos);

		pos.x -= it->GetTileSize().x;
		pos.y = pos.y / 2.0f - (i * 2 - 1) * it->GetTileSize().y;

		it->SetPosition(pos);

		i++;
	}

	CreateTile(TILE_ID::NORMAL, aqua::CVector2::ONE * 500);
	CreateTile(TILE_ID::NORMAL, aqua::CVector2::ONE * 600);
	CreateTile(TILE_ID::NORMAL, aqua::CVector2::ONE * 650);
}

/*
 * �X�V
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
 * �`��
 */
void CTileManager::Draw()
{
	IGameObject::Draw();
}

/*
 * ���
 */
void CTileManager::Finalize()
{
	SaveTile();

	IGameObject::Finalize();
}

/*
 * �^�C������
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
 * �^�C��������������
 */
void CTileManager::SaveTile()
{
	m_TileDataText.open("map_data\\tile_data.txt", std::ios::out);

	int count_tiles = 0;

	WritingText("tile_info");
	WritingTextCollEnd();

	for (auto& i : m_TileList)
	{
		// ��������
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
 * �e�L�X�g�ɏ�������
 */
void CTileManager::WritingText(std::string w)
{
	m_TileDataText << w << ",";
}

/*
 * �e�L�X�g�̉��s
 */
void CTileManager::WritingTextCollEnd()
{
	m_TileDataText << "\n";

}

/*
 *  �^�C���̃J�[�\���ړ�
 */
void CTileManager::MoveTile()
{
	// �}�E�X���W
	aqua::CVector2 pos = aqua::mouse::GetCursorPos();

	int i = 0;

	// ���������画�f
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

	// �����̂����߂��烊�Z�b�g
	if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
	{
		m_MoveFlag[m_SelectTileID] = false;
		m_SelectTileID = 0;
	}
}

/*
 * �^�C������������^�C���𐶐�
 */
void CTileManager::SampleTile()
{
	aqua::CVector2 pos = aqua::mouse::GetCursorPos();

	int i = 0;

	for (auto& it : m_SampleTile)
	{
		if (it->CheckOnTile(pos) && aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
			CreateTile((TILE_ID)i, aqua::GetWindowSize() / 2.0f);

		i++;
	}
}

/*
 *
 */
void CTileManager::DeleteTile()
{
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::RIGHT))
	{
		aqua::CVector2 pos = aqua::mouse::GetCursorPos();

		int i = -1;

		std::list<ITile*>::iterator it = m_TileList.begin();
		std::list<ITile*>::iterator end = m_TileList.end();

		while (it != end)
		{
			if ((*it)->CheckOnTile(pos))
			{
				i = (*it)->GetNowTileID();

				(*it)->Finalize();

				m_TileList.erase(it);

				break;
			}

			++it;
		}

		int j = 1;

		it = m_TileList.begin();
		end = m_TileList.end();

		while (it != end)
		{
			int max = (*it)->GetMaxNextTileSize();

			(*it)->SetTileID(j);

			for (int tile_i = 0; tile_i < max; tile_i++)
			{
				if ((*it)->GetNextTileID(tile_i) == i)
				{
					(*it)->SetNextTileID(tile_i, 0);
				}
			}

			++j;
			++it;

		}
	}
}

void CTileManager::CreateLine()
{
	aqua::CVector2 pos = aqua::mouse::GetCursorPos();

	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::MIDDLE))
	{
		for (auto& it : m_TileList)
		{
			if (it->CheckOnTile(pos))
			{
				m_LineClass = aqua::CreateGameObjectF<CLine>(this);

				m_LineClass->Initialize(it->GetCenterPosition());

			}
		}
	}

	if (m_LineClass)
	{
		m_LineClass->m_TergetPosition = &pos;

		for (auto& it : m_TileList)
		{
			if (it->CheckOnTile(pos))
				m_LineClass->m_TergetPosition = it->GetCenterPosition();
		}

		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::MIDDLE))
		{
			m_LineList.push_back(m_LineClass);
			m_LineClass = nullptr;
		}
	}

}
