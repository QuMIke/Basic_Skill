/*
In Counting sort, the frequencies of distinct elements of the array to be sorted is counted and stored in an auxiliary array,
by mapping its value as an index of the auxiliary array.The array A is traversed in O(N) time 
and the resulting sorted array is also computed in O(N) time.
AUX[] is traversed in O(K) time. Therefore, the overall time complexity of counting sort algorithm is O(N+K).
*/


#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>


template <typename T>
void count_sort(T& data, int len)
{
	int max = data[0];
	std::vector<int> aux_1(RAND_MAX);
	std::vector<int> aux_2(RAND_MAX);
	
	for (int i = 0; i < len; i++)
	{
		if (data[i]>max)
			max = data[i];
		aux_1[data[i]]++;
	}

	for (int i = 1; i<= max; ++i)
	{
		aux_1[i] += aux_1[i - 1];
	}

	for (size_t i = 0; i < len; i++)
	{
		aux_2[aux_1[data[i]] - 1] = data[i];
		--aux_1[data[i]];
	}

	for (size_t i = 0; i < len; i++)
	{
		data[i] = aux_2[i];
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

	count_sort(vec, len);

	std::cout << "After sorting:" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	system("pause");

    return 0;
}
