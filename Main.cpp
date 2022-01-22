#include<cstdlib>
#include<ctime>

#include"Player.h"
#include"Monster.h"

char getAnswer();

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	rand();

	std::cout << "Welcome to my magical world, and will your adventures begin!";

	Player player;
	std::cout << "Hello, " << player.getName() << ", are you ready?";
	//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "\nIn general, to be honest, i don\'t care, we start!";
	//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	system("cls");

	const char RUN = 'r', FIGHT = 'f';
	
	do
	{
		player.printPlayerStats();
		Monster monster = Monster::getRandomMonster();
		monster.printMonsterInfo();
		
		bool isRun = false;
		do
		{
			char answer = getAnswer();
			system("cls");
			
			switch (answer)
			{
			case RUN:
				isRun = player.tryToRun(monster);
				break;
			case FIGHT:
				player.attack(monster);
				monster.attack(player);
				player.printPlayerStats();
				monster.printMonsterInfo();
				break;
			}
		} while (!isRun && !monster.isDead()|| !player.isDead());

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