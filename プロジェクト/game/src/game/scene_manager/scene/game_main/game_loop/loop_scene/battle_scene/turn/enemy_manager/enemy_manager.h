#pragma once
#include "aqua.h"
#include "../../../../../../../../select_charactor/charactor/charactor_id.h"

class CEnemyManager
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief �R���X�g���N�^
	*/
	CEnemyManager(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CEnemyManager() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize(std::string enemy_file);

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

	std::vector<std::pair<aqua::CSprite*,STATUS*>> m_EnemyVector;

};