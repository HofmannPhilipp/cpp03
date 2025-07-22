/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:07:11 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/21 17:48:47 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== Creating ScavTrap ===" << std::endl;
	ScavTrap s("Scavy");

	std::cout << "\n=== ScavTrap: Testing Attack ===" << std::endl;
	s.attack("Training Dummy");
	s.attack("Target Bot");

	std::cout << "\n=== ScavTrap: Taking Damage ===" << std::endl;
	s.printStatus();
	s.takeDamage(30);
	s.printStatus();
	s.takeDamage(50);
	s.printStatus();
	s.takeDamage(50); // Should reduce HP to 0
	s.printStatus();

	std::cout << "\n=== ScavTrap: Attempt Repair ===" << std::endl;
	s.beRepaired(10); // Should not work if HP is 0
	s.printStatus();

	std::cout << "\n=== New ScavTrap: Energy Drain Test ===" << std::endl;
	ScavTrap t("Tanky");
	for (int i = 0; i < 51; ++i)
		t.attack("Dummy #" + std::to_string(i));
	t.printStatus();

	std::cout << "\n=== ScavTrap: Repair Test ===" << std::endl;
	t.beRepaired(20);
	t.printStatus();

	std::cout << "\n=== ScavTrap: Special Ability ===" << std::endl;
	t.guardGate();

	std::cout << "\n=== Destruction Phase ===" << std::endl;
	return 0;
}