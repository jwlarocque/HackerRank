#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// data structures...

std::vector<int> vectorFromInput(int items)
{
	// it might be better to have a size argument rather than pushing to this vector.
	std::vector<int> vOut;
	int temp;

	for (int index = 0; index < items; index++) {
		std::cin >> temp;
		vOut.push_back(temp);
	}
	return vOut;
}

int diagonalDifference(std::vector< std::vector<int> > square) {
	int primarySum = 0;
	int secondarySum = 0;
	for (int index = 0; index < square.size(); index++) {
		primarySum += square[index][index];
		secondarySum += square[square.size() - 1 - index][index];
	}
	return primarySum - secondarySum;
}

int main()
{
	int size;
	std::cin >> size;

	std::vector< std::vector<int> > square(size);
	for (int index = 0; index < size; index++) {
		// either set the element at index, or push it to the array, not both, not neither.
		square[index] = (vectorFromInput(size));
	}

	std::cout << std::abs(diagonalDifference(square));
	return 0;
}