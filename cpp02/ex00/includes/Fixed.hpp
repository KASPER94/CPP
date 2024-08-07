/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:35:48 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/07 11:43:56 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_fixed;
		const static int	_partitional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &cpy);
		~Fixed();
		Fixed &operator=(const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
