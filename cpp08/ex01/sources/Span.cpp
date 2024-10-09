/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/10 00:55:08 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() {
    
}

Span::Span(const unsigned int N): _Max(N), _Count(0), _Shortest(0), _Longest(0) {

}

Span::Span(const Span &cpy): _Input(cpy._Input), _Max(cpy._Max), _Count(cpy._Count), _Shortest(cpy._Shortest), _Longest(cpy._Longest) {

}

Span::~Span() {}

Span	&Span::operator=(const Span &rhs) {
    if (this == &rhs)
        return (*this);
    this->_Max = rhs._Max;
    this->_Count = rhs._Count;
    this->_Shortest = rhs._Shortest;
    this->_Longest = rhs._Longest;
    this->_Input = rhs._Input;
    return (*this);
}

bool    Span::checkLimits(const int _Count, const int _Max) {
    if (_Count == _Max)
        throw Span::SpanLimitReached();
    return (true);
}

void    Span::addNumber(const int nb) {
    try {
        checkLimits(this->_Count, this->_Max);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    this->_Count++;
    this->_Input.push_back(nb);
}

unsigned int Span::shortestSpan(void) {
    if (this->_Input.size() <= 1)
		throw SpanNotEnoughItems();
    std::vector<int> tmp = this->_Input;
    std::sort(tmp.begin(), tmp.end());
    this->_Shortest = *(tmp.begin() + 1) - tmp.front();
    if (this->_Shortest == 0)
        return (0);
    for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end() - 1; it++) {
        if (static_cast<unsigned long>(*(it + 1) - *it) < this->_Shortest) {
            this->_Shortest = *(it + 1) - *it;
            this->_tmpIt = *it;
            this->_tmpIt2 = *(it + 1);
            if (this->_Shortest == 0)
                return (0);
        }
    }
    return (this->_Shortest);
}

unsigned int Span::longestSpan(void) {
    if (this->_Input.size() <= 1)
        throw SpanNotEnoughItems();
    this->_Longest = *std::max_element((this->_Input.begin()), (this->_Input.end()))
        - *std::min_element((this->_Input.begin()), (this->_Input.end()));
    return (this->_Longest);
}

const char *Span::SpanNotEnoughItems::what() const throw() {
    return ((char*)"Span has only one item");
}

const char *Span::SpanLimitReached::what() const throw() {
    return ((char*)"Span's limit reached !");
}
