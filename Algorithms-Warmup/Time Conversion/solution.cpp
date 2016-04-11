#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>


int main()
{
    std::string time;
    std::cin >> time;
    
    int hours = std::stoi(time.substr(0, 2)) % 12;
    std::string sameStuff = time.substr(2, 6);
    
    if (time.substr(8, 2) == "PM") {
        hours += 12;
    }
    
    std::cout << std::setfill('0') << std::setw(2) << hours;
    std::cout << sameStuff << std::endl;
    
    return 0;
}