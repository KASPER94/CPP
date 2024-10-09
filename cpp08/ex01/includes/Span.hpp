/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/10 00:51:08 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
	private:
		std::vector<int>	_Input;
		unsigned int		_Max;
		unsigned int		_Count;
		unsigned int		_Shortest;
		unsigned int		_Longest;

		Span();
	public:
		int					_tmpIt;	
		int					_tmpIt2;
		Span(const unsigned int N);
		Span(const Span &cpy);
		~Span();

		Span	&operator=(const Span &rhs);
		void	addNumber(const int nb);
		template <template <class T, class Allocator = std::allocator<T> > class Container>
		void	addNumber(Container<int> c);
		class SpanLimitReached: public std::exception {
			public: const char* what() const throw();
		};
		class SpanNotEnoughItems: public std::exception {
			public: const char* what() const throw();
		};
		bool    checkLimits(const int _Count, const int _Max);
		unsigned int shortestSpan();
		unsigned int longestSpan();

};



template <template <class T, class Allocator = std::allocator<T> > class Container >
void Span::addNumber(Container<int> c) {
    try {
        Span::checkLimits(this->_Count, this->_Max);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	for (typename Container<int>::iterator it = c.begin(); it != c.end(); it++) {
		addNumber(*it);
	}
}

#endif