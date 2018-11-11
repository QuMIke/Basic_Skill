/*
Like linear search and binary search, 
ternary search is a searching techniquethat is used to determine the position of a specific value in an array. 
In binary search, the sorted array is divided into two parts while in ternary search,
it is divided into  parts and then you determine in which part the element exists.
Ternary search, like binary search, is a divide-and-conquer algorithm. 
It is mandatory for the array (in which you will search for an element) to be sorted before you begin the search. 
In this search, after each iteration it neglects ⅓part of the array and repeats the same operations on the remaining ⅔.
Its time complexity is O(log3N).
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

template <typename T1, typename T2>
int ternary_search_iterative(T1& data, int left, int right, T2& key)
{	

	while (left <= right)
	{	
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3 ;

		if (data[mid1] == key)
		{
			return mid1;
		}
		if (data[mid2] == key)
		{
			return mid2;
		}
		if (data[mid1] > key)
		{
			right = mid1 - 1;
		}
		else if (data[mid2] < key)
		{
			left = mid2 + 1;
		}
		else
		{
			left = mid1 + 1;
			right = mid2 - 1;
		}
	}

	return -1;
}

template <typename T1, typename T2>
int ternary_search_recursion(T1& data, int left, int right, T2& key)
{
	int mid1 = left + (right - left) / 3;
	int mid2 = right - (right - left) / 3;

	if(mid1 > mid2)
	{	
		return -1;
	}
	
	if (data[mid1] == key)
	{
		return mid1;
	}
	if (data[mid2] == key)
	{
		return mid2;
	}

	if (data[mid1] > key)
	{
		right = mid1 - 1;
		return ternary_search_recursion(data, left, right, key);
	}
	else if (data[mid2] < key)
	{
		left = mid2 + 1;
		return ternary_search_recursion(data, left, right, key);
	}
	else
	{
		left = mid1 + 1;
		right = mid2 - 1;
		return ternary_search_recursion(data, left, right, key);
	}

	return  -1;
}


int main()
{
	const int len = 100000;
	std::vector<int> vec;
	for (size_t i = 0; i < len; i++)
	{
		vec.push_back(i);
	}

	int key = 0;
	int idx = ternary_search_iterative(vec, 0, len-1, key);
	if (idx != -1)
	{
		std::cout << key << "'s index is " << idx <<"."<< std::endl;
	}
	else
	{
		std::cout << key << " is not in the data." << std::endl;
	}

	key = 999;
	idx = ternary_search_recursion(vec, 0, len - 1, key);
	if (idx != -1)
	{
		std::cout << key << "'s index is " << idx << "." << std::endl;
	}
	else
	{
		std::cout << key << " is not in the data." << std::endl;
	}

	system("pause");

    return 0;
}
