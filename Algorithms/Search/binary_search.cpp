/*
Binary search is the most popular Search algorithmh. 
It is efficient and also one of the most commonly used techniques that is used to solve problems.
It is used to perform operations on a sorted set.
As we dispose off one part of the search case during every step of binary search, 
and perform the search operation on the other half, this results in a worst case time complexity of O(log2N).
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

template <typename T>
int binary_search_iterative (T& t , int low , int high, int key)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (t[mid] < key)
		{
			low = mid + 1;
		}
		else if (t[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}


template <typename T>
int binary_search_recursion(T& t, int low, int high, int key)
{
	int mid = (low + high) / 2;

	if (low > high)
	{
		return -1;
	}

	if (t[mid] < key)
	{
		low = mid + 1;
		binary_search_recursion(t, low, high, key);
	}
	else if (t[mid] > key)
	{
		high = mid - 1;
		binary_search_recursion(t, low, high, key);
	}
	else 
	{
		return mid;
	}
}


int main()
{
	const int len = 1000;
	std::vector<int> vec;
	for (size_t i = 0; i < len; i++)
	{
		vec.push_back(i);
	}

	int key = 999;
	int idx = binary_search_iterative(vec, 0, len - 1, key);
	if (idx == -1)
	{
		std::cout << "Find " << key << " failed!" << std::endl;
	}
	else
	{
		std::cout << key << "'s idx is " << idx << std::endl;
	}

	key = 633;
	idx = binary_search_recursion(vec, 0, len - 1, key);
	if (idx == -1)
	{
		std::cout << "Find " << key << " failed!" << std::endl;
	}
	else
	{
		std::cout << key << "'s idx is " << idx << std::endl;
	}

	system("pause");

    return 0;
}
