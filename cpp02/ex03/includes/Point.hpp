/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:35:48 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/08 19:32:09 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point();
		Point(const float _x, const float _y);
		Point(const Point &cpy);
		~Point();

		Point &operator=(Point &rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

std::ostream& operator<<(std::ostream &o, const Point &Point);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
