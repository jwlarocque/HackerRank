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

// because it is a precondition, assume value is in array
int indexOfSorted(int value, std::vector<int> array) {
    int startIndex = 0;
    int endIndex = array.size() - 1;
    int currentIndex;
    while (1) {
        currentIndex = (endIndex + startIndex) / 2;
        if (array[currentIndex] == value) {
            return currentIndex;
        } else if (array[currentIndex] < value) {
            startIndex = currentIndex + 1;
        } else {
            endIndex = currentIndex - 1;
        }
    }
    return -1;
}

int main()
{
    int value, size;
    std::cin >> value >> size;
    std::cout << indexOfSorted(value, vectorFromInput(size)) << std::endl;
    
    return 0;
}