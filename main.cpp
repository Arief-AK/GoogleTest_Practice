#include <iostream>
#include <gtest/gtest.h>

#include "include/MathFunctions.hpp"
#include "include/Queue.hpp"
using namespace CustomMath;
using namespace CustomDataTypes;

// Factorial - Zero Input
TEST(MathFunctionsTest_Factorial, HandlesZeroInput)
{
    // GIVEN: Factorial function used
    // WHEN: Startup
    // THEN: Result is 1
    EXPECT_EQ(Factorial_int(0), 1);
}

// Factorial - Positive Input
TEST(MathFunctionsTest_Factorial, HandlesPositiveInput)
{
    // GIVEN: Previous test succeeded
    // WHEN: Startup
    // THEN: Result is its respective factorial value
    EXPECT_EQ(Factorial_int(1), 1);
    EXPECT_EQ(Factorial_int(2), 2);
    EXPECT_EQ(Factorial_int(3), 6);
    EXPECT_EQ(Factorial_int(4), 24);
    EXPECT_EQ(Factorial_int(5), 120);
    EXPECT_EQ(Factorial_int(10), 3628800);
}

// Queue - Zero Input
TEST(QueueTest, HandlesZeroInput)
{
    auto new_queue = Queue();
    EXPECT_EQ(new_queue.size(), 0);
}

int main(int argc, char **argv){
    std::cout << "Hello, from GoogleTestProject!\n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
