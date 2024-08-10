/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:11 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/10 13:38:50 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAPP_HPP
# define SCAVTRAPP_HPP

# include "ClapTrap.hpp"

class ScavTrap {
	private:
		bool	gateKeeperMode;

	public:
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &cpy);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &rhs);

		void	attack(const std::string &target);
		void	guardGate();
}

#endif
