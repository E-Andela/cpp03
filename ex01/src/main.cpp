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
	st.attack("blip");
	st1.attack("blieplbo");
	st.beRepaired(4);
	std::cout << std::endl;

	ct = st;

	ct.attack("hoi");
	std::cout << std::endl;
}