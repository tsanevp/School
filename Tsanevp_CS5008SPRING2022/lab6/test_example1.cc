/**
 *  CS 5008: Spr 2021
 *  Northeastern University, Seattle
 *  Lab 6: Testing with Google
 *
 *  Author: Adrienne H. Slaughter (02/25/2021)
 */


#include "gtest/gtest.h"

extern "C" {
    #include "example1.h"
}

const char* first = "first";
const char* second="second";
const char* third = "third";
const char* fourth = "fourth";


// STEP 0: Run 'make' and ''./test_suite' with the 
// starter code and make note of the information 
// printed to your console. 
// How are the parameters inside the TEST(param1, param2) represented?
// Param1: File we're test, or suite of tests
// Param2: Function we're testing, or a specific test desc
TEST(Foobar, SomeFunction) {
  int num = 4;
  int res = SquareNumber(num); 
  // Non "fatal"
  EXPECT_EQ(res, 16);
  // Fatal (Test stops running)
  //  ASSERT_EQ(res, 16);
  //  EXPECT_EQ(SquareNumber(0), 0);
}

TEST(Example1, SumTwoNumbers) {
  int num_one = 6;
  int num_two = 8;
  int res = SumTwoNumbers(num_one, num_two);
  EXPECT_EQ(res, 14);
  // STEP 1: Change num_one and/or num_two. 
  // Run 'make' and the 'test_suite' again. What happens? 
  // How can you use this for debugging?
  //
  // The test fails bc we didn't change the expected value. Can use this
  // to ensure our functions will have the output we expect.
}


TEST(Example1, MultiplyTwoNumbers) {
    int num_one = 4;
    int num_two = 5;
    int res = MultiplyTwoNumbers(num_one, num_two);
    // [actual value] [expected]
    EXPECT_EQ(res, 20);
  // STEP 2: Change the expected value to something 
  // NOT 20. Run 'make' and './test_suite' again and 
  // observe how the Google test suite reflects this error.
  //
  // Shows the input res, the expected value of 20, and our input value of 2
  // that we tried to set equal to 20.
}


/*
STEP 5: Add tests for the additional method(s) that you defined.
*/
TEST(NEW_SUB_FUNCTION, SubtractTwoNumbers) {
    double num_one = 1.5;
    double num_two = 0.5;
    double res = SubtractTwoNumbers(num_one, num_two);
    EXPECT_EQ(res, 1.0);

    num_one = 1.5;
    num_two = 2.5;
    double res1 = SubtractTwoNumbers(num_one, num_two);
    EXPECT_EQ(res1, -1.0);
}

TEST(ARRAY_FUNCTION, AddNumToArray) {
    int array[3] = {1, 2, 3};
    int value = 4;
    int* res = AddNumToArray(array, value);
    int expected[4] = {1, 2, 3, 4};
    EXPECT_EQ(*res, *expected);
}

TEST(NEW_FUNCTION, STRING_PREFIX) {
  EXPECT_TRUE(StringStartsWith("foo", "foobar"));
  EXPECT_FALSE(StringStartsWith("bar", "foobar"));
  ASSERT_FALSE(StringStartsWith("bar", "foobar"));
  EXPECT_TRUE(StringStartsWith("foo2", "foo2bar"));
  printf("got to this point\n");
  ////  EXPECT_TRUE(StringStartsWith("foo", NULL));
  //EXPECT_TRUE(StringStartsWith(NULL, NULL));
  // EXPECT_TRUE(StringStartsWith("foobar", "foo"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
