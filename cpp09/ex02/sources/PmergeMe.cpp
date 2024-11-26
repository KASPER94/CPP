/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/26 17:27:01 by skapersk         ###   ########.fr       */
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
	this->pair_container = rhs.pair_container;
	this->pending_container = rhs.pending_container;
	this->main_container = rhs.main_container;
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

    while (y < static_cast<int>(this->pending_container.size())) {
        unsigned long dist = jacobsthal_diff[i++];
        yMax = y + dist;
        xMax = x + dist;

        if (yMax > static_cast<int>(this->pending_container.size())) {
            yMax = this->pending_container.size();
        }
        while (yMax-- != y) {
            it = std::lower_bound(main_container.begin(), main_container.begin() + xMax, pending_container[yMax]);
            main_container.insert(it, pending_container[yMax]);
        }
        x += dist * 2;
        y += dist;
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

void PmergeMe::sortPairList() {
	std::list<ui>::iterator it = main_list.begin();
	while (it != main_list.end()) {
		std::list<ui>::iterator next_it = it;
		++next_it;
		if (next_it == main_list.end())
			break;

		if (*it < *next_it) {
			pair_list.push_back(std::make_pair(*it, *next_it));
		} else {
			pair_list.push_back(std::make_pair(*next_it, *it));
		}
		it = next_it;
		++it;
	}
}

std::list<std::pair<ui, ui> > PmergeMe::mergeSortPairList(std::list<std::pair<ui, ui> > tmp) {
	if (tmp.size() < 2)
		return tmp;

	std::list<std::pair<ui, ui> >::iterator mid = tmp.begin();
	std::advance(mid, tmp.size() / 2);

	std::list<std::pair<ui, ui> > left(tmp.begin(), mid);
	std::list<std::pair<ui, ui> > right(mid, tmp.end());

	left = mergeSortPairList(left);
	right = mergeSortPairList(right);

	std::list<std::pair<ui, ui> > result;
	std::list<std::pair<ui, ui> >::iterator it_left = left.begin();
	std::list<std::pair<ui, ui> >::iterator it_right = right.begin();

	while (it_left != left.end() && it_right != right.end()) {
		if (it_left->second < it_right->second) {
			result.push_back(*it_left);
			++it_left;
		} else {
			result.push_back(*it_right);
			++it_right;
		}
	}
	result.insert(result.end(), it_left, left.end());
	result.insert(result.end(), it_right, right.end());

	return result;
}

void PmergeMe::prepareForBinarySearchList() {
	std::list<std::pair<ui, ui> >::iterator it = pair_list.begin();
	main_list.clear();
	pending_list.clear();

	if (it != pair_list.end()) {
		main_list.push_back(it->first);
		++it;
	}
	for (; it != pair_list.end(); ++it) {
		main_list.push_back(it->second);
		pending_list.push_back(it->first);
	}
}

void PmergeMe::JacobsthalGroupList() {
	static const unsigned long jacobsthal_diff[] = {
		2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922,
		21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202
	};
	size_t y = 0, i = 0;

	while (y < pending_list.size()) {
		unsigned long group_size = jacobsthal_diff[i++];
		if (y + group_size > pending_list.size())
			group_size = pending_list.size() - y;

		std::list<ui>::iterator pending_it = pending_list.begin();
		std::advance(pending_it, y);

		for (size_t j = 0; j < group_size; ++j) {
			std::list<ui>::iterator insert_pos = std::lower_bound(
				main_list.begin(),
				main_list.end(),
				*pending_it
			);
			main_list.insert(insert_pos, *pending_it);
			++pending_it;
		}
		y += group_size;
	}
}


void PmergeMe::printList(ui nb) {
	std::list<ui>::iterator it = main_list.begin();
	size_t count = 0;

	for (; it != main_list.end() && count < nb; ++it, ++count) {
		std::cout << *it << " ";
	}
	if (main_list.size() > nb) {
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

void PmergeMe::sortList(const std::list<ui> &lst) {
	main_list = lst;
	sortPairList();
	pair_list = mergeSortPairList(pair_list);
	prepareForBinarySearchList();
	JacobsthalGroupList();
}
