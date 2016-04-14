#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <algorithm>


// it took me too long to realize how to do this...
int numSquares(int min, int max)
{
    double rootMin = sqrt(min);
    int numFound = int(sqrt(max)) - int(rootMin);
    if (rootMin == int(rootMin)) {
        numFound++;
    }
    return numFound;
}

int main()
{
    int cases, min, max;
    std::cin >> cases;
    
    for (int index = 0; index < cases; index++) {
        std::cin >> min >> max;
        std::cout << numSquares(min, max) << std::endl;
    }
    
    return 0;
}
