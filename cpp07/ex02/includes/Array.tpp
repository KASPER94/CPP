/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:20:26 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/24 22:46:23 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<class T>
Array<T>::Array(void): _size(0), _array(NULL) {
	try {
		this->_array = new T[];
	}
	catch(std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}
}

template<class T>
Array<T>::Array(unsigned int n): _size(n), _array(NULL) {
	try {
		this->_array = new T[this->_size];
	}
	catch(std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}
}

template<class T>
Array<T>::Array(const Array &cpy): _size(0), _array(NULL) {
	*this = cpy;
}

template<class T>
Array<T>::~Array() {
	delete [] this->_array;
}

template<class T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	this->_size = rhs._size;
	if (this->_array)
		delete [] this->_array;
	try {
		this->_array = new T[rhs._size];
		for (size_t i = 0; i < rhs._size; i++){
			this->_array[i] = rhs._array[i];
 		}
 	}
	catch(std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}
	return (*this);
}

template<class T>
T &Array<T>::operator[](const unsigned int n) {
	if (n >= this->_size) {
		throw OutofBound();
	}
	return (this->_array[n]);
}

template<class T>
unsigned int Array<T>::size(void) const {
	return (this->_size);
}

template<class T>
const char *Array<T>::OutofBound::what() const throw() {
	return ((char*) "Error: Index is out of bounds.");
}

