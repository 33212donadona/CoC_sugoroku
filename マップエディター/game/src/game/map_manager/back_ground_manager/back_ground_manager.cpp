#include "back_ground_manager.h"
#include <filesystem>
#include <fstream>

namespace file_sys = std::filesystem;

const std::string CBackGroundManager::m_directyory_name = "map_data";
const int         CBackGroundManager::m_drop_file_label_size = 100;

CBackGroundManager::CBackGroundManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "BackGroundManager")
{
}

void CBackGroundManager::Initialize()
{
	// �f�B���N�g���𐶐�
	file_sys::create_directory(m_directyory_name);

	m_BackGroundFile.Create(20);
	m_FileNum.Create(20);

	m_FileNum.text = "�h���b�N�A���h�h���b�v : " + std::to_string(0);

	// ���x��
	m_DropFileLabel.Create(m_drop_file_label_size);
	m_DropFileLabel.text = "�w�i�摜���R�R��\n�h���b�N�A���h�h���b�v!!";
	m_DropFileLabel.position = aqua::GetWindowSize() / 2.0f;
	m_DropFileLabel.position.x -= m_DropFileLabel.GetTextWidth()  / 2.0f;
	m_DropFileLabel.position.y -= m_DropFileLabel.GetFontHeight() / 2.0f;
	m_DropFileLabel.color = 0xff000000;
}

void CBackGroundManager::Update()
{
	DropSprite();
}

void CBackGroundManager::Draw()
{
	if (m_BackGroundSprite.GetResourceHandle() != AQUA_UNUSED_HANDLE)
	{

		m_BackGroundSprite.Draw();
		m_BackGroundFile.Draw();

	}
	else
		m_DropFileLabel.Draw();

	m_FileNum.Draw();
}

void CBackGroundManager::Finalize()
{
	if (m_BackGroundSprite.GetResourceHandle() != AQUA_UNUSED_HANDLE)
	{
		m_BackGroundSprite.Delete();
	}

	m_DropFileLabel.Delete();
	m_BackGroundFile.Delete();
	m_FileNum.Delete();
}

void CBackGroundManager::DropSprite()
{
	// ���N���b�N�Ńt�@�C���f�[�^���X�v���C�g�ɓǂݍ���
	if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
	{
		// �h���b�N�A���h�h���b�v�����t�@�C���̌��i�t�@�C����ǂݍ��񂾂�0���Z�b�g�j
		m_DropSpiteNum = GetDragFileNum();

		// �t�@�C�����𕶎����
		m_FileNum.text = "�h���b�N�A���h�h���b�v : " + std::to_string(m_DropSpiteNum);

		// �h���b�N�A���h�h���b�v�����t�@�C���̐�΃p�X
		GetDragFilePath(buffer);

		if (m_DropSpiteNum >= 1)
		{
			if (m_BackGroundSprite.GetResourceHandle() != AQUA_UNUSED_HANDLE)
				m_BackGroundSprite.Delete();

			m_BackGroundFile.text = buffer;

			m_BackGroundFile.position.y = (float)m_FileNum.GetFontHeight();

			m_BackGroundSprite.Create(buffer);
		}

	}
}
/*
 *  �摜�̕ۑ�
 */
bool CBackGroundManager::SaveSprite()
{
	if (m_BackGroundSprite.GetResourceHandle() == AQUA_UNUSED_HANDLE)return false;

	int file_buffer_num = 0;

	// �t�@�C�������擾
	for (int i = MAX_PATH; i > 0; i--)
	{
		if (buffer[i] == '\\')
		{
			file_buffer_num = i + 1;
			break;
		}
	}

	m_BackGround = m_directyory_name + "\\";

	// �R�s�[��̎Q�ƃp�X���쐬
	for (int i = file_buffer_num; i < MAX_PATH; i++)
	{
		if (buffer[i] == '\0')
			break;

		m_BackGround += buffer[i];
	}

	// �t�@�C�������݂��Ȃ���̓R�s�[��ɕۑ�����
	if (!file_sys::exists(m_BackGround))
		file_sys::copy_file(buffer, m_BackGround);

	return true;
}

/*
 *  �w�i�̃t�@�C�����̃|�C���^
 */
std::string* CBackGroundManager::GetBackGround()
{
	return &m_BackGround;
}
