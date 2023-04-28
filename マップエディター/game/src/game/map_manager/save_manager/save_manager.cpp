#include "save_manager.h"
#include "../back_ground_manager/back_ground_manager.h"

const float CSaveManager::m_min_button_size = 1.0f;
const float CSaveManager::m_max_button_size = 1.5f;
const float CSaveManager::m_max_size_easing_time = 1.0f;
const float CSaveManager::m_max_massage_time = 2.5f;

CSaveManager::CSaveManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SaveManager")
{
}

/*
 *  ������
 */
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

	// ���b�Z�[�W����
	m_MassageTime.Setup(m_max_massage_time);

}

/*
 *  �X�V
 */
void CSaveManager::Update()
{
	ClickHitButton(aqua::CVector2(aqua::mouse::GetCursorPos()));

	ButtonChangeSize();

	m_SaveButtonSize = aqua::Limit(m_SaveButtonSize, m_min_button_size, m_max_button_size);
}

/*
 *  �`��
 */
void CSaveManager::Draw()
{
	m_SaveButtonSprite.Draw();
}

/*
 *  ���
 */
void CSaveManager::Finalize()
{
	m_SaveButtonSprite.Delete();
}

/*
 *  �{�^������
 */
void CSaveManager::ClickHitButton(aqua::CVector2& position)
{
	// �O�t���[���̃t���O��ۑ�
	m_PrivCursorOnButton = m_CursorOnButton;

	// �{�^���̌��_
	aqua::CVector2 origin = m_SaveButtonSprite.position;

	// �{�^���̏Փ˔���
	if (
		position.x >= origin.x &&
		position.y >= origin.y &&
		position.x < origin.x + m_SaveButtonSprite.GetTextureWidth() * m_SaveButtonSprite.scale.x &&
		position.y < origin.y + m_SaveButtonSprite.GetTextureHeight() * m_SaveButtonSprite.scale.y
		)
	{

		if (aqua::mouse::Button(aqua::mouse::BUTTON_ID::LEFT))
			m_SaveButtonSprite.color = (aqua::CColor)0xff5f5f5f;

		// ���N���b�N�ŃZ�[�u
		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT) && m_BackGroundClass)
		{
			m_SaveMassageFlag = m_BackGroundClass->SaveSprite();

			m_SaveButtonSprite.color = (aqua::CColor)0xffffffff;
		}

		// �J�[�\���t���O��^
		m_CursorOnButton = true;

	}
	else
	{
		// �J�[�\���t���O���U
		m_CursorOnButton = false;
	}
}

/*
 *  �{�^���̃T�C�Y�ύX
 */
void CSaveManager::ButtonChangeSize()
{
	// �g�又��
	if (!m_SizeEasingTime.Finished())
	{
		// �J�[�\�������ɓ�������^
		if (m_CursorOnButton)
		{
			// �g��
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
			// �k��
			m_SaveButtonSprite.scale = aqua::CVector2::ONE *
				aqua::easing::OutCubic
				(
					m_SizeEasingTime.GetTime(),
					m_SizeEasingTime.GetLimit(),
					m_max_button_size,
					m_min_button_size
				);
		}
	}
	else
	{
		// ���Ԃ��߂�����ő厞�ԂŌŒ�
		m_SizeEasingTime.SetTime(m_SizeEasingTime.GetLimit());

		// �g�厞�Ԃ̃��Z�b�g
		if (m_CursorOnButton == !m_PrivCursorOnButton)
		{
			m_SizeEasingTime.SetTime(m_SizeEasingTime.GetLimit() - m_SizeEasingTime.GetTime());
		}
	}


	// ���Ԃ̍X�V
	m_SizeEasingTime.Update();

	// �傫���̕������摜�ړ�
	m_SaveButtonSprite.position = aqua::GetWindowSize();
	m_SaveButtonSprite.position.x -= m_SaveButtonSprite.GetTextureWidth() * m_SaveButtonSprite.scale.x;
	m_SaveButtonSprite.position.y -= m_SaveButtonSprite.GetTextureHeight() * m_SaveButtonSprite.scale.y;

}
