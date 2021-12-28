#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

class Creature
{
public:
	Creature(std::string name, const char symbol, int health, int damage, int gold)
		: m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold }{};
	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }

	void reduceHealth(const int value) { m_health -= value; }
	bool isDead() { return m_health > 0; }
	void addGold(const int value) { m_gold += value; }
	void attack(Creature& object)
	{
		object.reduceHealth(this->m_damage);
	}
protected:
	std::string m_name;
	char m_symbol;
	int m_health, m_damage, m_gold;
};

class Player : public Creature
{
public:
	Player() :Creature("", '@', 10, 1, 0), m_level{ 1 }
	{
		std::cout << "\nEnter name: ";
		getline(std::cin, m_name);
	}
	void levelUp() { ++m_level; }
	bool iswin() { return m_level == 20; }
private:
	int m_level;
};

class Monster :public Creature
{
public:
	enum Type
	{
		DRAGON, ORC, SLIME, MAX_TYPES
	};

	Monster(Type type) :Creature(monsterData[type].name, monsterData[type].symbol,
		monsterData[type].health, monsterData[type].damage, monsterData[type].gold) {};
	static Type getRandomMonster()
	{
		int type = rand() % Monster::MAX_TYPES;
		return static_cast<Type>(type);
	}
private:
	struct MonsterData
	{
		std::string name;
		char symbol;
		int health, damage, gold;
	};
	static MonsterData monsterData[Monster::MAX_TYPES];
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
		{ "dragon", 'D', 20, 4, 100 },
		{ "orc", 'O', 4, 2, 25 },
		{ "slime", 'S', 1, 1, 10 }
};

char getAnswer();

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Player player;
	std::cout << "Welcome, " << player.getName();
	char answer;
	const char RUN = 'r', FIGHT = 'f';
	do
	{
		Monster monster = Monster::getRandomMonster();
		answer = getAnswer();
		switch (answer)
		{
		case RUN:

			break;
		case FIGHT:

			break;
		}
	} while (!player.iswin() || !player.isDead());


	return 0;
}

char getAnswer()
{
	char answer;
	while (true)
	{
		std::cout << "\n(R)un or (F)ight: ";
		std::cin >> answer;
		std::cin.ignore(32767, '\n');
		if (std::cin.fail() || (answer != 'r' && answer != 'f'))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nTry again!";
		}
		return answer;
	}
}