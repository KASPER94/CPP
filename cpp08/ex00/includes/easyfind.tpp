/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/18 12:05:08 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>
# include "easyfind.hpp"

template<class T, class U>
T	find(T first, T last, const U &val) {
	while (first != last) {
		if (*first == val)
			return (first);
		first++;
	}
	return (last);
}

template<typename T>
int *easyfind(T &container, int value) {
	typename T::iterator it = find(container.begin(), container.end(), value);

	if (*it == value)
		return (&(*it));
	else
		throw std::exception();
}

#endif
