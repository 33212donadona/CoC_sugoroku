#pragma once
#include "aqua.h"

class CLine :
	public aqua::IGameObject
{
public:

	CLine(aqua::IGameObject* parent);
	~CLine() = default;

	/*
	 * @brief ������
	 */
	void Initialize(aqua::CVector2* first_pos);

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
	 * @brief ���̂�̃^�C���ԍ��̐ݒ�
	 * 
	 * @param[in] id �^�C���ԍ�
	 */
	void SetLineWay(int* id);

	/*
	 * @brief ���̂�Ƀ^�C���ԍ������邩�擾
	 * 	 
	 * @param[in] id �^�C���ԍ�
	 *
	 * @return ���̂�Ƀ^�C���ԍ������邩
	 * @retval true  ����
	 * @retval false �Ȃ�
	 */
	bool GetLineWayFlag(int* id);

	/*
	 * @brief ���̕`��
	 * 
	 */
	static void ArrowDraw();

	aqua::CVector2* m_TergetPosition;     // �I�_���W

	static std::list<aqua::CSprite*> m_ArrowSpriteList;    // ���摜���X�g

private:

	enum class LineWay
	{
		FROM,
		TO,

		MAX
	};

private:

	static const float m_LineThick;                        // ���̑���
	static const float m_ArrowSize;                        // ���̑傫��

	aqua::CVector2* m_FirstPosition;                       // �n�_���W�̃|�C���^
	aqua::CVector2  m_PrevFirstPosition;                   // �I�_���W
	aqua::CSprite   m_ArrowSprite;                         // ���摜

	int*            m_RefalenceTileID[(int)LineWay::MAX];  // �n�_�I�_�̃^�C���ԍ�
};