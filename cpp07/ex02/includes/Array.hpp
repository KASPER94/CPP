/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/24 01:19:24 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<class T>
class Array {
	private:
		unsigned int	_size;
		T				*_array;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &cpy);
		~Array();
		Array &operator=(const Array &rhs);

		T &operator[](const unsigned int n);
		unsigned int size(void) const;
		class OutofBound : public std::exception {
			public :
				const char *what() const throw();
		}
}


#endif