#include "line.h"

std::list<aqua::CSprite*> CLine::m_ArrowSpriteList;

const float CLine::m_LineThick = 30.0f;
const float CLine::m_ArrowSize = 0.8f;

CLine::CLine(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Line")
	, m_TergetPosition(nullptr)
	, m_FirstPosition(nullptr)
{
	m_ArrowSpriteList.push_back(&m_ArrowSprite);
}

/*
 * ������
 */
void CLine::Initialize(aqua::CVector2* first_pos)
{
	m_FirstPosition = first_pos;

	for (int i = 0; i < (int)LineWay::MAX; i++)
		m_RefalenceTileID[i] = 0;

	m_ArrowSprite.Create("data\\arrow\\arrow.png");
	m_ArrowSprite.scale = aqua::CVector2::ONE * m_ArrowSize;
	m_ArrowSprite.anchor.x = m_ArrowSprite.GetTextureWidth() / 2.0f * m_ArrowSprite.scale.x;
	m_ArrowSprite.anchor.y = m_ArrowSprite.GetTextureHeight() / 2.0f * m_ArrowSprite.scale.y;
}

/*
 * �X�V
 */
void CLine::Update()
{
	if (m_TergetPosition)
		m_PrevFirstPosition = *m_TergetPosition;

	m_ArrowSprite.rotation = atan2(m_PrevFirstPosition.y - m_FirstPosition->y, m_PrevFirstPosition.x - m_FirstPosition->x);

	m_ArrowSprite.position = *m_FirstPosition - (*m_FirstPosition - m_PrevFirstPosition) / 2.0f - m_ArrowSprite.anchor;
}

/*
 * �`��
 */
void CLine::Draw()
{
	DrawLineAA(m_FirstPosition->x, m_FirstPosition->y, m_PrevFirstPosition.x, m_PrevFirstPosition.y, 0xffffffff, m_LineThick);
}

/*
 * ���
 */
void CLine::Finalize()
{
	m_ArrowSpriteList.erase(std::find(m_ArrowSpriteList.begin(), m_ArrowSpriteList.end(), &m_ArrowSprite));
	m_ArrowSprite.Delete();
}

/*
 * ���̂�̃^�C���ԍ��̐ݒ�
 */
void CLine::SetLineWay(int id)
{
	if (id <= 0) return;

	for (int i = 0; i < (int)LineWay::MAX; i++)
	{
		if (m_RefalenceTileID[i] == 0)
		{
			m_RefalenceTileID[i] = id;
			break;
		}
	}
}

/*
 * ���̂�Ƀ^�C���ԍ������邩�擾
 */
bool CLine::GetLineWayFlag(int id)
{
	for (int i = 0; i < (int)LineWay::MAX; i++)
		if (m_RefalenceTileID[i] == id)return true;

	return false;
}

void CLine::ArrowDraw()
{
	if (m_ArrowSpriteList.empty())return;

	for (auto& it : m_ArrowSpriteList)
	{
		it->Draw();
	}
}
