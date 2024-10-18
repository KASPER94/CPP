/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/18 15:37:18 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>
# include "easyfind.hpp"

template<class T, class U>
T	findVal(T first, T last, const U &val) {
	while (first != last) {
		if (*first == val)
			return (first);
		first++;
	}
	return (last);
}

template<typename T>
int *easyfind(T &container, int value) {
	typename T::iterator it = findVal(container.begin(), container.end(), value);

	if (*it == value)
		return (&(*it));
	else
		throw std::exception();
}

#endif
