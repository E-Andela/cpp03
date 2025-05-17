#include "../inc/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: m_name{"Faulty"}
	, m_hitPoints {10}
	, m_energyPoints {10}
	, m_attackDamage {0}
{
	std::cout << "Default ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: m_name {name}
	, m_hitPoints {10}
	, m_energyPoints {10}
	, m_attackDamage {0}
{
	std::cout << "ClapTrap " << m_name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: m_name {other.m_name}
	, m_hitPoints {other.m_hitPoints}
	, m_energyPoints {other.m_energyPoints}
	, m_attackDamage {other.m_attackDamage}
{
	std::cout << "New Claptrap constructed in the image of " << other.m_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
	{
		std::cout << "ClapTrap " << m_name << " is already in the image of " << other.m_name << std::endl;
		std::cout << "No need to remodel" << std::endl;
		return (*this);
	}

	std::cout << "ClapTrap " << m_name << " will be remodeled in the image of " << other.m_name << std::endl;
	
	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;

	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << m_name << " disassembled" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (m_energyPoints > 0 && m_hitPoints > 0)
	{
		--m_energyPoints;
		std::cout << "ClapTrap " << m_name << " attacks " << target << " for " << m_attackDamage << " points of damage" << std::endl;
	}
	else
	{
		if (m_hitPoints <= 0)
			std::cout << "ClapTrap " << m_name << " tries to attack, but is already dead" << std::endl;
		if (m_energyPoints <= 0)
			std::cout << "ClapTrap " << m_name << " tries to attack, but has no energy left" << std::endl;
	}	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_hitPoints <= 0)
	{
		std::cout << "Stop! " << m_name << " is already dead" << std::endl;
		return ;
	}
	m_hitPoints -= amount;
	std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage" << std::endl;
	if (m_hitPoints < 0)
	{
		m_hitPoints = 0;
		std::cout << "ClapTrap " << m_name << " has lost all of its hit points and falls to the ground" << std::endl;
	}
	else
		std::cout << "ClapTrap " << m_name << " has " << m_hitPoints << " hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints > 0)
	{
		--m_energyPoints;
		m_hitPoints += amount;
		std::cout << "ClapTrap " << m_name << " regains " << amount << " hit points" << std::endl;
		std::cout << "Claptrap " << m_name << " now has " << m_hitPoints << " hit points" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << m_name << " tries to repair itself, but has no energy left" << std::endl;
	}
}