/*
Merge sort is a divide-and-conquer algorithm based on the idea of breaking down a list into several sub-lists until each sublist consists of a single element and merging those sublists in a manner that results into a sorted list.
Idea:
Divide the unsorted list into N sublists, each containing 1 element.
Take adjacent pairs of two singleton lists and merge them to form a list of 2 elements. N will now convert into N/2 lists of size 2.
Repeat the process till a single sorted list of obtained.
The list of size N is divided into a max of log(N)parts, and the merging of all sublists into a single list takes O(N) time, the worst case run time of this algorithm is Nlog(N).
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
void merge(std::vector<T>& data, int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;

	std::vector<T> L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = data[start + i];
	for (int i = 0; i < n2; i++)
		R[i] = data[mid + 1 + i];

	int i = 0, j = 0, k = start;
	while (i<n1 && j<n2)
	{
		if (L[i] <= R[j])
		{
			data[k] = L[i];
			i++;
		}
		else
		{
			data[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		data[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		data[k] = R[j];
		j++;
		k++;
	}

}

template <typename T>
void merge_sort(T& data, int start, int end)
{
	if (start < end)
	{
		int mid =  (start + end) / 2;
		merge_sort(data, start, mid);
		merge_sort(data, mid+1, end);
		merge(data, start, mid, end);
	}
}


int main()
{
	const int len = 1000;
	std::vector<int> vec;
	for (int i = 0; i < len; i++)
	{
		int temp = 1 + rand() % 1000;
		vec.push_back(temp);
	}

	std::cout << "Befroe sorting:" << std::endl;
	for (int i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	merge_sort(vec, 0, len - 1);

	std::cout << "After sorting:" << std::endl;
	for (int i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	system("pause");

    return 0;
}
