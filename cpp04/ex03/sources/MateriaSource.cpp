/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:54:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/18 23:59:46 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*saved_materias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &cpy);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &rhs);

		void		learnMateria(AMateria*);
		AMateria	*createMateria(const std::string &type);
}

#endif