#include "QueueTestFixture.hpp"

QueueTestFixture::QueueTestFixture()
{
    // Initate an empty queue
    m_queue = new CustomDataTypes::Queue();
}

QueueTestFixture::~QueueTestFixture()
{
    // Clear resources
    delete m_queue;
}

void QueueTestFixture::SetUp()
{
    // Code here will be called immediately after the constructor (right
    // before each test)
    m_queue->push_front(1);
    m_queue->push_front(2);
    m_queue->push_front(3);
    m_queue->push_front(4);
}

void QueueTestFixture::TearDown()
{
    // Code here will be called immediately after each test (right
    // before the destructor)
    m_queue->clear();
}
