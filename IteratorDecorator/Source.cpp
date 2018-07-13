#include "IteratorDecorator.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool filter1(int x)
{
	return x % 2 == 0;
}

bool filter2(int x)
{
	return x % 5 == 0;
}

int main()
{
	std::vector<int> vec(5);
	std::iota(vec.begin(), vec.end(), 1);
	IteratorDecorator<bool(*)(int), decltype(vec.begin())> it1(filter1, vec.begin(), vec.end());
	IteratorDecorator<bool(*)(int), decltype(vec.begin())> it2(filter2, vec.end(), vec.end());

	std::cout << *std::min_element(it1, it2);

	return 0;
}