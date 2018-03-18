#include "gtest/gtest.h"

TEST(t, p) 
{
	EXPECT_EQ(3, 1 + 2);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
