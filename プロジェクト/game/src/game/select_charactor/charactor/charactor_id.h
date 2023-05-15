#pragma once
#include <list>

enum class PLAYER_ID
{
	PL1,
	PL2,
	PL3,
	PL4,

	DUMMY
};

enum class JOB_ID
{
	ATTACKER,
	TANKER,
	SUPPORTER,
	HEALER,
	MAX
};

enum class SKILL_ID
{
	FIRING,
	SCOLDING,
	STEEL_MUSCLE,
	SIKOHUMI,
	FINALE,
	QUIBBLE,
	EMERGENCY_SURGERY,
	DOSE,
	MAX
};

struct STATUS
{
	float m_Hp = 0.0f;
	int m_Str = 0;
	int m_Dex = 0;
	int m_Armored = 0;
	PLAYER_ID m_Player = PLAYER_ID::DUMMY;
	PLAYER_ID m_Terget = PLAYER_ID::DUMMY;
};

using STATUS_LIST = std::list<STATUS>;