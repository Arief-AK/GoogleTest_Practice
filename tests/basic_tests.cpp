#include <iostream>

#include "../include/MathFunctions.hpp"
#include "../include/Queue.hpp"
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
    // GIVEN: Queue class is called
    auto new_queue = Queue();

    // WHEN: Startup
    // THEN: Result is an empty queue
    EXPECT_EQ(new_queue.size(), 0);
}

// Queue - Multiple Input
TEST(QueueTest, Appending)
{
    // GIVEN: Queue class is called
    auto new_queue = Queue();

    // WHEN: Startup
    // THEN: Appends values to the queue
    new_queue.push_back(10);
    new_queue.push_back(100);
    EXPECT_EQ(new_queue.size(), 2);
}

// Queue - Multiple Removal
TEST(QueueTest, Removing)
{
    // GIVEN: Queue class is called
    auto new_queue = Queue();

    // WHEN: Startup
    // THEN: Appends values to the queue - size should be 2
    new_queue.push_back(1);
    new_queue.push_back(2);
    EXPECT_EQ(new_queue.size(), 2);

    // WHEN: Startup
    // THEN: Removes the values from the queue
    auto popped_value = new_queue.pop_back();
    EXPECT_EQ(popped_value, 2);
    popped_value = new_queue.pop_back();
    EXPECT_EQ(popped_value, 1);
}

// Queue - Find value in queue
TEST(QueueTest, FindValue)
{
    // GIVEN: Queue class is filled with 3 elements
    auto new_queue = Queue();
    new_queue.push_back(1);
    new_queue.push_back(2);
    new_queue.push_back(3);

    // WHEN: Startup
    // THEN: Finds the element in the middle (position 1)
    auto found_node = new_queue.find_value(2);
    EXPECT_EQ(found_node->value, 2);

    // WHEN: Startup
    // THEN: Attempts to find non-existing element in queue
    EXPECT_THROW(new_queue.find_value(4), std::runtime_error );
}

// Queue - Clear the queue
TEST(QueueTest, ClearQueue)
{
    // GIVEN: Queue class is filled with 3 elements
    auto new_queue = Queue();
    new_queue.push_back(1);
    new_queue.push_back(2);
    new_queue.push_back(3);

    // WHEN: Startup
    // THEN: Attempts to clear the queue
    new_queue.clear();
    EXPECT_EQ(new_queue.size(), 0);
}