/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:01:47 by athirion          #+#    #+#             */
/*   Updated: 2023/02/10 13:20:07 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_HPP
# define DISTANCE_HPP

#include "iterator_traits.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "random_access_iterator.hpp"

namespace ft {

	template < class InputIterator >
	typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {

		typename ft::iterator_traits<InputIterator>::difference_type i = 0;
		for (; first != last; first++)
			i ++;
	
		return (i);
	}

}

#endif
