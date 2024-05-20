#include "pch.h"
#include "../Image Processing/menu.h"
#include "../Image Processing/menu.cpp"

namespace MenuTest {
	TEST(MenuInputTest, HandlesStringInput) {
		EXPECT_EQ(getMenuNumber("1"), 1);

		EXPECT_ANY_THROW(getMenuNumber("abcde"));
	}
}