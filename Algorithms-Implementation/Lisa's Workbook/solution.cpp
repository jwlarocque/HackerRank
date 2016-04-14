#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


// I feel that there might be fewer 1-indexed problems in a different category.
// They're really annoying.

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

int main()
{
    int numChapters, problemsPerPage; 
    std::cin >> numChapters >> problemsPerPage;
    std::vector<int> numProblemsInChapter = vectorFromInput(numChapters);
    
    int totalPages = 1;
    int currentPages;
    int numSpecialFound = 0;
    for (int chapter = 0; chapter < numChapters; chapter++) {
        for (int problem = 0; problem < numProblemsInChapter[chapter]; problem++) {
            if ((problem / problemsPerPage) + totalPages == problem + 1) {
                numSpecialFound++;
            }
        }
        // always rounds up (division)
        currentPages = (numProblemsInChapter[chapter] + problemsPerPage - 1) / problemsPerPage;
        totalPages += currentPages;
    }
    
    std::cout << numSpecialFound << std::endl;
    
    return 0;
}