/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/03 11:05:12 by skapersk         ###   ########.fr       */
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
		virtual ~Cure();

		Cure &operator=(const Cure &rhs);

		virtual AMateria			*clone() const;
		virtual void		use(ICharacter &target);
};

#endif