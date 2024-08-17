/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:22:51 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/17 22:26:22 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &cpy);
		virtual ~Animal();

		Animal	&operator=(const Animal &rhs);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif