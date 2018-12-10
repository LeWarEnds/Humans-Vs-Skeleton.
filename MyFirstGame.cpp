#include <iostream>
#include <random>
#include <ctime>

int main() {

	std::cout << "***** Welcome to Humans Vs skeletons ***** " << std::endl << std::endl; // heading of the game when starts.

	std::default_random_engine randomGenerator(time(NULL));
	std::uniform_real_distribution<float> Attack(0.0f, 1.0f);

	//Human Properties.
	float humanAttack = 0.6f;
	float humanDamage = 200.0f;
	float humanHealth = 250.0f;
	float currentHumanHealth = humanHealth;

	// Skeleton Properties.
	float skeletonAttack = 0.4f;
	float skeletonDamage = 40.0f;
	float skeletonHealth = 50.0f;
	float currentSkeletonHealth = skeletonHealth;

	int Skeletons;
	int Humans;
	int startHumans;
	int startSkeletons;

	float attackResult;

	char humanTurn = 'H';
	char skeletonTurn = 'S';

	//Get the number of Humans.
	std::cout << "Enter the number of Humans : " << std::flush;
	std::cin >> Humans;
	startHumans = Humans;

	//Get the number of Skeletons.
	std::cout << "Enter the number of Skeletons : " << std::flush;
	std::cin >> Skeletons;
	startSkeletons = Skeletons;


	while ((Humans > 0 ) && (Skeletons > 0)) {

		// Get the Attack value.
		attackResult = Attack(randomGenerator);
		
		//Turn of Humans.
		if (humanTurn == 'H') {

			// if the attack hits the skeleton.
			if (attackResult <= humanAttack) {
				currentSkeletonHealth -= humanDamage;
			}
			// if the health reduced to zero.
			if (currentSkeletonHealth < 0) {
				Skeletons--;
				currentSkeletonHealth = skeletonHealth;
			}
			//Turn equals to Skeleton.
			skeletonTurn = 'S';
		}
		

		else {
			if (attackResult <= skeletonAttack) {
				currentHumanHealth -= skeletonDamage;
			}
			if (currentHumanHealth < 0) {
				Humans--;
				currentHumanHealth = humanHealth;
			}	
			// Turn Changes to Human.
			humanTurn = 'H';
		}
	}

	std::cout << "Battle Ended. " << std::endl;
	if (Humans > 0) {
		std::cout << "Humans Won." << std::endl;
		std::cout << "There are " << Humans << " Humans left." << std::endl;	
	}
	else {
		std::cout << "Skeletons Won. " << std::endl;
		std::cout << "There are " << Skeletons << " Skeletons left. " << std::endl;
	}

	std::cout << startHumans - Humans << " Humans Lost their lives. " << std::endl;
	std::cout << startSkeletons - Humans << " Skeletons Lost their lives. " << std::endl;

	system("PAUSE");
	return 0;
}
