#include "QueueTestFixture.hpp"

TEST_F(QueueTestFixture, SetupInput)
{
    // As implemented in setup, 4 elements are stored in queue
    EXPECT_EQ(m_queue->size(),4);
}

TEST_F(QueueTestFixture, FindValue)
{
    // GIVEN: Element inputted at the front of queue
    m_queue->push_front(-1);

    // WHEN: Startup
    // THEN: Get the value of the front element
    auto new_node = m_queue->find_value(-1);
    EXPECT_EQ(new_node->prev, nullptr);
    EXPECT_EQ(new_node->value, -1);

    // GIVEN: Element inputted at the back of queue
    m_queue->push_back(-2);

    // WHEN: Startup
    // THEN: Get the value of the back element
    new_node = m_queue->find_value(-2);
    EXPECT_EQ(new_node->next, nullptr);
    EXPECT_EQ(new_node->value, -2);

    // WHEN: Startup
    // THEN: Attempt to get size of queue
    EXPECT_EQ(m_queue->size(), 6);
}

TEST_F(QueueTestFixture, FindInvalidValue)
{
    // GIVEN: 4 elements from setup are in the queue
    
    // WHEN: Attempting to find non-existing value in the queue
    // THEN: Throws runtime_error exception
    EXPECT_THROW(m_queue->find_value(10), std::runtime_error );

    // WHEN: Attempting to find non-existing value in the queue
    // THEN: Throws runtime_error exception
    EXPECT_THROW(m_queue->find_value(0), std::runtime_error );

    // WHEN: Attempting to find non-existing value in the queue
    // THEN: Throws runtime_error exception
    EXPECT_THROW(m_queue->find_value(10), std::runtime_error );

    // WHEN: Attempting to find non-existing value in the queue
    // THEN: Throws runtime_error exception
    EXPECT_THROW(m_queue->find_value(20), std::runtime_error );

    // WHEN: Attempting to find non-existing value in the queue
    // THEN: Throws runtime_error exception
    EXPECT_THROW(m_queue->find_value(-10), std::runtime_error );

    // WHEN: Attempting to find non-existing value in the queue
    // THEN: Throws runtime_error exception
    EXPECT_THROW(m_queue->find_value(-20), std::runtime_error );
}