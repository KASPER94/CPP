/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:22:51 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/11 16:11:27 by skapersk         ###   ########.fr       */
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
		Animal(const &Animal);
		virtual ~Animal();

		Animal	&operator=(const Animal &rhs);

		virtual void	makeSound();
		std::string		getType(void);
};

#endif