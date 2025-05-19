#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
protected:
	std::string m_name;
	int			m_hitPoints {10};
	int			m_energyPoints {10};
	int			m_attackDamage {0};

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	virtual std::string getType() const;
	virtual std::string getName() const;
};

#endif