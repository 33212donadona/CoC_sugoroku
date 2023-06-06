#include "select_tile_text.h"

const aqua::CPoint CSelectTileText::m_font_space(20, 40);
const aqua::CPoint CSelectTileText::m_shake_noise(12, 5);
const float CSelectTileText::m_shake_interval = 0.5f;
const int   CSelectTileText::m_shake_max_count = 4;

CSelectTileText::CSelectTileText(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SelectTileText")
	, m_ShakeMove(aqua::CVector2::ZERO)
	, m_ShakeCount(0)
	, m_Angle(0)

{
}

void CSelectTileText::Initialize(std::string text, aqua::CVector2 center_position, int font_size)
{
	m_TextLabel.Create(font_size);
	m_TextLabel.text = text;

	m_TextBox.Create("data\\game_main\\UI\\Šª•¨_Ž†.png");
	m_TextBox.position = center_position;

	// —]”’‚ðŠÜ‚ß‚½‘å‚«‚³
	aqua::CPoint text_size;
	text_size.x = (m_TextLabel.GetTextWidth() + m_font_space.x);
	text_size.y = (m_TextLabel.GetFontHeight() + m_font_space.y);

	m_TextBox.position.x -= text_size.x / 2.0f;
	m_TextBox.position.y -= text_size.y / 2.0f;

	for (int i = 0; i < 2; ++i)
	{
		m_TextBothEnds[i].Create("data\\game_main\\UI\\Šª•¨_‘©.png");
		m_TextBothEnds[i].position = m_TextBox.position;
	}

	// •¶Žš‚É‡‚í‚¹‚Ä‘å‚«‚³‚ð•ÏX
	m_TextBox.scale.x = (float)((text_size.x + m_TextBothEnds[0].GetTextureWidth()) / m_TextBox.GetTextureWidth());
	m_TextBox.scale.y = (float)(text_size.y / m_TextBox.GetTextureHeight());

	m_TextBothEnds[0].position.x -= m_TextBothEnds[0].GetTextureWidth() / 2.0f;
	m_TextBothEnds[1].position.x += m_TextBox.GetTextureWidth() * m_TextBox.scale.x - m_TextBothEnds[1].GetTextureWidth() / 2.0f;

	m_TextLabel.position = center_position;
	m_TextLabel.position.x -= m_TextLabel.GetTextWidth() / 2.0f;
	m_TextLabel.position.y -= m_TextLabel.GetFontHeight() / 2.0f;

	// ŽžŠÔ
	m_ShakeTimer.Setup(m_shake_interval);
}

void CSelectTileText::Update()
{
	if (m_ShakeCount != 0)
	{
		if (m_ShakeTimer.Finished())
		{
			m_ShakeTimer.Reset();
			m_Angle = aqua::DegToRad((float)aqua::Rand(360));
			m_ShakeMove.x = m_ShakeCount * cosf(m_Angle);
			m_ShakeMove.y = m_ShakeCount * sinf(m_Angle);
			m_ShakeCount--;
		}
		 
		m_ShakeTimer.Update();
	}
	else
	{
		m_ShakeMove = aqua::CVector2::ZERO;

		m_ShakeCount = m_shake_max_count;
	}
}

void CSelectTileText::Draw()
{
	m_TextBox.Draw();

	m_TextLabel.Draw();

	for (int i = 0; i < 2; ++i)
		m_TextBothEnds[i].Draw();
}

void CSelectTileText::Finalize()
{
	m_TextBox.Delete();

	m_TextLabel.Delete();

	for (int i = 0; i < 2; ++i)
		m_TextBothEnds[i].Delete();
}