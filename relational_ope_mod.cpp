#include "common.hpp"
#include "vector.hpp"
/* #include <vector> */
/* #include "doc/ft_astrid/includes/vector.hpp" */

/* #define TESTED_NAMESPACE std */
#define TESTED_NAMESPACE ft
#define TESTED_TYPE int

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2(4);

	static int i = 0;

	/* cmp(vct, vct);  // 0 */
	/* cmp(vct, vct2); // 1 */

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (vct == vct) << " | ne: " << (vct != vct) << std::endl;
	std::cout << "lt: " << (vct <  vct) << " | le: " << (vct <= vct) << std::endl;
	std::cout << "gt: " << (vct >  vct) << " | ge: " << (vct >= vct) << std::endl;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (vct == vct2) << " | ne: " << (vct != vct2) << std::endl;
	std::cout << "lt: " << (vct <  vct2) << " | le: " << (vct <= vct2) << std::endl;
	std::cout << "gt: " << (vct >  vct2) << " | ge: " << (vct >= vct2) << std::endl;
	
	vct2.resize(10);
	
	/* cmp(vct, vct2); // 2 */
	/* cmp(vct2, vct); // 3 */

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (vct == vct2) << " | ne: " << (vct != vct2) << std::endl;
	std::cout << "lt: " << (vct <  vct2) << " | le: " << (vct <= vct2) << std::endl;
	std::cout << "gt: " << (vct >  vct2) << " | ge: " << (vct >= vct2) << std::endl;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (vct2 == vct) << " | ne: " << (vct2 != vct) << std::endl;
	std::cout << "lt: " << (vct2 <  vct) << " | le: " << (vct2 <= vct) << std::endl;
	std::cout << "gt: " << (vct2 >  vct) << " | ge: " << (vct2 >= vct) << std::endl;

	vct[2] = 42;

	/* cmp(vct, vct2); // 4 */
	/* cmp(vct2, vct); // 5 */

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (vct == vct2) << " | ne: " << (vct != vct2) << std::endl;
	std::cout << "lt: " << (vct <  vct2) << " | le: " << (vct <= vct2) << std::endl;
	std::cout << "gt: " << (vct >  vct2) << " | ge: " << (vct >= vct2) << std::endl;
	
	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (vct2 == vct) << " | ne: " << (vct2 != vct) << std::endl;
	std::cout << "lt: " << (vct2 <  vct) << " | le: " << (vct2 <= vct) << std::endl;
	std::cout << "gt: " << (vct2 >  vct) << " | ge: " << (vct2 >= vct) << std::endl;

	swap(vct, vct2);

	/* cmp(vct, vct2); // 6 */
	/* cmp(vct2, vct); // 7 */

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (vct == vct2) << " | ne: " << (vct != vct2) << std::endl;
	std::cout << "lt: " << (vct <  vct2) << " | le: " << (vct <= vct2) << std::endl;
	std::cout << "gt: " << (vct >  vct2) << " | ge: " << (vct >= vct2) << std::endl;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (vct2 == vct) << " | ne: " << (vct2 != vct) << std::endl;
	std::cout << "lt: " << (vct2 <  vct) << " | le: " << (vct2 <= vct) << std::endl;
	std::cout << "gt: " << (vct2 >  vct) << " | ge: " << (vct2 >= vct) << std::endl;




	
	return (0);
}
