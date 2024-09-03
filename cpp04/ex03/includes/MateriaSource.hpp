/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:54:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/03 01:49:52 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*saved_materias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &cpy);
		virtual ~MateriaSource();

		MateriaSource &operator=(const MateriaSource &rhs);

		virtual void		learnMateria(AMateria*);
		virtual AMateria	*createMateria(const std::string &type);
};

#endif