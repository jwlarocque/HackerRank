#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


// didn't both optimizing this with the given position (for that matter, it would be much
// faster to get both char positions at once).  Just eat it with cin.
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
    int size, x, y;
    std::cin >> size >> x >> y;
    std::vector< std::vector<char> > mainGrid = gridFromInput(size, size);
    std::vector<int> mPos = positionInGrid('m', mainGrid);
    std::vector<int> pPos = positionInGrid('p', mainGrid);
    if (mPos[0] < pPos[0]) {
        std::cout << "DOWN" << std::endl;
        mPos[0]++;
    } else if (mPos[0] > pPos[0]) {
        std::cout << "UP" << std::endl;
        mPos[0]--;
    } else if (mPos[1] > pPos[1]) {
        std::cout << "LEFT" << std::endl;
        mPos[1]--;
    } else {
        std::cout << "RIGHT" << std::endl;
        mPos[1]++;
    }
    return 0;
}