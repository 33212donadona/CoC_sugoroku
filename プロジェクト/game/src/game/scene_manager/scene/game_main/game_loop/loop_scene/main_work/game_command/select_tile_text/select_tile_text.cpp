#include "select_tile_text.h"
#include "../../../../../../../../shake/shake.h"

const aqua::CPoint CSelectTileText::m_font_space(20, 40);
const aqua::CPoint CSelectTileText::m_shake_noise(12, 5);
const float CSelectTileText::m_shake_interval = 0.1f;
const int   CSelectTileText::m_shake_max_count = 4;
const int	CSelectTileText::m_flashing_max_time = 360;
const int	CSelectTileText::m_max_both_ends = 2;
const unsigned char CSelectTileText::m_flashing_alpha = 20;

CSelectTileText::CSelectTileText(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SelectTileText")
	, m_FlashingFlag(false)

{
}

void CSelectTileText::Initialize(std::string text, aqua::CVector2 center_position, int font_size)
{

	m_TextBothEnds = AQUA_NEW aqua::CSprite[m_max_both_ends];
	m_FlashingTextBothEnds = AQUA_NEW aqua::CSprite[m_max_both_ends];
	m_TextBothEndsPosition = AQUA_NEW aqua::CVector2[m_max_both_ends];
	m_FlashingTextBothEndsPosition = AQUA_NEW aqua::CVector2[m_max_both_ends];

	m_TextLabel.Create(font_size);
	m_TextLabel.text = text;
	// 余白を含めた大きさ
	m_TextSize.x = (m_TextLabel.GetTextWidth() + m_font_space.x);
	m_TextSize.y = (m_TextLabel.GetFontHeight() + m_font_space.y);

	m_TextLabel.position = center_position;
	m_TextLabel.position -= m_TextSize / 2.0f;

	m_TextBox.Create("data\\game_main\\UI\\巻物_紙.png");
	m_TextBox.position = m_TextLabel.position;


	m_TextBox.scale.y = (float)(m_TextSize.y / m_TextBox.GetTextureHeight());

	for (int i = 0; i < m_max_both_ends; ++i)
	{
		m_TextBothEnds[i].Create("data\\game_main\\UI\\巻物_束.png");
		m_TextBothEnds[i].position = m_TextBox.position;
		m_TextBothEnds[i].scale.y = m_TextBox.scale.y;
	}

	// 文字に合わせて大きさを変更
	m_TextBox.scale.x = (float)((m_TextSize.x + m_TextBothEnds[0].GetTextureWidth()) / m_TextBox.GetTextureWidth());

	m_TextBothEnds[0].position.x -= m_TextBothEnds[0].GetTextureWidth() / 2.0f;
	m_TextBothEnds[1].position.x += m_TextBox.GetTextureWidth() * m_TextBox.scale.x - m_TextBothEnds[1].GetTextureWidth() / 2.0f;


	// 点滅用
	m_FlashingTextBox = m_TextBox;
	m_FlashingTextBox.blend_mode = aqua::ALPHABLEND::ADD;
	m_FlashingTextBox.color.alpha = m_flashing_alpha;


	for (int i = 0; i < m_max_both_ends; ++i)
	{

		m_FlashingTextBothEnds[i] = m_TextBothEnds[i];
		m_FlashingTextBothEnds[i].blend_mode = aqua::ALPHABLEND::ADD;
		m_FlashingTextBothEnds[i].color.alpha = m_flashing_alpha;

	}

	// 座標を保持
	m_TextLabelPosition = m_TextLabel.position;
	m_TextBoxPosition = m_TextBox.position;
	m_FlashingTextBoxPosition = m_FlashingTextBox.position;

	for (int i = 0; i < m_max_both_ends; ++i)
	{
		m_TextBothEndsPosition[i] = m_TextBothEnds[i].position;
		m_FlashingTextBothEndsPosition[i] = m_FlashingTextBothEnds[i].position;
	}

	m_Shake = aqua::CreateGameObject<Shake>(this);
	m_Shake->SetUp(m_shake_max_count, m_shake_interval);

	// 時間
	m_FlashingTime.Setup(m_flashing_max_time);

}

void CSelectTileText::Update()
{
	if (m_FlashingFlag)
	{
		m_Shake->Updata();

		if (m_FlashingFlag)
			m_FlashingFlag = false;

		m_TextLabel.position = m_TextLabelPosition + m_Shake->GetShake();

		m_TextBox.position = m_TextBoxPosition + m_Shake->GetShake();

		m_FlashingTextBox.position = m_FlashingTextBoxPosition + m_Shake->GetShake();

		for (int i = 0; i < m_max_both_ends; ++i)
		{
			m_TextBothEnds[i].position = m_TextBothEndsPosition[i] + m_Shake->GetShake();
			m_FlashingTextBothEnds[i].position = m_FlashingTextBothEndsPosition[i] + m_Shake->GetShake();
		}
	}
	else
	{
		if (m_TextLabel.position != m_TextLabelPosition)
			m_TextLabel.position = m_TextLabelPosition;

		if (m_TextBox.position != m_TextBoxPosition)
			m_TextBox.position = m_TextBoxPosition;

		if (m_FlashingTextBox.position != m_FlashingTextBoxPosition)
			m_FlashingTextBox.position = m_FlashingTextBoxPosition;

		for (int i = 0; i < m_max_both_ends; ++i)
		{
			if (m_TextBothEnds[i].position != m_TextBothEndsPosition[i])
				m_TextBothEnds[i].position = m_TextBothEndsPosition[i];

			if (m_FlashingTextBothEnds[i].position != m_FlashingTextBothEndsPosition[i])
				m_FlashingTextBothEnds[i].position = m_FlashingTextBothEndsPosition[i];
		}

		m_Shake->ReSet();
	}
}

void CSelectTileText::Draw()
{
	m_TextBox.Draw();

	m_TextLabel.Draw();

	for (int i = 0; i < m_max_both_ends; ++i)
		m_TextBothEnds[i].Draw();

	if (m_FlashingFlag)
	{
		m_FlashingTextBox.Draw();

		for (int i = 0; i < m_max_both_ends; ++i)
			m_FlashingTextBothEnds[i].Draw();
	}
}

void CSelectTileText::Finalize()
{
	m_TextBox.Delete();
	m_FlashingTextBox.Delete();

	m_TextLabel.Delete();

	for (int i = 0; i < m_max_both_ends; ++i)
	{
		m_TextBothEnds[i].Delete();
		m_FlashingTextBothEnds[i].Delete();
	}
}

/*
 *  点滅
 */
void CSelectTileText::FlashingColor()
{
	if (!m_FlashingFlag)
	{
		m_FlashingFlag = true;

		m_FlashingTextBox.color.alpha = m_flashing_alpha;

		for (int i = 0; i < m_max_both_ends; ++i)
			m_FlashingTextBothEnds[i].color.alpha = m_flashing_alpha;

		m_FlashingTime.Reset();
	}

	m_FlashingTime.Update();

	if (m_FlashingTime.Finished())
		m_FlashingTime.Reset();

	m_FlashingTextBox.color.alpha =
		(unsigned char)(sin(aqua::DegToRad(m_FlashingTime.GetTime())) * 255);

	for (int i = 0; i < m_max_both_ends; ++i)
	{
		m_FlashingTextBothEnds[i].color.alpha =
			(unsigned char)(sin(aqua::DegToRad(m_FlashingTime.GetTime())) * 255);
	}
}

aqua::CVector2 CSelectTileText::GetTextSize()
{
	aqua::CVector2 size;

	size.x = (float)(m_TextBothEnds[0].GetTextureWidth() + m_TextBox.GetTextureWidth() * m_TextBox.scale.x);

	size.y = (float)m_TextBox.GetTextureHeight();

	return size;
}

void CSelectTileText::SetPosition(aqua::CVector2 center_position)
{

	m_TextLabel.position = center_position;
	m_TextLabel.position.x -= m_TextLabel.GetTextWidth() / 2.0f;
	m_TextLabel.position.y -= m_TextLabel.GetFontHeight() / 2.0f;

	m_TextBox.position = m_TextLabel.position;

	for (int i = 0; i < m_max_both_ends; ++i)
	{
		m_TextBothEnds[i].position = m_TextBox.position;
	}

	m_TextBothEnds[0].position.x -= m_TextBothEnds[0].GetTextureWidth() / 2.0f;
	m_TextBothEnds[1].position.x += m_TextBox.GetTextureWidth() * m_TextBox.scale.x - m_TextBothEnds[1].GetTextureWidth() / 2.0f;

	m_FlashingTextBox.position = m_TextBox.position;

	for (int i = 0; i < m_max_both_ends; ++i)
		m_FlashingTextBothEnds[i].position = m_TextBothEnds[i].position;

	// 座標を保持
	m_TextLabelPosition = m_TextLabel.position;
	m_TextBoxPosition = m_TextBox.position;
	m_FlashingTextBoxPosition = m_FlashingTextBox.position;

	for (int i = 0; i < m_max_both_ends; ++i)
	{
		m_TextBothEndsPosition[i] = m_TextBothEnds[i].position;
		m_FlashingTextBothEndsPosition[i] = m_FlashingTextBothEnds[i].position;
	}

}
