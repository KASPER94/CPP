/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/20 20:48:27 by skapersk         ###   ########.fr       */
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
		~Ice();

		Ice &operator=(const Ice &rhs);

		AMateria			*clone() const;
		void		use(ICharacter &target);
};

#endif