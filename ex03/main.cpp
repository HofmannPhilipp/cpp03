/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:07:11 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/23 13:11:58 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== 🔨 Konstruktor-Tests ===\n";
	DiamondTrap d1("Diamondy");
	d1.printStatus();

	std::cout << "\n=== 📋 Copy Constructor-Test ===\n";
	DiamondTrap d2(d1); // Copy Constructor
	d2.printStatus();

	std::cout << "\n=== 📥 Assignment Operator-Test ===\n";
	DiamondTrap d3;
	d3 = d1; // Assignment Operator
	d3.printStatus();

	std::cout << "\n=== 🔫 Attack / Repair / Take Damage ===\n";
	d1.attack("enemy");
	d1.takeDamage(20);
	d1.beRepaired(10);
	d1.printStatus();

	std::cout << "\n=== 🚧 Test aus ScavTrap ===\n";
	d1.guardGate();

	std::cout << "\n=== 🎉 Test aus FragTrap ===\n";
	d1.highFivesGuys();

	std::cout << "\n=== 👤 Test von whoAmI() ===\n";
	d1.whoAmI();

	std::cout << "\n=== 💀 Destruktor-Test beim Ende ===\n";
	return 0;
}