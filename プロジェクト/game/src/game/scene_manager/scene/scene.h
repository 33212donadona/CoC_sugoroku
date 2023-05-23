#pragma once
#include "aqua.h"
#include "scene_id.h"
#include "../../game_sound_manager/sound_id.h"

class CGameSoundManager;

class IScene : 
	public aqua::IGameObject
{
public:

	/*
	*  @brief �R���X�g���N�g
	*/
	IScene(aqua::IGameObject* parent,std::string name,SceneID next_scene);

	/*
	*  @brief �f�X�g���N�g
	*/
	virtual ~IScene() = default;
	
	/*
	*  @brief �X�V
	*/
	virtual void Update()override;

	/*
	*  @brief �`��
	*/
	virtual void Draw()override;

	/*
	*  @brief ���
	*/
	virtual void Finalize()override;

	/*
	*  @brief �؂�ւ��t���O�̎擾
	* 
	*  @retval     true    �؂�ւ���
    *  @retval     false   �؂�ւ��Ȃ�
	*/
	bool CheckChangeFlag();

	/*
	*  @brief ���̃V�[���̎擾
	* 
	*  @return ���̃V�[��
	*/
	SceneID GetNextScene();

protected:

	bool m_ChangeFlag;                 //! �؂�ւ��t���O

private:

	/*
	*   @brief �V�[���ɍ��������yID���擾
	* 
	*   @return ���yID
	*/
	Sound_ID SceneSoundID(std::string& name);

private:
	SceneID m_NextSceneID;           //! ���̃V�[��ID

	aqua::CLabel m_SceneName;        //! �V�[����

	

	CGameSoundManager* m_GameSoundManager; //! ���y�Ǘ��N���X
};

