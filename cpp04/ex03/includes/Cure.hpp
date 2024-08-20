/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/20 20:48:22 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CURE_HPP
# define	CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(std::string const &type);
		Cure(const Cure &cpy);
		~Cure();

		Cure &operator=(const Cure &rhs);

		AMateria			*clone() const;
		void		use(ICharacter &target);
};

#endif