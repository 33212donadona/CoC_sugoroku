#pragma once
#include "aqua.h"

class CTurn
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief �R���X�g���N�^
	*/
	CTurn(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CTurn() = default;

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

	aqua::CSprite m_BackGround;

};