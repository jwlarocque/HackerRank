#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <algorithm>


int numDivisibleDigits(int input)
{
    int numFound = 0;
    int temp = input;
    while (temp > 0) {
        // NOTE TO SELF - C++ does not hold your hand as far as logical operator precedence.
        // ANOTHER NOTE - do not divide by zero.
        if ((temp % 10) != 0 && !(input % (temp % 10))) {
            numFound++;
        }
        temp /= 10;
    }
    return numFound;
}

int main()
{
    int cases, input;
    std::cin >> cases;
    
    for (int index = 0; index < cases; index++) {
        std::cin >> input;
        std::cout << numDivisibleDigits(input) << std::endl;
    }
    return 0;
}
