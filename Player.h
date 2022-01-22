#pragma once

#include<thread>
#include<chrono>

#include"Creature.h"


class Monster;

class Player : public Creature
{
public:
	Player();
	void levelUp();
	bool iswin();
	void addGold(const int value);
	int tryToRun(const Monster& monster);
	void printPlayerStats();
private:
	int m_level;
	int m_baseLvlHealth;
};