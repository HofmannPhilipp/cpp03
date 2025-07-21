/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:07:11 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/21 13:35:20 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");

	std::cout << "\n=== Testing Attack ===" << std::endl;
	a.attack("a wooden dummy");
	a.printStatus();
	a.attack("training bot");
	a.printStatus();

	std::cout << "\n=== Testing Damage ===" << std::endl;
	a.printStatus();
	a.takeDamage(3);
	a.printStatus();
	a.takeDamage(5);
	a.printStatus();
	a.takeDamage(10); // Should result in 0 HP
	a.printStatus();

	std::cout << "\n=== Testing Repair ===" << std::endl;
	a.beRepaired(4); // Should NOT work (dead)
	a.printStatus();

	b.printStatus();
	b.beRepaired(5); // Should work
	b.printStatus();

	std::cout << "\n=== Draining Energy ===" << std::endl;
	for (int i = 0; i < 11; ++i)
	{
		b.attack("energy target"); // Will stop when energy runs out
		b.printStatus();
	}

	std::cout << "\n=== Done ===" << std::endl;

	return 0;
}