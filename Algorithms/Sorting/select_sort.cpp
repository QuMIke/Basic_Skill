/*
The Selection sort algorithm is based on the idea of finding the minimum 
or maximum elementin an unsorted array and then putting it in its correct position in a sorted array.
Its complexity is O(N*N). 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>


template<typename T1>
void select_sort(T1& data, int len, bool acsending = true)
{
	for (size_t i = 0; i < len; i++)
	{
		int idx = i;

		for (size_t j = i+1; j < len; j++)
		{
			if (acsending)
			{
				if (data[idx] > data[j])
				{
					idx = j;
				}
			}
			else
			{
				if (data[idx] < data[j])
				{
					idx = j;
				}
			}
		}

		std::swap(data[i], data[idx]);
	}
}


int main()
{
	const int len = 1000;
	std::vector<int> vec;
	for (size_t i = 0; i < len; i++)
	{
		int temp = 1 + rand() % 1000;
		vec.push_back(temp);
	}

	std::cout << "Before sorting:" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	select_sort(vec, len);

	std::cout << "After sorting:" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	system("pause");

    return 0;
}
