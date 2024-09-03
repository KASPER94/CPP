/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/03 11:05:07 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICE_HPP
# define	ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(std::string const &type);
		Ice(const Ice &cpy);
		virtual ~Ice();

		Ice &operator=(const Ice &rhs);

		virtual AMateria			*clone() const;
		virtual void		use(ICharacter &target);
};

#endif