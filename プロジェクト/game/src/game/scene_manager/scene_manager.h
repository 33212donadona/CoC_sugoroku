#pragma once
#include "aqua.h"
#include "scene/scene.h"

class CSceneManager :
	public aqua::IGameObject
{
public:

	/*!
	*  @brief �R���X�g���N�^
	*/
	CSceneManager(aqua::IGameObject* parent);

	/*!
	*  @brief �f�X�g���N�^
	*/
	~CSceneManager() = default;

	/*!
	*  @brief ������
	*/
	void Initialize()override;

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

	/*!
	*  @brief �V�[���̐؂�ւ�
	*/
	void ChageScene( SceneID scene_id);

private:

	/*!
	 *  @brief      ���ID
	 */
	enum class STATE
	{
		SCENE_IN,
		SCENE_UPDATA,
		SCENE_OUT,
		SCENE_CHANGE,
	};

	/*!
	 *  @brief      �FID 
	 */
	enum class COLOR
	{
		BLACK,
		GREEN,
		BLUE,
		YELLOW,
		CYAN,
		MAGENT,

		MAX
	};

	static const unsigned int m_fade_color[(int)COLOR::MAX]; //! �t�F�[�h�̐F
	static const float        m_fade_time;                   //! �t�F�[�h�̍ő厞��
	static const float        m_max_alpha;                   //! ���ߓx�̍ő�
	static const float        m_min_alpha;                   //! ���ߓx�̍ŏ�
											                 
	IScene* m_Scene;                                         //! �V�[���̊��N���X
											                 
	SceneID m_NextID;		                                 //! ���̃V�[��ID
	STATE   m_SceneState;                                    //! �V�[���̏��
											                 
	aqua::CBoxPrimitive m_FadeBox;                           //! ��ʃt�F�[�h
	aqua::CTimer        m_FadeTime;                          //! �t�F�[�h�̎���

};