#include "Player.h"
#include"Monster.h"

//////////////////////////////////////////////////////////
//public
Player::Player() 
	:Creature("", 10, 1, 0), m_level{ 1 }, m_baseLvlHealth{ 10 }
{
	std::cout << "\nEnter name: ";
	getline(std::cin, m_name);
}

void Player::levelUp()
{
	++m_level; 
	++m_damage;
	m_baseLvlHealth += 2;
	m_health = m_baseLvlHealth;
}

bool Player::iswin()
{
	return m_level >= 20;
}

void Player::addGold(const int value)
{
	m_gold += value;
}

int Player::tryToRun(const Monster& monster)
{
	int isRun = rand() % 2;
	if (!isRun)
	{
		m_health -= monster.getDamage();
		std::cout << "\nFail! You don\'t run, " << monster.getName() << " hit you, and take " << monster.getDamage() << " health points."
			<< "\nNow you have " << m_health << " health points.";
	}
	else
	{
		std::cout << "\nRun forest, run! You is lucky, you can run of monster";
	}
	return static_cast<bool>(isRun);
}
