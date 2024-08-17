/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:08:51 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/13 18:51:02 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain &cpy);
		~Brain();

		Brain	&operator=(const Brain &rhs);
		void	setIdea(unsigned int i, std::string idea);
		void	getIdea(void);
};

#endif
