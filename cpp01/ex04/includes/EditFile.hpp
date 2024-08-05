/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EditFile.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:03 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 14:32:03 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITFILE_HPP
# define EDITFILE_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <sys/stat.h>
# include <string>

# define FAILURE 1
# define SUCCESS 0

class EditFile {
	private:
		std::string		_file_name;
		std::string		_new_file_name;
		std::string		_replace_from;
		std::string		_replace_to;
		std::string		_content;

		std::ifstream	_file_in;
		std::ofstream	_file_out;
	
	public:
		EditFile(std::string name, std::string s1, std::string s2);
		~EditFile();
		
		std::string	getFileName(void);
		std::string	getNewFileName(void);
		int			readIn(void);
		int			writeOut(void);
};

#endif