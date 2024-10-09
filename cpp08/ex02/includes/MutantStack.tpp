/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/10 01:26:15 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {

}

template <typename T>
MutantStack<T>::~MutantStack() {
	
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &cpy): std::stack<T>(cpy) {
	
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &rhs) {
	std::stack<T>::operator=(rhs);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return (this->c.begin());
};

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return (this->c.end());
};


#endif