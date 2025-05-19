#include "../inc/DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap diamond;
	std::cout << std::endl;

	diamond.whoAmI();
	std::cout << std::endl;

	diamond.attack("target");
	std::cout << std::endl;

	diamond.highFivesGuys();
	std::cout << std::endl;

	diamond.guardGate();
	std::cout << std::endl;
}