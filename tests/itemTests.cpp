#include "gtest/gtest.h"
#include "../header/StoryIO.h"
#include <iostream>



TEST(Constructors, stdCINandCOUT){
	EXPECT_NO_THROW(StoryIO io(std::cin, std::cout));
}

TEST(Constructs, stringStreams){
	std::ostringstream ostr;
	std::istringstream istr;
	ASSERT_NO_THROW(StoryIO io(istr, ostr));
}