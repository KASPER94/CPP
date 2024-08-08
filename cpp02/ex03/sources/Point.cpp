/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:06:55 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/08 19:40:40 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	"Point.hpp"

Point::Point(): _x(0), _y(0) {

}

Point::Point(const float x, const float y): _x(x), _y(y){

}

Point::Point(const Point &cpy): _x(cpy._x), _y(cpy._y) {

}

Point::~Point() {

}

Point &Point::operator=(Point &rhs) {
	return rhs;
}


Fixed	Point::getX(void) const {
	return (this->_x);
}

Fixed	Point::getY(void) const {
	return (this->_y);
}

std::ostream &operator<<(std::ostream &o, const Point &Point) {
	o << "(" << Point.getX() << " , " << Point.getY() << ")";
	return (o);
}
