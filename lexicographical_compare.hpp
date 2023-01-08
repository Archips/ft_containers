/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:40:06 by athirion          #+#    #+#             */
/*   Updated: 2023/01/08 15:51:54 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE
# define LEXICOGRAPHICAL_COMPARE

namespace ft {

	template < class InputI1, class InputI2 >
	bool cmp(const InputI1 &a, InputI2 &b) {
		return (a < b);
	}

	template < class InputI1, class InputI2 >
	bool lexicographical_compare(InputI1 first1, InputI1 last1, InputI2 first2, InputI2 last2) {

		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}
	
	template < class InputI1, class InputI2, class Compare > 
	bool lexicographical_compare(InputI1 first1, InputI1 last1, InputI2 first2, InputI2 last2, Compare comp) {

		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (comp(*first1, first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}
}

#endif
