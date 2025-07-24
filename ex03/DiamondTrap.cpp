/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:42:03 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/23 16:17:56 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("DefaultDiamondy")
{
	setName(this->name + "_clap_name");
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "💎 DiamondTrap Default constructor called for " << this->name << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name)
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "💎 DiamondTrap Constructor called for " << name << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "🛠️ DiamondTrap Copy constructor called for " << other.getName() << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "📋 DiamondTrap Assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	this->name = other.name;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "💀 DiamondTrap Destructor called for " << this->name << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "🤖 [whoAmI] I am DiamondTrap \"" << this->name
			  << "\", but my ClapTrap name is \"" << ClapTrap::getName() << "\"." << std::endl;
}