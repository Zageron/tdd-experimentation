#pragma once

#include <array>

void InsertionSort(int* collection, int size)
{
	for (size_t j = 1; j < size; j++)
	{
		int key = collection[j];
		int i = j - 1;
		while (i >= 0 && collection[i] > key)
		{
			collection[i + 1] = collection[i];
			--i;
		}

		collection[i + 1] = key;
	}
}
