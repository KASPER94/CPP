/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:27:13 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/17 22:53:21 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &cpy);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &rhs);
		void	makeSound() const;
		std::string	getType() const;
};

#endif