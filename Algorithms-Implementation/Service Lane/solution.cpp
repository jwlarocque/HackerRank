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

int minInRange(int start, int end, std::vector<int> arr) {
    int minimum = arr[start];
    for (int index = start + 1; index <= end; index++) {
        if (arr[index] < minimum) {
            minimum = arr[index];
        }
    }
    return minimum;
}

int main()
{
    int length, cases, start, end;
    std::cin >> length >> cases;
    std::vector<int> serviceWidth = vectorFromInput(length);
    
    for (int test = 0; test < cases; test++) {
        std::cin >> start >> end;
        std::cout << minInRange(start, end, serviceWidth) << std::endl;
    }
    
    return 0;
}