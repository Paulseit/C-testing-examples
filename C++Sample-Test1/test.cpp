#include "pch.h"
#include "test.h"


namespace UnitTests
{
TEST(ExampleMathTests, UnitAddTest)
{
	testHeader math;
	EXPECT_EQ(math.Add(2, 3), 5);
	EXPECT_EQ(math.Add(-1, 1), 0);
}

TEST(ExampleMathTests, UnitMultTest)
{
	testHeader math;
	EXPECT_EQ(math.Multiply(4, 5), 20);
	EXPECT_EQ(math.Multiply(0, 10), 0);
}
} 