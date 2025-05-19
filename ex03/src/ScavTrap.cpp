#include "../inc/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	std::cout << "Default ScavTrap constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	
	std::cout << "ScavTrap " << m_name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "New ScavTrap constructed in the image of " << other.m_name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)
	{
		std::cout << getType() << m_name << " is already in the image of " << other.m_name << std::endl;
		std::cout << "No need to remodel" << std::endl;
		return (*this);
	}

	std::cout << getType() << m_name << " will be remodeled in the image of " << other.m_name << std::endl;

	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;

	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << m_name << " disassembled" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap's attack is called" << std::endl;
	if (m_energyPoints > 0 && m_hitPoints > 0)
	{
		--m_energyPoints;
		std::cout << getType() << getName() << " attacks " << target << " for " << m_attackDamage << " points of damage" << std::endl;
	}
	else
	{
		if (m_hitPoints <= 0)
			std::cout << getType() << getName() << " tries to attack, but is already dead" << std::endl;
		if (m_energyPoints <= 0)
			std::cout << getType() << getName() << " tries to attack, but has no energy left" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << getType() << getName() << " is now in gate keeping mode" << std::endl;
}

std::string ScavTrap::getType() const
{
	return ("ScavTrap ");
}