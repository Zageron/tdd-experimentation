#include <limits.h>
#include "gtest/gtest.h"
#include "sample.h"

TEST(Addition, CanAddTwoNumbers)
{
	EXPECT_TRUE(add(2, 2) == 4);
}
