/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:11 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/11 11:35:59 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap &cpy);
		~FragTrap();

		FragTrap	&operator=(const FragTrap &rhs);

		void	attack(const std:: string &target);
		void	highFivesGuys(void);
};

#endif
