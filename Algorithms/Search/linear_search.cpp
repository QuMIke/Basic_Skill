/*
Linear search is used on a collections of items. 
It relies on the technique of traversing a list from start to end 
by exploring properties of all the elements that are found on the way.
he time complexity of the linear search is O(N) because each element in an array is compared only once.
*/

#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <iostream>


const int SIZE = 10;

int main()
{
	std::vector<int> vec;

	for (size_t i = 0; i < SIZE; i++)
	{
		int temp = 1 + (int)20 * rand() / (RAND_MAX + 1);
		vec.push_back(temp);
	} 

	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout <<  vec[i]<<" " ;
	}
	std::cout << std::endl;

	int to_find = 10;
	bool if_finded = false;

	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == to_find)
		{
			if_finded = true;
			std::cout << "The number " << to_find << " is in the vector, its idx is "
				<< i + 1 << ".\n";
		}
	}	
	
	if(!if_finded)
		std::cout << to_find << " is not in the vector.\n";

	system("pause");

    return 0;
}
