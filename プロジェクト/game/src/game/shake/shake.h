#pragma once
#include "aqua.h"

class Shake
	:public aqua::IGameObject
{
public:

	Shake(aqua::IGameObject* parent);

	~Shake() = default;

	void Updata();

	void SetUp(int max_shake_count,float m_shake_interval);

	void ReSet();

	aqua::CVector2 GetShake();

private:

	aqua::CVector2 m_ShakeMove;
	aqua::CTimer  m_ShakeTimer;
	int m_ShakeCount;
	int m_ShakeMaxCount;
	float m_Angle;

};