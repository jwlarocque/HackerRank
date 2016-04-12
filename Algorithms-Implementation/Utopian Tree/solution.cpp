#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


int treeHeight(int cycles) {
    int height = 1;
    for (int cycle = 1; cycle <= cycles; cycle++) {
        if (cycle % 2) {
            height *= 2;
        } else {
            height += 1;
        }
    }
    return height;
}

int main()
{
    int cases, numCycles, numSprings, numSummers;
    std::cin >> cases;
    
    for (int index = 0; index < cases; index++) {
        std::cin >> numCycles;
        std::cout << treeHeight(numCycles) << std::endl;
    }
    
    return 0;
}