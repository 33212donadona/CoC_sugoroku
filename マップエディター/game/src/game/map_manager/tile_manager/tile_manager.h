#pragma once
#include "aqua.h"
#include "tile/tile.h"
#include "line/line.h"
#include <fstream>

enum class TILE_ID
{
	NORMAL,
	IVENT,

	MAX
};

class CTileManager:
	public aqua::IGameObject
{
public:

	CTileManager(aqua::IGameObject* parent);
	~CTileManager() = default;

	/*
	 * @brief ������
	 */
	void Initialize()override;

	/*
	 * @brief �X�V
	 */
	void Update()override;

	/*
	 * @brief �`��
	 */
	void Draw()override;

	/*
	 * @brief ���
	 */
	void Finalize()override;

	/*
	 * @brief �^�C������
	 */
	void CreateTile(TILE_ID tile_id,aqua::CVector2 position);

	/*
	 * @brief �^�C���̕ۑ�
	 */
	void SaveTile(std::string* back_ground);

private:

	/*
	 * @brief �e�L�X�g�ɏ�������
	 * 
	 * @param[in] w  ������
	 */
	void WritingText(std::string w);

	/*
	 * @brief �e�L�X�g�̉��s
	 */
	void WritingTextCollEnd();

	/*
	 * @brief �^�C���̃J�[�\���ړ�
	 */
	void MoveTile();

	/*
	 * @brief �^�C������������^�C���𐶐�
	 */
	void SampleTile();

	/*
	 * @brief �^�C��������
	 */
	void DeleteTile();

	/*
	 * @brief �^�C���ɓ������� 
	 */
	void CreateLine();

private:
	static const float        m_menu_space;              //! ���j���[�̃X�y�[�X
	static const int          m_menu_font_size;          //! ���j���[�����̑���

	std::ofstream             m_TileDataText;            //! �^�C���ۑ��t�@�C���ϐ� 

	std::string               m_TileDataTextName;        //! �^�C���ۑ��t�@�C����

	std::list<ITile*>         m_TileList;	             //! �^�C���N���X�̃��X�g
	std::list<ITile*>         m_TileMenu;	             //! ���j���[�^�C���N���X�̃��X�g
	std::list<CLine*>         m_LineList;	             //! ���C���N���X�̃��X�g
	std::list<ITile*>::iterator::value_type m_FromTile;  //! ���C���̎n�_

	CLine*                    m_LineClass;               //! ���C���N���X

	std::vector<bool>         m_MoveFlag;                //! �^�C���N���X�̈ړ��t���O

	aqua::CBoxPrimitive       m_MenuBox;                 //! ���j���[�{�b�N�X
	aqua::CLabel              m_MenuLabel;               //! ���j���[���x��

	int                       m_SelectTileID;            //! ���삵�����^�C���ԍ�
	int                       m_TileTextFileMax;         //! �^�C���ۑ��t�@�C���̌�

};