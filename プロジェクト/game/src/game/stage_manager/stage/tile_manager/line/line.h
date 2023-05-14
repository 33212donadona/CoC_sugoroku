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
	void Initialize(aqua::CVector2* start_pos, aqua::CVector2* end_pos);

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
	 * @brief ���̕`��
	 * 
	 */
	static void ArrowDraw();


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
	aqua::CVector2* m_TergetPosition;                      // �I�_���W�̃|�C���^
	aqua::CVector2  m_Distance;                            // ����
	aqua::CSprite   m_ArrowSprite;                         // ���摜
	aqua::CSprite   m_LineSprite;                          // ���摜

	int*            m_RefalenceTileID[(int)LineWay::MAX];  // �n�_�I�_�̃^�C���ԍ�
};