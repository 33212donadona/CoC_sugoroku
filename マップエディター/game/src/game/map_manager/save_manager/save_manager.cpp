#include "save_manager.h"
#include "../back_ground_manager/back_ground_manager.h"

const float CSaveManager::m_min_button_size = 1.0f;
const float CSaveManager::m_max_button_size = 3.5f;
const float CSaveManager::m_max_size_easing_time = 1.0f;

CSaveManager::CSaveManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"SaveManager")
{
}

void CSaveManager::Initialize()
{
	// �{�^���摜�̓ǂݍ���
	m_SaveButtonSprite.Create("data\\button\\Buttom.png");

	// �{�^���摜�̍��W��ݒ�
	m_SaveButtonSprite.position = aqua::GetWindowSize();

	m_SaveButtonSprite.position.x -= m_SaveButtonSprite.GetTextureWidth();
	m_SaveButtonSprite.position.y -= m_SaveButtonSprite.GetTextureHeight();

	// �w�i�N���X
	m_BackGroundClass = (CBackGroundManager*)aqua::FindGameObject("BackGroundManager");

	// �C�[�W���O����
	m_SizeEasingTime.Setup(m_max_size_easing_time);

}

void CSaveManager::Update()
{
	ClickHitButton(aqua::CVector2(aqua::mouse::GetCursorPos()));

	m_SaveButtonSize = aqua::Limit(m_SaveButtonSize, m_min_button_size, m_max_button_size);
}

void CSaveManager::Draw()
{
	m_SaveButtonSprite.Draw();
}

void CSaveManager::Finalize()
{
	m_SaveButtonSprite.Delete();
}

void CSaveManager::ClickHitButton(aqua::CVector2& position)
{

	m_PrivNowButton = m_NowButton;

	aqua::CVector2 origin = m_SaveButtonSprite.position;

	if (
		position.x >= origin.x &&
		position.y >= origin.y &&
		position.x < origin.x + m_SaveButtonSprite.GetTextureWidth() &&
		position.y < origin.y + m_SaveButtonSprite.GetTextureHeight()
		)
	{
		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT) && m_BackGroundClass)
			m_BackGroundClass->SaveSprite();

		m_NowButton = true;

		// ���Ԃ��߂�����ő厞�ԂŌŒ�
		if (m_SizeEasingTime.Finished())
			m_SizeEasingTime.SetTime(m_SizeEasingTime.GetLimit());

		// ���W����������g��
		m_SaveButtonSprite.scale = aqua::CVector2::ONE *
			aqua::easing::InCubic
			(
				m_SizeEasingTime.GetTime(),
				m_SizeEasingTime.GetLimit(),
				m_min_button_size,
				m_max_button_size
			);
	}
	else
	{
		// ���W����������g��
		m_SaveButtonSprite.scale = aqua::CVector2::ONE *
			aqua::easing::OutCubic
			(
				m_SizeEasingTime.GetTime(),
				m_SizeEasingTime.GetLimit(),
				m_max_button_size,
				m_min_button_size
			);
	}

	// �傫���̕������ړ�
	m_SaveButtonSprite.position = aqua::GetWindowSize();
	m_SaveButtonSprite.position.x -= m_SaveButtonSprite.GetTextureWidth() * m_SaveButtonSprite.scale.x;
	m_SaveButtonSprite.position.y -= m_SaveButtonSprite.GetTextureHeight() * m_SaveButtonSprite.scale.y;

	// ���Ԃ̍X�V
	m_SizeEasingTime.Update();
}
