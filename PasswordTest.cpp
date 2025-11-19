/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, stwo_leading_letters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aab");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, lowercase_then_upper)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aAmong");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, one_uppper_one_lower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, only_upper)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AA");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, only_lower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aa");
	ASSERT_EQ(0, actual);
}


TEST(PasswordTest, empty_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, one_letter_many)
{
	Password my_password;
	int actual = my_password.unique_characters("aa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, one_letter)
{
	Password my_password;
	int actual = my_password.unique_characters("a");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letters)
{
	Password my_password;
	int actual = my_password.unique_characters("aabb");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, unique_empty)
{
    Password my_password;
    int actual = my_password.unique_characters("");
    ASSERT_EQ(0, actual);
}
