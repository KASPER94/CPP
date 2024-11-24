/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/24 17:59:50 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe &cpy) {
	*this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	this->main_container = rhs.main_container;
	this->pair_ui = rhs.pair_ui;
	this->pair_container = rhs.pair_container;
	return (*this);
}

void	PmergeMe::sortPairVector() {
	int odd = this->main_container.size() % 2;

	this->pair_container.reverse(this->main_container.size() / 2);
	std::vector<ui>::iterator it = main_container.begin();
	for (; _it != main_container.end() - odd; it += 2) {
		if (*it < *(it + 1))
			this->pair_ui.push_back(std::pair<ui, ui>(*it, *(it + 1)));
		else
			this->pair_ui.pusb_back(std::pair<ui, ui>(*(it + 1), *it));
	}
}

void	PmergeMe::mergeSortPairVector() {
	std::vector<std::pair<ui, ui>> tmp = this->pair_container;
	int	mid = tmp.size / 2;
	ui i = 0, j = 0, k = 0;

	if (tmp.size() < 2)
		return ;
	
}

void	PmergeMe::sortVector(const std::vector<ui> &vec) {
	this->main_container = vec;
	this->sortPairVector();
	this->mergeSortPairVector();
}
	