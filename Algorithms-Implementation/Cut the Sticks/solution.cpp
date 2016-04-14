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

int printVector(std::vector<int> arr)
{
    std::cout << "[";
    for (int index = 0; index < arr.size(); index++) {
        std::cout << arr[index] << ", ";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}

int minInVector(std::vector<int> arr)
{
    int minimum = arr[0];
    for (int index = 1; index < arr.size(); index++) {
        if (arr[index] < minimum) {
            minimum = arr[index];
        }
    }
    return minimum;
}

int main()
{
    int length, smallest;
    std::cin >> length;
    std::vector<int> arr = vectorFromInput(length);
    while (arr.size() > 0) {
        std::cout << length << std::endl;
        smallest = minInVector(arr);
        for (int index = 0; index < length; index++) {
            if (arr[index] == smallest) {
                arr.erase(arr.begin() + index);
                length--;
                index--;
            } else {
                arr[index] = arr[index] - smallest;
            }
        }
    }
    return 0;
}