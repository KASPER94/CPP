/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/24 19:27:31 by skapersk         ###   ########.fr       */
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

void 	PmergeMe::binarySearchVector() {

}

std::vector<ui> generateJacobsthalSequence(size_t n) {
    std::vector<ui> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    for (size_t i = 2; i < n; ++i) {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    }
    return jacobsthal;
}

void PmergeMe::JacobsthalGroupVector() {
	std::vector<ui> jacobsthal = generateJacobsthalSequence(pending_container.size());

    for (size_t i = 0; i < pending_container.size(); ++i) {
        ui index = jacobsthal[i];
        if (index >= main_container.size()) {
            main_container.push_back(pending_container[i]);
        } else {
			std::vector<ui>::iterator it = std::lower_bound(main_container.begin(), main_container.end(), pending_container[i]);
            main_container.insert(it, pending_container[i]);
        }
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
	