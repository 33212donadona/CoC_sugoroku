#include "stage_manager.h"
#include "stage/stage.h"
#include <filesystem>

const std::string CStageManager::m_tile_data = "map_data\\tile_data_";

CStageManager::CStageManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent)
	, m_Stage(nullptr)
	, m_ExistsFileNum(0)
	, m_SelectFile(0)
{
}

/*
 *  ������
 */
void CStageManager::Initialize()
{
}

/*
 *  �X�V
 */
void CStageManager::Update()
{
	if (m_Stage)m_Stage->Update();
}

/*
 *  �`��
 */
void CStageManager::Draw()
{
	if (m_Stage)m_Stage->Draw();
}

/*
 *  ���
 */
void CStageManager::Finalize()
{
	if (m_Stage)m_Stage->Finalize();
	AQUA_SAFE_DELETE(m_Stage);
}

/*
 *  �X�e�[�W�𐶐�
 */
void CStageManager::CreateStage(int stage_id)
{
	if (stage_id > m_ExistsFileNum || stage_id < 0)return;

	m_SelectFile = stage_id;

	m_Stage = aqua::CreateGameObject<CStage>(this);
	m_Stage->Initialize(m_tile_data + std::to_string(m_SelectFile) + ".txt");
}

/*
 * ���݂���t�@�C���̌������߂�
 */
void CStageManager::CountExistsFile()
{
	while (std::filesystem::exists(m_tile_data + std::to_string(m_SelectFile) + ".txt"))
	{
		m_ExistsFileNum++;
	}
}
