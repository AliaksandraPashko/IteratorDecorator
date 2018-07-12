#include "IteratorDecorator.h"
#include <iostream>
#include <numeric>
#include <vector>

bool filter1(int x)
{
	return x % 2 == 0;
}

bool filter2(int x)
{
	return x % 3 == 0;
}

int main()
{
	std::vector<int> vec(5);
	std::iota(vec.begin(), vec.end(), 1);
	IteratorDecorator<bool(*)(int), decltype(vec.begin())> it1(filter1, vec.begin());
	IteratorDecorator<bool(*)(int), decltype(vec.begin())> it2(filter2, vec.begin());


	return 0;
}