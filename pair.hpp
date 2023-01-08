/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:01:08 by athirion          #+#    #+#             */
/*   Updated: 2023/01/08 16:46:18 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {	

	template < class T1, class T2 >
	struct pair {

		typedef T1	first_type;
		typedef T2	second_type;

		T1 first;
		T2 second;

		pair(void);
		pair(const T1& x, const T2& y);

		template < class U1, class U2 >
		pair( const pair < U1, U2 >& p);

		~pair(void);

		pair& operator=(const pair& other);

	};

	template < class T1, class T2 >
	bool operator==(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs);

	template < class T1, class T2 >
	bool operator!=(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs);

	template < class T1, class T2 >
	bool operator<(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs);

	template < class T1, class T2 >
	bool operator<=(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs);

	template < class T1, class T2 >
	bool operator>(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs);

	template < class T1, class T2 >
	bool operator>=(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs);

}

#endif
