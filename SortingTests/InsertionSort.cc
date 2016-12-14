#include "gtest\gtest.h"
#include "InsertionSort.h"
#include "HelperFunctions.h"

// INSERTION-SORT(A)
// 1	for j = 2 to A.length
// 2		key = A[j]
// 3		// Insert A[j] into the sorted sequence A[1.. j - 1].
// 4		i = j - 1
// 5		while i > 0 and A[i] > key
// 6			A[i + 1] = A[i]
// 7			i = i - 1
// 8		A[i + 1] = key



TEST(InsertionSort, Sort)
{
	int unsortedArray[] { 5, 2, 4, 6, 1, 3 };
	int expectedArray[] { 1, 2, 3, 4, 5, 6 };

	//InsertionSort.Sort(&unsortedArray);

	EXPECT_EQ(SizeOfArray(unsortedArray), SizeOfArray(expectedArray));
}
