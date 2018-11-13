/*
Quick sort is based on the divide-and-conquer approach based on the idea of choosing one element as a pivot element 
and partitioning the array around it such that: 
Left side of pivot contains all the elements that are less than the pivot element.
Right side contains all elements greater than the pivot.
Complexity The worst case time complexity of this algorithm is O(N*N) , but as this is randomized algorithm, 
its time complexity fluctuates between O(NlogN) and O(N*N) and mostly it comes out to be O(NlogN). 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>


template <typename T>
int partition(T &data, int start, int end)
{
	int i = start-1;
	auto pivot = data[end];
	
	for (int j = start; j < end; j++)
	{
		if (data[j] <= pivot)
		{
			i++;
			std::swap(data[i], data[j]);	
		}
	}

	std::swap(data[i+1], data[end]);
	
	return i+1;

}


template <typename T>
void quick_sort(T &data, int start, int end)
{
	if (start < end)
	{
		int pivot = partition(data, start, end);
		quick_sort(data, start, pivot - 1);
		quick_sort(data, pivot + 1, end);
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

	quick_sort(vec, 0, len - 1);

	std::cout << "After sorting:" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	system("pause");

    return 0;
}
