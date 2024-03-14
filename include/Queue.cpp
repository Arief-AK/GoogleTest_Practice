#include "Queue.hpp"
#include <exception>
#include <iostream>
using namespace CustomDataTypes;

CustomDataTypes::Queue::Queue()
{
    try
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

CustomDataTypes::Queue::~Queue()
{
    delete head;
    delete tail;
}

void CustomDataTypes::Queue::push_back(int value)
{
    LinkedListNode *new_node = new LinkedListNode;
    new_node->value = value;
    new_node->prev = tail;
    new_node->next = nullptr;

    // If queue is empty - new_node becomes head and tail
    if(head == nullptr){
        head = new_node;
    }
    else{
        // Set previous tail to have new_node as next node
        tail->next = new_node;
    }
    
    // Housekeeping
    tail = new_node;
    count++;
}

void CustomDataTypes::Queue::push_front(int value)
{
    LinkedListNode *new_node = new LinkedListNode;
    new_node->value = value;
    new_node->prev = nullptr;
    new_node->next = head;

    // If queue is empty - new_node becomes head and tail
    if(tail == nullptr){
        tail = new_node;
    }
    else{
        // Set previous pointer to current head to become new_node
        head->prev = new_node;
    }
    
    // Housekeeping
    head = new_node;
    count++;
}

int CustomDataTypes::Queue::pop_back()
{
    // Get the tail
    auto old_tail = tail;
    auto value = old_tail->value;

    // Set the tail of queue to be the previous node of old tail
    tail = old_tail->prev;
    
    // If queue is not empty - ensure that the next pointer of the current tail is null
    if(tail != nullptr){
        tail->next = nullptr;
    }
    // Else, set both head and tail to null
    else{
        head = nullptr;
    }

    // Housekeeping
    delete old_tail;
    count--;

    // Return
    return value;
}

int CustomDataTypes::Queue::pop_front()
{
    // Get the head
    auto old_head = head;
    auto value = old_head->value;

    // Set the head of queue to be the next node of old head
    head = old_head->next;
    
    // If queue is not empty - ensure that the previous pointer of the current head is null
    if(head != nullptr){
        head->prev = nullptr;
    }
    // Else, set both head and tail to null
    else{
        tail = nullptr;
    }
    
    // Housekeeping
    delete old_head;
    count--;

    // Return
    return value;
}

int CustomDataTypes::Queue::size()
{
    return count;
}
