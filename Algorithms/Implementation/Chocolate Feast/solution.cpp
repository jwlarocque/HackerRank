#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


// easy one, so no helper functions
int main()
{
    int cases, dollars, price, wrappersPerChocolate, wrappers, eaten, tempConsumed;
    std::cin >> cases;
    
    for (int caseIndex = 0; caseIndex < cases; caseIndex++) {
        std::cin >> dollars >> price >> wrappersPerChocolate;
        eaten = dollars / price;
        wrappers = eaten;
        while (wrappers >= wrappersPerChocolate) {
            tempConsumed = wrappers / wrappersPerChocolate;
            eaten += tempConsumed;
            wrappers += tempConsumed;
            wrappers -= tempConsumed * wrappersPerChocolate;
        }
        std::cout << eaten << std::endl;
    }
    return 0;
}