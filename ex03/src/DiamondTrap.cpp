#include "../inc/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap()
{
	m_name = "Faulty";
	ClapTrap::m_name = m_name + "_clap_name";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
	std::cout << "Default DiamondTrap constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	m_name = name;
	ClapTrap::m_name = m_name + "_clap_name";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
	std::cout << "DiamondTrap " << m_name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
	m_name = other.m_name;
	ClapTrap::m_name = m_name + "_clap_name";
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;
	std::cout << "New DiamondTrap constructed in the image of " << other.m_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this == &other)
	{
		std::cout << getType() << m_name << " is already in the image of " << other.m_name << std::endl;
		std::cout << "No need to remodel" << std::endl;
		return (*this);
	}

	std::cout << getType() << m_name << " will be remodeled in the image of " << other.m_name << std::endl;

	m_name = other.m_name;
	ClapTrap::m_name = m_name + "_clap_name";
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << m_name << " disassembled" << std::endl;
}

void DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name: " << m_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::m_name << std::endl;
}

std::string DiamondTrap::getType() const
{
	return "DiamondTrap ";
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

std::string DiamondTrap::getName() const
{
	return m_name;
}
	