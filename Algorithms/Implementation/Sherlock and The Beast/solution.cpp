#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


std::string numberFromDigits(int numFives, int numThrees) {
    std::string out = "";
    for (int index = numFives + numThrees; index > numThrees; index--) {
        out += "5";
    }
    for (int index = numThrees; index > 0; index--) {
        out += "3";
    }
    return out;
}

std::string largestDecent(int digits) {
    for (int numFives = digits / 3 * 3; numFives >= 0; numFives -= 3) {
        if (!((digits - numFives) % 5)) {
            return numberFromDigits(numFives, digits - numFives);
        }
    }
    
    return "-1";
}

int main()
{
    int cases, numDigits;
    std::cin >> cases;
    
    for (int index = 0; index < cases; index++) {
        std::cin >> numDigits;
        std::cout << largestDecent(numDigits) << std::endl;
    }
    
    return 0;
}