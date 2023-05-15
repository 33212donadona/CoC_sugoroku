#include "skill.h"

ISkill::ISkill(aqua::IGameObject* parent, std::string name)
	:aqua::IGameObject(parent,name,"Skill")
{
}