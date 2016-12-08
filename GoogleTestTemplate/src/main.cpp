#include "gtest/gtest.h"

#pragma region Unit Test Includes

#include "sample_unittest.cc"

#pragma endregion Unit Test Includes

// --------------------------------------------------------------------------------

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}