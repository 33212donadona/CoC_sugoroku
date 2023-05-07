#pragma once
#include "aqua.h"
#include "../sound_id.h"

class CGameSound
	:public aqua::IGameObject
{
public:

	CGameSound(aqua::IGameObject parent);
	~CGameSound() = default;

	/*
	*  @brief ������
	*/
	void Initialize(Sound_ID id,std::string name,bool loop_flag);

	/*
	*  @brief ���
	*/
	void Finalize()override;

	/*
	*  @brief ���yID���擾
	*/
	Sound_ID GetSoundID();

	/*
	*  @brief �Đ�
	*/
	void Play();

	/*
	*  @brief ��~
	*/
	void Stop();

	/*
	*  @brief ��~
	*/
	bool IsPlaying();


private:

	Sound_ID m_ID;                //! ���yID
	aqua::CSoundPlayer m_Sound;   //! ���y

};