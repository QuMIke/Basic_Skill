/*
Insertion sort is based on the idea that one element from the input elements is consumed 
in each iteration to find its correct position i.e, the position to which it belongs in a sorted array.
It iterates the input elements by growing the sorted array at each iteration. It compares the current element
with the largest value in the sorted array. If the current element is greater, 
then it leaves the element in its place and moves on to the next element
else it finds its correct position in the sorted array and moves it to that position. 
This is done by shifting all the elements, which are larger than the current element,
in the sorted array to one position ahead.The worst time complexity of insert sorting is O(N*N).
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void insert_sort(T& data, int len, bool acsending = true)
{
	if (len <=1 )
	{
		return;
	}

	for (int i = 0; i < len; i++)
	{
		int idx = i;
		for (int j = i-1; j>=0; j--)
		{
			if (acsending)
			{
				if (data[idx]<data[j])
				{
					std::swap(data[idx], data[j]);
					idx = j;
				}
			}
			else
			{
				if (data[idx] > data[j])
				{
					std::swap(data[idx], data[j]);
					idx = j;
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
		int temp = 1 + rand() % 1000;
		vec.push_back(temp);
	}

	std::cout << "Befroe sotring:" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	insert_sort(vec, len);

	std::cout << "After sorting:" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	system("pause");

    return 0;
}
