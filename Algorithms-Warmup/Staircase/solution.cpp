#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


/* You might be wondering, at this point, why I have a folder for every problem
 * (instead of simply naming the cpp files something reasonable).  There are some
 * files ignored by git, and not submitted, which are nice to have in their own folders.
 * Also I'm in a bit of a folder phase.
 */

int main()
{
	int height;
	std::cin >> height;

	for (int index = 1; index <= height; index++) {
		std::cout << std::string(height - index, ' ');
		std::cout << std::string(index, '#') << "\n";
	}

	return 0;
}