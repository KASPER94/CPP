/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:35:48 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/06 19:18:59 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <fstream>
# include <string>

class Fixed {
	private:

	public:
		Fixed();
		Fixed(const Fixed &cpy);
		~Fixed();
		Fixed &operator=(const Fixed &rhs);
};

#endif
