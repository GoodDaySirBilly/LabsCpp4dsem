#ifndef MY_QUEUE_PROT_H
#define MY_QUEUE_PROT_H

#include "MyQueue.h"

class MyQueueProt : protected MyQueue{
    using MyQueue::MyQueue;
    public:
    int printTask();
};

#endif