/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:03 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 10:34:45 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <cstdlib>
# include "Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon	&weapon;
	
	public:
		HumanA(std::string _name, Weapon &weapon);
		~HumanA();
		
		void	attack(void);	
};

#endif