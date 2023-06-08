#pragma once
#include "aqua.h"

using LinePair = std::pair<aqua::CSprite*, bool*>;
using LineList = std::list<LinePair*>;

enum class LineWay
{
	FROM,
	TO,

	MAX
};

class CLine :
	public aqua::IGameObject
{
public:

	CLine(aqua::IGameObject* parent);
	~CLine() = default;

	/*
	 * @brief ������
	 */
	void Initialize(aqua::CVector2* start_pos, aqua::CVector2* end_pos,int tile_id,int from_id);

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

	/*
	 * @brief �n�_�I�_�̃^�C���ԍ����擾
	 */
	int GetWayTileID(LineWay way);

	static LineList m_ArrowSpriteList;    // ���摜���X�g

	bool visible;                         // 

private:

	static const float m_LineThick;       // ���̑���
	static const float m_ArrowSize;       // ���̑傫��
										  
	aqua::CVector2* m_FirstPosition;      // �n�_���W�̃|�C���^
	aqua::CVector2* m_TergetPosition;     // �I�_���W�̃|�C���^
	aqua::CVector2  m_Distance;           // ����
	aqua::CSprite   m_ArrowSprite;        // ���摜
	aqua::CSprite   m_LineSprite;         // ���摜
										  
	LinePair        m_LinePair;           // ���̃y�A
										  
	int*            m_RefalenceTileID;    // �n�_�I�_�̃^�C���ԍ�
};