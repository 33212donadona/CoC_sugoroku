#include"shake.h"

Shake::Shake(aqua::IGameObject* parent)
	:IGameObject(parent,"Shake")
{
}

void Shake::Updata()
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

		m_ShakeCount = m_ShakeMaxCount;
	}
}

void Shake::SetUp(int max_shake_count,float m_shake_interval)
{
	m_Angle = 0;

	m_ShakeMove = aqua::CVector2::ZERO;
	m_ShakeMaxCount = max_shake_count;
	m_ShakeCount = m_ShakeMaxCount;

	m_ShakeTimer.Setup(m_shake_interval);
}

void Shake::ReSet()
{
	m_Angle = 0;

	m_ShakeMove = aqua::CVector2::ZERO;
	m_ShakeCount = m_ShakeMaxCount;
	
	m_ShakeTimer.Reset();
}

aqua::CVector2 Shake::GetShake()
{
	return m_ShakeMove;
}
