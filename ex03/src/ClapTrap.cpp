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
	std::cout << "New ClapTrap constructed in the image of " << other.m_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << m_name << " disassembled" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_hitPoints <= 0)
	{
		std::cout << "Stop! " << getName() << " is already dead" << std::endl;
		return ;
	}
	m_hitPoints -= amount;
	std::cout << getType() << getName() << " takes " << amount << " points of damage" << std::endl;
	if (m_hitPoints < 0)
	{
		m_hitPoints = 0;
		std::cout << getType() << getName() << " has lost all of its hit points and falls to the ground" << std::endl;
	}
	else
		std::cout << getType() << getName() << " has " << m_hitPoints << " hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints > 0)
	{
		--m_energyPoints;
		m_hitPoints += amount;
		std::cout << getType() << getName() << " regains " << amount << " hit points" << std::endl;
		std::cout << getType() << getName() << " now has " << m_hitPoints << " hit points" << std::endl;
	}
	else
	{
		std::cout << getType() << getName() << " tries to repair itself, but has no energy left" << std::endl;
	}
}

std::string ClapTrap::getType() const
{
	return "ClapTrap ";
}

std::string ClapTrap::getName() const
{
	return m_name;
}