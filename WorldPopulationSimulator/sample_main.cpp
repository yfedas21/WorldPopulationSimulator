#include "simulator.h"

int main() {
	std::cout << " -- Welcome to the world population simulator! -- " << std::endl;
	int num_days;

	Simulator *earth_sim = new Simulator();
	std::cout << "How many days do you want the simulation to run? : "; 
	std::cin >> num_days;
	
	earth_sim->set_total_time(num_days);
	
	earth_sim->run_simulation();

	delete earth_sim;
	system("PAUSE");
	return 0;
}