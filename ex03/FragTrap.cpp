/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:23:57 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/22 11:19:09 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	setName("DefaultFraggy");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "🐐 FragTrap Default constructor called for " << getName() << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "🐐 FragTrap Constructor called for " << name << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "🛠️ FragTrap Copy constructor called for " << other.getName() << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "📋 FragTrap Assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "💀 FragTrap Destructor called for " << getName() << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "🖐 FragTrap " << getName() << " requests a high five! Positive vibes only! ✨" << std::endl;
}