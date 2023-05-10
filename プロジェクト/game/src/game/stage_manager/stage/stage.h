#pragma once
#include "aqua.h"
#include "tile_manager/tile_manager.h"

class CStage
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CStage(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CStage() = default;

	/*!
	 *  @brief ������
	 */
	bool Initialize(std::string file_name);

	/*!
	 *  @brief �X�V
	 */
	void Update()override;

	/*!
	 *  @brief �`��
	 */
	void Draw()override;

	/*!
	 *  @brief ���
	 */
	void Finalize()override;
private:

	aqua::CSprite m_BackGoundSprite;

	CTileManager* m_TileManager;

	TileInfo*     m_TileData;
};