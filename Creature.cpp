#include "Creature.h"

///////////////////////////////////////////////////////
//private
void Creature::reduceHealth(const int value)
{
	m_health -= value;
}

//////////////////////////////////////////////////////
//public
Creature::Creature(std::string name, int health, int damage, int gold)
	: m_name{ name }, m_health{ health }, m_damage{ damage }, m_gold{ gold }{};

const std::string Creature::getName()const
{
	return m_name;
}

const int Creature::getHealth()const
{
	return m_health;
}

const int Creature::getDamage() const
{
	return m_damage;
}

const int Creature::getGold() const
{
	return m_gold;
}

bool Creature::isDead()
{
	return (m_health <= 0);
}

void Creature::attack(Creature& const object)
{
	object.reduceHealth(this->m_damage);
}
