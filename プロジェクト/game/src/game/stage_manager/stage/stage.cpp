#include "stage.h"
#include <filesystem>
/*
 *  �R���X�g���N�^ 
 */
CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Stage")
{
}

/*
 *  ������
 */
bool CStage::Initialize(std::string file_name)
{
	if(!std::filesystem::exists(file_name))return false;

	m_TileManager = aqua::CreateGameObject<CTileManager>(this);

	aqua::CCSVLoader loader;

	loader.Load(file_name);

	m_BackGoundSprite.Create(loader.GetString(0,0));

	int row = 1;
	int max_row = loader.GetRows();
	int max_col = loader.GetCols() - 1;

	while (row < max_row)
	{
		TileInfo info;

		info.id = loader.GetInteger(row, 0);
		info.tile_name = loader.GetString(row, 1);
		info.position.x = loader.GetFloat(row, 2);
		info.position.y = loader.GetFloat(row, 3);

		for (int i = 4; i < max_col; ++i)
			info.m_FromID.push_back(loader.GetInteger(row, i));
		
		m_TileManager->CreateTile(info);

		row++;
	}

	return true;
}

/*
 *  �X�V
 */
void CStage::Update()
{
	IGameObject::Update();
	m_TileManager->Update();
}

/*
 *  �`��
 */
void CStage::Draw()
{
	m_BackGoundSprite.Draw();
	m_TileManager->Draw();
}

/*
 *  �`��
 */
void CStage::Finalize()
{
	m_BackGoundSprite.Delete();
	m_TileManager->Finalize();
}
