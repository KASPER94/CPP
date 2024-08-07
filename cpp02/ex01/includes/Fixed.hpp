/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:35:48 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/07 18:18:37 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_fixed;
		const static int	_partitional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &cpy);
		~Fixed();
		Fixed(const int int_val);
		Fixed(const float float_val);
		Fixed &operator=(const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream &o, const Fixed &Fixed);

#endif
