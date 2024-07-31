/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:16:03 by skapersk          #+#    #+#             */
/*   Updated: 2024/07/31 11:32:13 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOO_H
# define PHONEBOOK_H

# include "Contact.hpp"

class	PhoneBook {
	private:
		Contact			_contacts[8];
		unsigned int	_nb_contacts;

		void	print(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);
};

#endif