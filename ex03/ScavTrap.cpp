/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:45:54 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/23 14:04:07 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	setName("DefaultScavy");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "🤖 ScavTrap Default constructor called for " << getName() << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "🤖 ScavTrap Constructor called for " << name << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "🛠️ ScavTrap Copy constructor called for " << other.getName() << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "📋 ScavTrap Assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "💀 ScavTrap Destructor called for " << getName() << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "🛡 ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
	unsigned int energyPoints = getEnergyPoints();
	if (getHitPoints() <= 0)
	{
		std::cout << "❌ ScavTrap " << getName() << " cannot attack: 0 hit points!" << std::endl;
		return;
	}
	if (getEnergyPoints() <= 0)
	{
		std::cout << "🚧 ScavTrap " << getName() << " cannot attack: no energy points left!" << std::endl;
		return;
	}
	std::cout << "🏹 ScavTrap " << getName() << " attacks " << target
			  << ", causing " << energyPoints << " points of damage!" << std::endl;
	setEnergyPoints(energyPoints - 1);
}