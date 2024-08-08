/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:38:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/08 11:12:11 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed(0) {
}

Fixed::~Fixed(void) {
}

Fixed::Fixed(const int int_val) {
	this->setRawBits(int_val << this->_partitional_bits);
}

Fixed::Fixed(const float float_val) {
	this->setRawBits(roundf(float_val * (1 << this->_partitional_bits)));
}

Fixed::Fixed(const Fixed &cpy) {
	*this = cpy;
}

Fixed	&Fixed::operator=(const Fixed &rhs) {
	this->_fixed = rhs.getRawBits();
	return *this;
}


bool	Fixed::operator>(const Fixed &rhs) const {
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<(const Fixed &rhs) const {
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=(const Fixed &rhs) const {
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=(const Fixed &rhs) const {
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator==(const Fixed &rhs) const {
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(const Fixed &rhs) const {
	return (this->toFloat() != rhs.toFloat());
}

float	Fixed::operator+(const Fixed &rhs) const {
	return (this->toFloat() + rhs.toFloat());
}

float	Fixed::operator-(const Fixed &rhs) const {
	return (this->toFloat() - rhs.toFloat());
}

float	Fixed::operator*(const Fixed &rhs) const {
	return (this->toFloat() * rhs.toFloat());
}

float	Fixed::operator/(const Fixed &rhs) const {
	return (this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++(void) {
	++_fixed;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	old = *this;

	++_fixed;
	return (old);
}

Fixed	&Fixed::operator--(void) {
	--_fixed;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	old = *this;

	++_fixed;
	return (old);
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

Fixed			&Fixed::min(Fixed &a, Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed		&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed			&Fixed::max(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed		&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &o, const Fixed &Fixed) {
	o << Fixed.toFloat();
	return o;
}
