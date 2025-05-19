#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ct;
	ScavTrap st;
	ScavTrap st1("Spartacus");
	std::cout << std::endl;

	st.guardGate();
	st.attack("someone");
	st1.attack("someone else");
	st.beRepaired(4);
	std::cout << std::endl;

	ct = st;

	ct.attack("ScavTrap");
	std::cout << std::endl;
}
