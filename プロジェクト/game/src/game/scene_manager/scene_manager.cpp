#include "scene_manager.h"
#include "scene_channel.h"
#include "../game_sound_manager/game_sound_manager.h"
#include "../common_data/common_data.h"

const unsigned int CSceneManager::m_fade_color[] =       //! �t�F�[�h�̐F
{
	0xff000000,
	0xff007f00,
	0xff00007f,
	0xff7f7f00,
	0xff007f7f,
	0xff7f007f
};

const float         CSceneManager::m_fade_time = 0.75f;	 //! �t�F�[�h�̍ő厞��
const unsigned char CSceneManager::m_max_alpha = (unsigned char)250;	 //! ���ߓx�̍ő�
const unsigned char CSceneManager::m_min_alpha = (unsigned char)0;      //! ���ߓx�̍ŏ�

/*
 *  �R���X�g���N�^
 */
CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SceneManager")
	, m_Scene(nullptr)
	, m_NextID(SceneID::TITLE)
	, m_SceneState(STATE::SCENE_IN)
{
}

/*
 *  ������
 */
void CSceneManager::Initialize()
{
	aqua::CreateGameObject<CGameSoundManager>(this)->Initialize();
	aqua::CreateGameObject<CCommonData>(this);

	ChageScene(m_NextID);

	m_FadeBox.Setup(
		aqua::CVector2::ZERO,
		(float)aqua::GetWindowWidth(),
		(float)aqua::GetWindowHeight(),
		m_fade_color[(int)COLOR::BLACK]
	);

	m_FadeTime.Setup(m_fade_time);
}

/*
 *  �X�V
 */
void CSceneManager::Update()
{
	switch (m_SceneState)
	{
	case CSceneManager::STATE::SCENE_IN:

		if (m_FadeTime.GetLimit() < m_FadeTime.GetTime())
			m_FadeTime.SetTime(m_FadeTime.GetLimit());

		m_FadeBox.color.alpha = (unsigned char)aqua::easing::InExp
		(
			m_FadeTime.GetTime(),
			m_FadeTime.GetLimit(),
			m_max_alpha,
			m_min_alpha
		);

		if (m_FadeTime.Finished())
		{
			m_FadeBox.color.alpha = m_min_alpha;
			m_SceneState = STATE::SCENE_UPDATA;
			m_FadeTime.Reset();
		}
		else
			m_FadeTime.Update();

		break;
	case CSceneManager::STATE::SCENE_UPDATA:

		if (m_Scene->CheckChangeFlag())
		{
			m_SceneState = STATE::SCENE_OUT;
			int color = aqua::Rand((int)COLOR::MAX - 1, (int)COLOR::BLACK);
			m_FadeBox.color = m_fade_color[color];
		}

		break;
	case CSceneManager::STATE::SCENE_OUT:

		if (m_FadeTime.GetLimit() <= m_FadeTime.GetTime())
			m_FadeTime.SetTime(m_FadeTime.GetLimit());

		m_FadeBox.color.alpha = (unsigned char)aqua::easing::OutExp
		(
			m_FadeTime.GetTime(),
			m_FadeTime.GetLimit(),
			m_min_alpha,
			m_max_alpha
		);

		if (m_FadeTime.Finished())
		{
			m_FadeBox.color.alpha = m_max_alpha;
			m_SceneState = STATE::SCENE_CHANGE;
			m_FadeTime.Reset();
		}
		else
			m_FadeTime.Update();

		break;
	case CSceneManager::STATE::SCENE_CHANGE:

		// ���̃V�[�����Q��
		m_NextID = m_Scene->GetNextScene();

		// �V�[���̏I������
		m_Scene->Finalize();

		aqua::ListErase(&m_ChildObjectList, m_Scene);

		AQUA_SAFE_DELETE(m_Scene);

		// �V�[���̐؂�ւ�
		ChageScene(m_NextID);

		m_SceneState = STATE::SCENE_IN;

		break;
	}

	IGameObject::Update();
}

/*
 *  �`��
 */
void CSceneManager::Draw()
{
	if (m_Scene)
		m_Scene->Draw();

	m_FadeBox.Draw();
}

/*
 *  ���
 */
void CSceneManager::Finalize()
{
	// �V�[���̏I������
	m_Scene->Finalize();

	aqua::ListErase(&m_ChildObjectList, m_Scene);

	AQUA_SAFE_DELETE(m_Scene);

	IGameObject::Finalize();
}

/*
 *  �V�[���̐؂�ւ�
 */
void CSceneManager::ChageScene(SceneID scene_id)
{
	if (scene_id == SceneID::DUMMY)return;

	switch (scene_id)
	{
	case SceneID::TITLE:
		m_Scene = (IScene*)aqua::CreateGameObject<CTitle>(this);
		break;
	case SceneID::SELECT:
		m_Scene = (IScene*)aqua::CreateGameObject<CSelect>(this);
		break;
	case SceneID::GAME:
		m_Scene = (IScene*)aqua::CreateGameObject<CGameMain>(this);
		break;
	case SceneID::RESULT:
		m_Scene = (IScene*)aqua::CreateGameObject<CResult>(this);
		break;
	}

	m_Scene->Initialize();
}
