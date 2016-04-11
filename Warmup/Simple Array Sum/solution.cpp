#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arraySize;
	cin >> arraySize;
	int sum;
	int temp;
	for (int index = 0; index < arraySize; index++) {
		cin >> temp;
		sum = temp + sum;
	}
	cout << sum;
	return 0;
}