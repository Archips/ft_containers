/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:23:19 by athirion          #+#    #+#             */
/*   Updated: 2023/01/09 10:23:20 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

# include "pair.hpp"

namespace ft {

    template < class T1, class T2 >
    ft::pair< T1, T2 > make_pair(T1 t, T2 u) {
        return (ft::pair< T1, T2 > (t, u));
    }
}

#endif
