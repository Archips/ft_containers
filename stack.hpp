/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:33:30 by athirion          #+#    #+#             */
/*   Updated: 2023/01/06 14:09:14 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <vector>

namespace ft {

    template < class T, class Container = std::vector <T> >
    class stack {


    public:

        typedef typename Container::value_type 	value_type;
        typedef typename Container::size_type 	size_type;
        typedef Container 						container_type;

        explicit stack(const Container &cntr = Container()): c(cntr) {}

        ~stack(void){}

        // TOP

        value_type& top() {
            return (c.back());
        }

        const value_type& top() const {
            return (c.back());
        }

        // EMPTY

        bool empty() const {
            return (c.empty());
        }

        //SIZE

        size_type size() const {
            return (c.size());
        }

        //PUSH

        void push(const value_type& val) {
            c.push_back(val);
        }

        //POP

        void pop() {
            c.pop_back();
        }

		//OPERATORS

        friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
            return (lhs.c == rhs.c);
        }

        friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
            return (lhs.c < rhs.c);
        }

    protected:

        container_type c;

    };

    //RELATIONAL OPERATORS

    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (!(lhs == rhs));
    }

    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (!(rhs < lhs));
    }

    template <class T, class Container>
    bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (rhs < lhs);
    }

    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (!(lhs < rhs));
    }

}

#endif
