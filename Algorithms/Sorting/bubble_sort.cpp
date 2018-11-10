/*
Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements 
and then swapping their positions if they exist in the wrong order.The complexity of bubble sort is  
O(N*N)in both worst and average cases, because the entire array needs to be iterated for every element.
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void bubble_sort(T &data, int len, bool acsending = true)
{
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = i+1; j < len; j++)
		{
			if (acsending)
			{
				if (data[i] > data[j])
					std::swap(data[i], data[j]);
			}
			else
			{
				if (data[i] < data[j])
				{
					std::swap(data[i], data[j]);
				}
			}
		}
	}
}



int main()
{
	const int len = 1000;
	std::vector<int> vec;
	for (size_t i = 0; i < len; i++)
	{
		int temp= rand() % 1000;
		vec.push_back(temp);
	}

	std::cout << "Before Sorting:" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	bubble_sort(vec, len);

	std::cout << "After Sorting:" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	system("pause");

    return 0;
}
