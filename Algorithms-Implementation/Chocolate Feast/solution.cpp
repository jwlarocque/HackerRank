#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


int main()
{
    int length, smallest;
    std::cin >> length;
    std::vector<int> arr = vectorFromInput(length);
    printVector(arr);
    while (arr.size() > 0) {
        std::cout << length << std::endl;
        smallest = minInVector(arr);
        for (int index = 0; index < length; index++) {
            if (arr[index] == smallest) {
                arr.erase(arr.begin() + index);
                length--;
                index--;
            } else {
                arr[index] = arr[index] - smallest;
            }
        }
    }
    return 0;
}