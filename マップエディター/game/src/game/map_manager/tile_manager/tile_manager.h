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
	void SaveTile();

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

	std::ofstream m_TileDataText;

	std::list<ITile*> m_TileList;
	std::list<ITile*> m_SampleTile;

	std::list<CLine*> m_LineList;
	CLine*            m_LineClass;

	aqua::CLabel label;

	std::vector<bool> m_MoveFlag;

	int m_SelectTileID;

};