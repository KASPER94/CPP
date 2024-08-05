/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:03 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 10:36:37 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <cstdlib>
# include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon		*weapon;
	
	public:
		HumanB(std::string _name);
		~HumanB(void);
		
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif