/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:07:54 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/24 10:08:15 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("DefaultTrap"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "🛠️ Default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "🛠️ Constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "🛠️ ClapTrap Copy constructor called for " << other.name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	std::cout << "📋 Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "💀 Destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << "❌ ClapTrap " << name << " cannot attack: 0 hit points!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "🚧 ClapTrap " << name << " cannot attack: no energy points left!" << std::endl;
		return;
	}
	std::cout << "💣 ClapTrap " << name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "💢 ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
	if (hitPoints <= amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "❌ ClapTrap " << name << " cannot repair: 0 hit points!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "🚧 ClapTrap " << name << " cannot repair: no energy points left!" << std::endl;
		return;
	}

	std::cout << "🔧 ClapTrap " << name << " repairs itself for " << amount << " HP!" << std::endl;
	hitPoints += amount;
	energyPoints--;
}

void ClapTrap::printStatus() const
{
	std::cout << "📊 [Status] " << name
			  << " | HP: " << hitPoints
			  << " | Energy: " << energyPoints
			  << " | Attack: " << attackDamage << std::endl;
}
