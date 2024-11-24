/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/24 17:56:52 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <cstdlib>
# include <sys/time.h>
# include <set>

typedef unsigned int ui;

class PmergeMe {
	private:
		std::vector<ui> main_container;
		std::vector<std::pair<ui, ui>>	pair_container;
		std::pair<ui, ui> pair_ui;
		
		void	sortPairVector();
		void	mergeSortPairVector();
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cpy);

		PmergeMe &operator=(const PmergeMe &rhs);
		void	sortVector();
		void	printVector(unsigned int nb); 
};

#endif