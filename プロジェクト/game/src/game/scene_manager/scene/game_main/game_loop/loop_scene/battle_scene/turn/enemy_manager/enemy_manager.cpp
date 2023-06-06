#include "enemy_manager.h"

CEnemyManager::CEnemyManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "EnemyManager")
{
}

void CEnemyManager::Initialize(std::string enemy_file)
{

	aqua::CCSVLoader loader;

	loader.Load(enemy_file);

	int row = loader.GetRows();

	for (int i = 0; i > row; ++i)
	{
		std::pair<aqua::CSprite*, STATUS*> enemy;
		aqua::CSprite sprite;
		STATUS status;

		sprite.Create(loader.GetString(i, 0));
		status.m_Hp  = loader.GetFloat(i, 1);
		status.m_Str = loader.GetInteger(i, 2);
		status.m_Dex = loader.GetInteger(i, 3);

		enemy.first = &sprite;
		enemy.second = &status;

		m_EnemyVector.push_back(enemy);
	}

}

void CEnemyManager::Update()
{

}

void CEnemyManager::Draw()
{

}

void CEnemyManager::Finalize()
{

}
