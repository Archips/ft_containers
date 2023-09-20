# ft_containers

This project is a C++ implementation of several containers from the Standard Template Library (STL). The primary goal is to create custom versions of these containers while adhering to the structure and conventions of the original containers. The project follows the C++98 standard and aims to provide C++98 features, excluding any newer functionalities. Additionally, it includes some fundamental C++11 features, like SFINAE, to deepen your understanding of template metaprogramming.

## Score

-  125%

## Project Highlights

- Implements custom versions of the following STL containers: vector, map, and stack.
- The map container utilizes the custom vector class as its default underlying container but remains compatible with other STL containers.
- Optional bonus: Implement the set container using a red-black tree.
- Provides custom implementations of essential C++11 features, including std::iterators_traits, std::reverse_iterator, std::enable_if, std::is_integral, std::equal/std::lexicographical_compare, std::pair, and std::make_pair.
- Adheres to naming conventions, follows namespace ft, and maintains a coherent and justifiable internal data structure for each container.
- Limits the number of public functions to match those of standard containers, with additional functions being private or protected as needed.
- Implements all required member functions, non-member functions, and overloads for each container.
- Utilizes std::allocator and allows the use of the friend keyword for non-member overloads, with strict justification and evaluation.
- Includes an optional set container, which is required to use a red-black tree.

## Usage

To use these custom containers in your C++ project, follow these steps:

1. Clone the GitHub repository to your local machine.
2. Include the necessary container header files in your C++ code, e.g., `#include "vector.hpp"`, `#include "map.hpp"`, or `#include "stack.hpp"`.
3. Instantiate the containers with the desired data types and start using them as you would with STL containers.

## Author

[Archibald Thirion](https://github.com/Archips)
