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
	 *  @brief �摜�̕ۑ�
	 * 
	 *  @return �ۑ��̐���
	 *  @retval     true    �ۑ�����
     *  @retval     false   �ۑ����s�܂��͂��łɑ��݂��Ă���
	 */
	bool SaveSprite();

	/*
	 *  @brief �w�i�̃t�@�C�����̃|�C���^ 
	 */
	std::string* GetBackGround();

private:

	/*
	 *  @brief �h���b�N�A���h�h���b�v�ŉ摜�ǂݍ���
	 */
	void DropSprite();

private:

	static const std::string m_directyory_name;
	static const int         m_drop_file_label_size;

	char buffer[MAX_PATH];

	std::string m_BackGround;

	aqua::CSprite m_BackGroundSprite;

	aqua::CLabel  m_BackGroundFile;
	aqua::CLabel  m_FileNum;

	aqua::CLabel  m_DropFileLabel;

	int m_DropSpiteNum;

};