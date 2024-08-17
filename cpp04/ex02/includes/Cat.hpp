/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:21:33 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/17 22:53:32 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(const Cat &cpy);
		~Cat();

		Cat &operator=(const Cat &rhs);
		void	makeSound(void) const;
		void	setIdea(unsigned int i, std::string idea);
		void	getIdea(void) const;
};

#endif
