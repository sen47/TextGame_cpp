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
		printPlayerStats();
		std::cout << "\n\nFail! You can\'t run, " << monster.getName() << " hit you, and take " << monster.getDamage() << " health points."
			<< "\nNow you have " << m_health << " health points.";
	}
	else
	{
		printPlayerStats();
		std::cout << "\n\nRun forest, run! You is lucky, you can run of monster";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		system("cls");
	}
	return static_cast<bool>(isRun);
}

void Player::printPlayerStats()
{
	std::cout << "Hero: " << m_name << ", lvl: " << m_level << ", hp: " << m_health 
		<< ", damage: " << m_damage << ", gold: " << m_gold;
}

