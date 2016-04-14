#include <cmath>
#include <cstdio>
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

int main()
{
	int size;
	std::cin >> size;

	std::vector<int> integers = vectorFromInput(size);
	int numPos = 0;
	int numZero = 0;
	int numNeg = 0;

	for (int index = 0; index < size; index++) {
		if (integers[index] > 0) {
			numPos++;
		} else if (integers[index] < 0) {
			numNeg++;
		} else {
			numZero++;
		}
	}

	std::cout << std::fixed << std::setprecision(6);

	std::cout << (double)numPos / (double)(size) << "\n";
	std::cout << (double)numNeg / (double)(size) << "\n";
	std::cout << (double)numZero / (double)(size) << "\n";
	return 0;
}