/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:58:30 by athirion          #+#    #+#             */
/*   Updated: 2023/01/08 15:31:43 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft {

	template < class InputI1, class InputI2 >
	bool pred(const InputI1 &a, const InputI1 &b) {
		return (a == b);
	}

	template < class InputI1, class InputI2 >
	bool equal(InputI1 first1, InputI1 last1, InputI2 first2) {
		
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return (false);
			}
		}
		return (true);
	}


	template < class InputI1, class InputI2, class BinaryPredicate >
	bool equal(InputI1 first1, InputI1 last1, InputI2 first2, BinaryPredicate pred) {
	
		for (; first1 != last1; ++first1, ++first2) {
			if (!pred(*first1, *first2)) {
				return (false);
			}
		}
		return (true);
	}
}

#endif
