/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/26 17:14:48 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <sys/time.h>
# include <set>
# include <algorithm>

typedef unsigned int ui;

class PmergeMe {
	private:
		std::vector<ui> main_container;
		std::vector<ui> pending_container;
		std::vector<std::pair<ui, ui> >	pair_container;

		std::list<ui> main_list;
		std::list<ui> pending_list;
		std::list<std::pair<ui, ui> > pair_list;

		void							sortPairVector();
		std::vector<std::pair<ui, ui> >	mergeSortPairVector(std::vector<std::pair<ui, ui> > tmp);
		void							prepareForBinarySearchVector();
		void							JacobsthalGroupVector();

		void sortPairList();
		std::list<std::pair<ui, ui> > mergeSortPairList(std::list<std::pair<ui, ui> > tmp);
		void prepareForBinarySearchList();
		void JacobsthalGroupList();

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cpy);

		PmergeMe &operator=(const PmergeMe &rhs);
		void	sortVector(const std::vector<ui> &vec);
		void	printVector(ui nb);
		void	sortList(const std::list<ui> &lst);
		void	printList(ui nb);
};

#endif
