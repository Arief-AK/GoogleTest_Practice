#pragma once
#ifndef QUEUE_H
#define QUEUE_H

namespace CustomDataTypes
{
    typedef struct LinkedListNode
    {
        int value;
        struct LinkedListNode *next;
        struct LinkedListNode *prev;

    } LinkedListNode;

    class Queue
    {
    public:

        Queue();
        ~Queue();

        void push_back(int value);
        void push_front(int value);
        int pop_back();
        int pop_front();
        int size();
        
    private:
        int count;
        LinkedListNode *head;
        LinkedListNode *tail;
    };
}

#endif