/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:14:20 by athirion          #+#    #+#             */
/*   Updated: 2023/01/08 14:58:51 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft {

	template <bool Cond, class T = void >
	struct enable_if {};

	template <class T>
	struct enable_if <true, T> {

		typedef T type;
	};
}

#endif
