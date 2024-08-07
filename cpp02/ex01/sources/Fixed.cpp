/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:38:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/07 18:30:19 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int int_val) {
	std::cout << "Ini constuctor called" << std::endl;
	this->setRawBits(int_val << this->_partitional_bits);
}

Fixed::Fixed(const float float_val) {
	std::cout << "Float constuctor called" << std::endl;
	this->setRawBits(roundf(float_val * (1 << this->_partitional_bits)));
}

Fixed::Fixed(const Fixed &cpy) {
	std::cout << "Copy constuctor called" << std::endl;
	*this = cpy;
}

Fixed	&Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = rhs.getRawBits();
	return *this;
}

float	Fixed::toFloat(void) const {
	return (this->getRawBits() / (float)(1 << this->_partitional_bits));
}

int		Fixed::toInt(void) const {
	return (this->getRawBits() >> this->_partitional_bits);
}

int	Fixed::getRawBits(void) const {
	return (this->_fixed);
}

void	Fixed::setRawBits(const int raw) {
	this->_fixed = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &Fixed) {
	o << Fixed.toFloat();
	return o;
}
