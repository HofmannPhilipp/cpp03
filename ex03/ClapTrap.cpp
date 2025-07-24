/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:07:54 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/24 09:58:29 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: name("DefaultTrap"),
	  hitPoints(10),
	  energyPoints(10),
	  attackDamage(0)
{
	std::cout << "🛠️ ClapTrap Default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "🛠️ ClapTrap Constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "🛠️ ClapTrap Copy constructor called for " << other.getName() << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "📋ClapTrap Assignment operator called" << std::endl;
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
	std::cout << "💀ClapTrap Destructor called for " << name << std::endl;
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
	std::cout << "🔫 ClapTrap " << name << " attacks " << target
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
void ClapTrap::setName(std::string name)
{
	this->name = name;
}
void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}
std::string ClapTrap::getName() const
{
	return this->name;
}
unsigned int ClapTrap::getHitPoints() const
{
	return this->hitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}
unsigned int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}
void ClapTrap::printStatus() const
{
	std::cout << "📊 [Status] " << name
			  << " | HP: " << hitPoints
			  << " | Energy: " << energyPoints
			  << " | Attack: " << attackDamage << std::endl;
}
