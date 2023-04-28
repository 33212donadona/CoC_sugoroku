#pragma once
#include "aqua.h"
#include "sound_id.h"
class CGameSoundManager : 
	public aqua::IGameObject
{
public:
	CGameSoundManager(aqua::IGameObject* parent);
	~CGameSoundManager() = default;

	void Initialize()override;
	void Update()override;
	void Finalize()override;

private:

	static const std::string m_SoundListFile;

	std::vector<std::pair<Scene::ID,std::string>> m_SoundBGM;



};