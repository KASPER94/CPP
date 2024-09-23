/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 22:47:51 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &cpy);
		Serializer &operator=(const Serializer &rhs);
		
	public:
		static uintptr_t serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);
};

#endif