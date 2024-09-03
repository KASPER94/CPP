/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:49:37 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/03 11:13:32 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

class Character : public ICharacter {
	protected:
		std::string name;
		AMateria	*inventory[4];

	public:
		Character();
		Character(std::string name);
		Character(const Character &cpy);
		virtual ~Character();

		Character &operator=(const Character &rhs);

		const std::string &getName() const;
		void 		equip(AMateria *m);
		void 		unequip(int idx);
		void 		use(int idx, ICharacter &target);
		AMateria	*saveMateria(int idx);
};

std::ostream&	operator<<(std::ostream& stream, Character const& cl);

#endif