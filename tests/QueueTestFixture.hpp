#pragma once

#include "../include/Queue.hpp"

class QueueTestFixture : public testing::Test
{
  protected:
    QueueTestFixture();
    ~QueueTestFixture();

    // Functions that override SetUp and TearDown functions from GTests
    void SetUp() override;
    void TearDown() override;

    CustomDataTypes::Queue* m_queue;
};