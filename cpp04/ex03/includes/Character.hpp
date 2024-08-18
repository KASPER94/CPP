/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:49:37 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/19 00:01:04 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria	*inventory[4];

	public:
		Character();
		Character(std::string name);
		Character(const Character &cpy);
		~Character();

		Character &operator=(const Character &rhs);

		const std::string &getName() const;
		void 		equip(AMateria *m);
		void 		unequip(int idx);
		void 		use(int idx, ICharacter &target);
		AMateria	*saveMateria(int idx);
};

#endif