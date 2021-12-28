#include "Monster.h"

////////////////////////////////////////////////////////////
//private
Monster::MonsterData const Monster::monsterData[Monster::MAX_TYPES]
{
		{ "dragon", 20, 4, 100 },
		{ "orc", 4, 2, 25 },
		{ "slime", 1, 1, 10 }
};

////////////////////////////////////////////////////////////
//public
Monster::Monster(Type type) 
	:Creature(monsterData[type].name, monsterData[type].health, monsterData[type].damage, monsterData[type].gold) {}

Monster::Type Monster::getRandomMonster()
{
	int type = rand() % Monster::MAX_TYPES;
	return static_cast<Type>(type);
}

void Monster::printMonsterInfo()
{
	std::cout << "\n\nYou have encountered a " << m_name << ", he have " << m_health << " points of health.";
}
