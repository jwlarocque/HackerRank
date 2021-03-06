#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


// I considered writing a class for this, but overkill for this problem.
// Also these 'Bot saves princess' problems are somewhat underwhelming.
std::vector< std::vector<char> > gridFromInput(int height, int width)
{
    std::string temp;
    std::vector< std::vector<char> > grid (height, std::vector<char> (width, '-'));
    for (int row = 0; row < height; row++) {
        std::cin >> temp;
        for (int col = 0; col < width; col++) {
            grid[row][col] = temp[col];
        }
    }
    return grid;
}

int printGrid(std::vector< std::vector<char> > grid)
{
    std::cout << "Printing grid:" << std::endl;
    std::cout << "Height: " << grid.size() << std::endl;
    std::cout << "Width: " << grid[0].size() << std::endl;
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            std::cout << grid[row][col];
        }
        std::cout << std::endl;
    }
    return 0;
}

std::vector<int> positionInGrid(char element, std::vector< std::vector<char> > grid)
{
    std::vector<int> position (2, -1);
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            if (grid[row][col] == element) {
                position[0] = row;
                position[1] = col;
                return position;
            }
        }
    }
    return position;
}

int main()
{
    int size;
    std::cin >> size;
    std::vector< std::vector<char> > mainGrid = gridFromInput(size, size);
    std::vector<int> mPos = positionInGrid('m', mainGrid);
    std::vector<int> pPos = positionInGrid('p', mainGrid);
    while (mPos[0] < pPos[0]) {
        std::cout << "DOWN" << std::endl;
        mPos[0]++;
    }
    while (mPos[0] > pPos[0]) {
        std::cout << "UP" << std::endl;
        mPos[0]--;
    }
    while (mPos[1] > pPos[1]) {
        std::cout << "LEFT" << std::endl;
        mPos[1]--;
    }
    while (mPos[1] < pPos[1]) {
        std::cout << "RIGHT" << std::endl;
        mPos[1]++;
    }
    return 0;
}