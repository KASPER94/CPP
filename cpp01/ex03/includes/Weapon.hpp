/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:03 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 10:28:14 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <cstdlib>

class Weapon {
	private:
		std::string	_type;
	
	public:
		Weapon(std::string _type);
		~Weapon();
		
		const std::string	&getType();	
		void	setType(std::string _type);
};

#endif