/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:21:33 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/17 22:53:26 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(const Dog &cpy);
		~Dog();

		Dog &operator=(const Dog &rhs);
		void	makeSound(void) const;
		void	setIdea(unsigned int i, std::string idea);
		void	getIdea(void) const;
};

#endif
