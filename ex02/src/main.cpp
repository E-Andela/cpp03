#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap claptrap("Clappy");
	ScavTrap scavtrap("Scavvy");
	FragTrap fragtrap("Fraggy");
	std::cout << std::endl;

	claptrap.attack("target");
	scavtrap.attack("target");
	fragtrap.attack("target");
	std::cout << std::endl;

	claptrap.takeDamage(5);
	scavtrap.takeDamage(5);
	fragtrap.takeDamage(5);
	std::cout << std::endl;

	claptrap.beRepaired(3);
	scavtrap.beRepaired(3);
	fragtrap.beRepaired(3);
	std::cout << std::endl;

	fragtrap.highFivesGuys();
	scavtrap.guardGate();
	std::cout << std::endl;

	ClapTrap *cp = &scavtrap;
	cp->attack("target");
	std::cout << std::endl;
	
	return (0);
}