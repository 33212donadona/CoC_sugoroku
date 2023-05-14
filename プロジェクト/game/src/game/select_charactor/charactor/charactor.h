#pragma once
#include "aqua.h"
#include "charactor_id.h"

class CCharactor
	: public aqua::IGameObject
{
public:
	/*!
	 *  @brief �R���X�g���N�^
	 */
	CCharactor(aqua::IGameObject* parent);

	/*!
	 *  @brief �f�X�g���N�^
	 */
	~CCharactor() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize();

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




};