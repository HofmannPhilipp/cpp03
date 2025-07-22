/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:07:11 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/22 10:56:05 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== 🔨 Creating FragTrap f1 ===" << std::endl;
	FragTrap f1("Fraggy");

	std::cout << "\n=== 🧪 Testing highFivesGuys() ===" << std::endl;
	f1.highFivesGuys();

	std::cout << "\n=== 📋 Copy Constructor: f2(f1) ===" << std::endl;
	FragTrap f2(f1);

	std::cout << "\n=== 📥 Assignment Operator: f3 = f1 ===" << std::endl;
	FragTrap f3;
	f3 = f1;

	std::cout << "\n=== ⚔️ Testing attack, takeDamage, and beRepaired ===" << std::endl;
	f1.printStatus();
	f1.attack("Training Dummy");
	f1.takeDamage(30);
	f1.printStatus();
	f1.beRepaired(20);
	f1.printStatus();

	std::cout << "\n=== 🔁 Energy Drain Test ===" << std::endl;
	for (int i = 0; i < 51; ++i)
		f1.attack("Target " + std::to_string(i));

	std::cout << "\n=== ❌ Damage Beyond HP ===" << std::endl;
	f1.takeDamage(999); // should go to 0 HP
	f1.attack("won't happen");
	f1.beRepaired(10);

	std::cout << "\n=== 🧹 End of Main ===" << std::endl;

	return 0;
}