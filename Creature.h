#pragma once
#include<iostream>
#include<string>

class Creature
{
	void reduceHealth(const int value);

public:
	Creature(std::string name, int health, int damage, int gold);
	const std::string getName()const;
	const int getHealth()const;
	const int getDamage()const;
	const int getGold() const;
	bool isDead();
	void attack(Creature& const object);
protected:
	std::string m_name;
	int m_health, m_damage, m_gold;
};