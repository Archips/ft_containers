#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {

    template< class Iter >
    struct iterator_traits;

    template< class T >
    struct iterator_traits<T*>;

    template< class T >
    struct iterator_traits<const T*>;



}

#endif