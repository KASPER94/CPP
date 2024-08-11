/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:11 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/11 14:47:59 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;
		using 		FragTrap::_hit_pts;
		using		ScavTrap::_energy_pts;
		using		FragTrap::_attack_pts;

	public:
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap &cpy);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &rhs);

		using	ScavTrap::attack;
		void	whoAmI(void);
};

#endif
