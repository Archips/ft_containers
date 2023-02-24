#include "../includes/common_map.hpp"
/* #include "../includes/map.hpp" */
#include <map>

#define T1 int
#define T2 int
/* #define TESTED_NAMESPACE ft */
#define TESTED_NAMESPACE std

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> const mp;
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(); // <-- error expected

	(void)it;
	return (0);
}
