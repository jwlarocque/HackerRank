#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


std::vector<int> vectorFromInput(int items)
{
	std::vector<int> vOut(items);
	int temp;

	for (int index = 0; index < items; index++) {
		std::cin >> temp;
		vOut[index] = temp;
	}
	return vOut;
}

std::string cancelled(int threshold, std::vector<int> times) {
    for (int index = 0; index < times.size(); index++) {
        if (times[index] <= 0) {
            threshold--;
        }
    }
    if (threshold <= 0) {
        return "NO";
    }
    return "YES";
}

int main()
{
    int cases;
    std::cin >> cases;
    int threshold;
    int numStudents;
    
    for (int test = 0; test < cases; test++) {
        std::cin >> numStudents;
        std::cin >> threshold;
        std:: cout << cancelled(threshold, vectorFromInput(numStudents)) << std::endl;
    }
    
    return 0;
}