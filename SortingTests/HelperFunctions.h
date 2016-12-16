#pragma once

static bool ArraysAreEqual(int* array0, int* array1, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (array0[i] != array1[i])
		{
			return false;
		}
	}

	return true;
}
