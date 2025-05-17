#include "../inc/ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ct1("R3-D4");
	ClapTrap ct2("C3-PE");
	ClapTrap ct3(ct1);
	ClapTrap ct4;
	ct4 = ct2;

	std::cout << std::endl;

	ct1.attack("C3-P0");
	ct2.takeDamage(5);
	ct2.attack("R3-D4");
	ct2.beRepaired(3);

	std::cout << std::endl;

	ct4.takeDamage(5);
	ct4.takeDamage(9);
	ct4.takeDamage(5);
	ct4.attack("someone");
	ct4.beRepaired(10);
	ct4.attack("someone");

	std::cout << std::endl;
}