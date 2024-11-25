/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/25 14:03:44 by skapersk         ###   ########.fr       */
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
	this->pending_container = rhs.pending_container;
	return (*this);
}

void	PmergeMe::sortPairVector() {
	int odd = this->main_container.size() % 2;

	this->pair_container.reserve(this->main_container.size() / 2);
	std::vector<ui>::iterator it = main_container.begin();
	for (; it != main_container.end() - odd; it += 2) {
		if (*it < *(it + 1))
			this->pair_container.push_back(std::pair<ui, ui>(*it, *(it + 1)));
		else
			this->pair_container.push_back(std::pair<ui, ui>(*(it + 1), *it));
	}
}

std::vector<std::pair<ui, ui> >	PmergeMe::mergeSortPairVector(std::vector<std::pair<ui, ui> > tmp) {
	int	mid = tmp.size() / 2;
	ui i = 0, j = 0, k = 0;

	if (tmp.size() < 2)
		return tmp;
	std::vector<std::pair<ui, ui> > left(tmp.begin(), tmp.begin() + mid);
	std::vector<std::pair<ui, ui> > rigth(tmp.begin() + mid, tmp.end());
	left = this->mergeSortPairVector(left);
	rigth = this->mergeSortPairVector(rigth);
	while (i < left.size() && j < rigth.size()) {
		if (left[i].second < rigth[j].second) {
			tmp[k] = left[i];
			i++;
		}
		else {
			tmp[k] = rigth[j];
			j++;
		}
		k++;
	}
	while (i < left.size()) {
		tmp[k] = left[i];
		i++;
		k++;
	}
	while (j < rigth.size()) {
		tmp[k] = rigth[j];
		j++;
		i++;
	}
	return (tmp);
}

void	PmergeMe::prepareForBinarySearchVector() {
	bool odd = (this->main_container.size() % 2) == 1;
	ui last = 0;
	ui size = this->main_container.size();

	if (odd) {
		last = this->main_container.back();
	}
	this->pending_container.reserve(size / 2 + static_cast<int>(odd));
	this->main_container.clear();
	this->main_container.reserve(size);
	this->main_container.push_back(this->pair_container.begin()->first);
	for (ui i = 0; i < this->pair_container.size(); i++) {
		this->main_container.push_back(this->pair_container[i].second);
		if (i != 0)
			this->pending_container.push_back(this->pair_container[i].first);
	}
	if (odd) {
		this->pending_container.push_back(last);
	}
}

void PmergeMe::JacobsthalGroupVector() {
    static unsigned long jacobsthal_diff[] = {
        2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922,
        21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202,
        5592406, 11184810, 22369622, 44739242, 89478486, 178956970,
        357913942, 715827882, 1431655766, 2863311530
    };
	std::vector<ui>::iterator it;
	int x = 1, y = 0, i = 0;
	int xMax, yMax;
	
	while (static_cast<unsigned long>(yMax) > this->pending_container.size()) {
		unsigned long dist = jacobsthal_diff[i];
		yMax = y + dist;
		xMax = x + dist;
		while (yMax-- != y) {
			it = std::lower_bound(main_container.begin(), main_container.begin() + xMax, pending_container[yMax]);
			main_container.insert(it, pending_container[yMax]);
		}
		x += dist * 2;
		y += dist;
	}
	yMax = pending_container.size();
	while (yMax-- != y) {
		it = std::lower_bound(main_container.begin(), main_container.begin() + xMax, pending_container[yMax]);
		main_container.insert(it, pending_container[yMax]);	
	}
}

void	PmergeMe::printVector(ui nb) {
	ui	size = this->main_container.size();

	for (unsigned int i = 0; i < this->main_container.size() && i < nb; i++) {
		std::cout << this->main_container[i] << " ";
    }
	if (size > nb)
		std::cout << "[...]";
}

void	PmergeMe::sortVector(const std::vector<ui> &vec) {
	this->main_container = vec;
	this->sortPairVector();
	this->pair_container = this->mergeSortPairVector(this->pair_container);
	this->prepareForBinarySearchVector();
	this->JacobsthalGroupVector();
}
	