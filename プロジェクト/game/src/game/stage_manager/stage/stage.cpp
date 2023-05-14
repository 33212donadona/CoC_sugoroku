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
	int count_row = 0;
	int max_row = loader.GetRows() - row;
	int max_col = loader.GetCols() - 1;

	m_TileData = AQUA_NEW TileInfo[max_row];

	while (row < max_row)
	{
		m_TileData[count_row].id = loader.GetInteger(row, 0);
		m_TileData[count_row].tile_name = loader.GetString(row, 1);
		m_TileData[count_row].position.x = loader.GetFloat(row, 2);
		m_TileData[count_row].position.y = loader.GetFloat(row, 3);

		for (int i = 4; i < max_col; ++i)
			m_TileData[count_row].m_FromID.push_back(loader.GetInteger(row, i));
		
		m_TileManager->CreateTile(&m_TileData[count_row]);

		row++;
		count_row++;
	}

	loader.Unload();

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

	AQUA_SAFE_DELETE(m_TileManager);
	AQUA_SAFE_DELETE_ARRAY(m_TileData);
}
