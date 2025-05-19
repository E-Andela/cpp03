#include "../inc/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << "Default FragTrap constructed" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	
	std::cout << "FragTrap " << m_name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "New FragTrap constructed in the image of " << other.m_name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this == &other)
	{
		std::cout << "FragTrap " << m_name << " is already in the image of " << other.m_name << std::endl;
		std::cout << "No need to remodel" << std::endl;
		return (*this);
	}

	std::cout << "FragTrap " << m_name << " will be remodeled in the image of " << other.m_name << std::endl;

	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;

	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << m_name << " disassembled" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (m_energyPoints <= 0)
	{
		std::cout << "FragTrap " << m_name << " tries to high five, but is out of energy" << std::endl;
		return ;
	}
	if (m_hitPoints <= 0)
	{
		std::cout << "FragTrap " << m_name << " tries to high five, but is already dead" << std::endl;
		return ;
	}
	--m_energyPoints;
	std::cout << "FragTrap " << m_name << " high fives you!" << std::endl;
}