#include "../inc/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : m_name {name}
{
	std::cout << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: m_name {other.m_name}
	, m_hitPoints {other.m_hitPoints}
	, m_energyPoints {other.m_energyPoints}
	, m_attackDamage {other.m_attackDamage}
{
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return (*this);

	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;

	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructing " << m_name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << m_name << " attacks " << target << " for " << m_attackDamage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	m_hitPoints -= amount;
	std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage" << std::endl;
}