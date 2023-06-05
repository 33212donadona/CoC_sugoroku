#pragma once
#include "aqua.h"


class CBattleScene
	:public aqua::IGameObject
{
public:

	/*!
	*  @brief �R���X�g���N�^
	*/
	CBattleScene(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CBattleScene() = default;

	/*!
	 *  @brief ������
	 */
	void Initialize(std::string back_ground_name);

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