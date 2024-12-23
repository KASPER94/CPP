/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:59 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/27 23:59:58 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	ltrim(std::string &str) {
	int	i = 0;

	if (str.length() == 0)
		return ;
	while (isspace(str[i]))
		i++;
	str = str.substr(i, str.length());
}

static void	rtrim(std::string &str) {
	int	i = str.length() - 1;

	if (str.length() == 0)
		return ;
	while (isspace(str[i]))
		i--;
	str = str.substr(0, i + 1);
}

static bool checkOverflow(std::string str) {
	if (str[0] == '+') {
		if (str.length() > 11)
			return (true);
		else if (str.length() == 11 && str.compare("+4294967295") > 0)
			return (true);
	}
	else {
		if (str.length() > 10)
			return (true);
		else if (str.length() == 10 && str.compare("4294967295") > 0)
			return (true);
	}
	return (false);
}

static bool checkInt(std::string str) {
	size_t i = 0;

	ltrim(str);
	rtrim(str);
	if (str[0] == '+')
		i++;
	for (; i < str.length(); i++) {
		if (isdigit(str[i])) {
			continue ;
		} else {
			return (false);
		}
	}
	return (!checkOverflow(str));
}

static bool hasDuplicates(std::vector<unsigned int> &entries) {
	std::set<unsigned int> s(entries.begin(), entries.end());
	return (s.size() != entries.size());
}

static unsigned long  getTime()
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return (time.tv_usec + time.tv_sec * 1000000);
}

static std::string dtoa(double nb) {
	std::ostringstream s;
	std::string str;

	s << std::setprecision(3) << std::fixed << nb;
	str = s.str();
	str = str.erase(str.find_last_not_of('0') + 1);
	if (str[str.length() - 1] == '.')
		str += "0";
	return (str);
}

template <typename container>
static void	printEntries(const container &cont, unsigned int maxLen) {
	typename container::const_iterator it = cont.begin();
	size_t count = 0;
	for (; it != cont.end() && count < maxLen; ++it, ++count) {
		std::cout << *it << " ";
	}
	if (cont.size() > maxLen) {
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

template <typename Container>
void printContainer(const Container &container, unsigned int maxLen) {
    typename Container::const_iterator it = container.begin();
    size_t count = 0;

    for (; it != container.end() && count < maxLen; ++it, ++count) {
        std::cout << *it << " ";
    }
    if (container.size() > maxLen) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

template <typename container>
static void sort(PmergeMe &pmm, const container entries) {
	unsigned long vecIn, vecOut;
	unsigned long listIn, listOut;

	std::cout << "sorting Vector... " << std::endl;
	vecIn = getTime();
	std::vector<ui> vecEntries(entries.begin(), entries.end());
	pmm.sortVector(vecEntries);
	vecOut = getTime();
	std::cout << "Done." << std::endl;

	std::cout << "Before : ";
	printEntries(vecEntries, 20);
	std::cout << "After :  ";
	printContainer(pmm.getVec(), 20);
	std::cout << "Time to process a range of " << entries.size();
	std::cout << " elements: " << vecOut - vecIn;
	std::cout << " µs (";
	std::cout << dtoa(static_cast<double>(vecOut - vecIn) / 1000000.0) << " s)\n" << std::endl;
	std::cout << std::endl;

	std::cout << "sorting List... " << std::endl;
	listIn = getTime();
	std::list<ui> listEntries(entries.begin(), entries.end());
	pmm.sortList(listEntries);
	listOut = getTime();
	std::cout << "Done. " << std::endl;

	std::cout << "Before : ";
	printEntries(listEntries, 20);
	std::cout << "After :  ";
	printContainer(pmm.getList(), 20);
	std::cout << "Time to process a range of " << entries.size();
	std::cout << " elements: " << listOut - listIn;
	std::cout << " µs (";
	std::cout << dtoa(static_cast<double>(listOut - listIn) / 1000000.0) << " s)\n" << std::endl;
}

int	main(int ac, char **av) {
	PmergeMe pmm;
	std::vector<unsigned int> entries;
	int i = 0;

	if (ac == 1) {
		std::cerr << "Error: Wrong entries. you can use ./PmergeMe `shuf -i 1-100000 -n 3000 | tr \"\\n\" \" \"`" << std::endl;
		return (1);
	}
	std::cout << "Verifying the input array..." << std::endl;
	while (av[++i]) {
		if (!checkInt(av[i])) {
			std::cerr << " ❌ " << av[i] << " is not an unsigned integer" << std::endl;
			return (1);
		}
		entries.push_back(std::atoi(av[i]));
	}
	if (hasDuplicates(entries)) {
		std::cerr << " ❌ " << av[i] << " has a duplicate" << std::endl;
		return (1);
	}
	std::cout << " ✅  All arguments are unsigned long and there is no duplicates" << std::endl;
	std::cout << "\nStarting sortings..." << std::endl;
	sort(pmm, entries);
	return (0);
}
