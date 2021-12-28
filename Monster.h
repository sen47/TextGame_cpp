#pragma once
#include"Creature.h"

class Monster :public Creature
{
public:
	enum Type
	{
		DRAGON, ORC, SLIME, MAX_TYPES
	};

	Monster(Type type);
	static Type getRandomMonster();
	void printMonsterInfo();
private:
	struct MonsterData
	{
		std::string name;
		int health, damage, gold;
	};
	static const MonsterData monsterData[Monster::MAX_TYPES];
};

