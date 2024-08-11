/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:11 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/11 14:39:30 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAPP_HPP
# define SCAVTRAPP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap {
	private:
		bool	_gateKeeperMode;

	public:
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &cpy);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &rhs);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif
