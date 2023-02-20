/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:22:53 by athirion          #+#    #+#             */
/*   Updated: 2023/02/20 14:04:03 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
/* #include "random_access_iterator.hpp" */
/* #include <iterator> */

namespace ft {

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag: public input_iterator_tag {};
	struct bidirectional_iterator_tag: public forward_iterator_tag {};
	struct random_access_iterator_tag: public bidirectional_iterator_tag {};

	template < class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	struct iterator {

		public:
		
			typedef				Distance							difference_type;
			typedef				T									value_type;
			typedef				Pointer								pointer;
			typedef				Reference							reference;
			typedef				Category							iterator_category;
	};	

    template< class iterator >
    struct iterator_traits {

		public:
	
			typedef typename 	iterator::difference_type				difference_type;
			typedef typename	iterator::value_type					value_type;
			typedef typename 	iterator::pointer						pointer;
			typedef typename 	iterator::reference						reference;
			typedef typename 	iterator::iterator_category				iterator_category;
	};

    template< class T >
    struct iterator_traits<T*> {

		public:
	
			typedef 			std::ptrdiff_t						difference_type;
			typedef 			T									value_type;
			typedef				T*									pointer;
			typedef				T&									reference;
			typedef random_access_iterator_tag					iterator_category;
	};

    template< class T >
    struct iterator_traits<const T*> {

		public:

			typedef 			std::ptrdiff_t						difference_type;
			typedef				T									value_type;
			typedef				const T*							pointer;
			typedef				const T&							reference;
			typedef random_access_iterator_tag					iterator_category;
	};

	template < class iterator >
	typename iterator_traits< iterator >::iterator_category __iterator_category(const iterator&) {
	
		return (typename iterator_traits<iterator>::iterator_category());
	}
	
}

#endif
