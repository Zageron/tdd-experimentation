#pragma once

static int SizeOfArray(int* anArray)
{
	int size = 0;

	if (anArray != nullptr)
	{
		size = sizeof(anArray) * sizeof(anArray[0]);
	}

	return size;
}