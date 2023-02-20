/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:01:08 by athirion          #+#    #+#             */
/*   Updated: 2023/02/20 16:15:43 by athirion         ###   ########.fr       */
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

		pair(void): first(first_type()), second(second_type()) {}
		pair(const T1& x, const T2& y): first(x), second(y) {}

		template < class U1, class U2 >
		pair( const pair < U1, U2 >& p): first(p.first), second(p.second) {}

		~pair(void) {}

		pair& operator=(const pair& other) {

            if (this != &other) {
                this->first = other.first;
                this->second = other.second;
            }
            return (*this);
        }

	};

	template < class T1, class T2 >
	bool operator==(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs) {
        if (lhs.first == rhs.first && lhs.second == rhs.second)
            return (true);
        return (false);
    }

	template < class T1, class T2 >
	bool operator!=(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs) {
        return !(lhs == rhs);
    }

	template < class T1, class T2 >
	bool operator<(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs) {
        if (lhs.first < rhs.first)
            return (true);
        else if (rhs.first < lhs.first)
            return (false);
        if (lhs.second < rhs.second)
            return (true);
        return (false);
    }

	template < class T1, class T2 >
	bool operator<=(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs) {
        return (!(rhs < lhs));
    }

	template < class T1, class T2 >
	bool operator>(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs) {
        return (rhs < lhs);
    }

	template < class T1, class T2 >
	bool operator>=(const ft::pair< T1, T2 >& lhs, const ft::pair < T1, T2>& rhs) {
        return (!(lhs < rhs));
    }

}

#endif
