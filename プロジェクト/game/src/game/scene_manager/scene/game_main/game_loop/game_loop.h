#pragma once
#include "aqua.h"

class CGameLoop
	:public aqua::IGameObject
{
public:
	/*!
	*  @brief �R���X�g���N�^
	*/
	CGameLoop(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CGameLoop() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize()override;

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