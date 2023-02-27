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

TEST(OutputFunc, outputBasic){
	std::ostringstream ostr;
	std::istringstream istr;
	StoryIO io(istr, ostr);
	io << "Test Output" << io.endl;
	EXPECT_EQ(ostr.str(), "Test Output\n");
	// the output in console should be "Test Output" and a newline.
}

TEST(InputFuncs, getString){
	std::string input("word\n");
	std::ostringstream ostr;
	std::istringstream istr(input);

	StoryIO io(istr, ostr);
	std::string output = io.getString();
	EXPECT_EQ(output, "word");
}

TEST(InputFuncs, getDigit){
	std::string input("9");
	std::ostringstream ostr;
	std::istringstream istr(input);

	StoryIO io(istr, ostr);
	int output = io.getDigit();
	EXPECT_EQ(output, 9);
}

TEST(InputFuncs, getDigit3Invalids){
	/*
	word
	2word
	22
	9
	*/
	std::string input("word\n2word\n22\n9");
	std::ostringstream ostr;
	std::istringstream istr(input);

	StoryIO io(istr, ostr);
	int output = io.getDigit();
	EXPECT_EQ(output, 9);
	EXPECT_EQ(ostr.str(), "Please enter a valid number!\nPlease enter a valid number!\nPlease enter a valid number!\n");
}

TEST(InputFuncs, getDigitMax){
	/*
	9
	5
	*/
	std::string input("9\n5");
	std::ostringstream ostr;
	std::istringstream istr(input);

	StoryIO io(istr, ostr);
	int output = io.getDigit(5);
	EXPECT_EQ(output, 5);
	EXPECT_EQ(ostr.str(), "Please enter a valid number!\n");
}