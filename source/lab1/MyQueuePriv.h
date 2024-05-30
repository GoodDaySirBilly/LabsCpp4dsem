#ifndef MY_QUEUE_PRIV_H
#define MY_QUEUE_PRIV_H

#include "MyQueue.h"

class MyQueuePriv : private MyQueue{
    using MyQueue::MyQueue;
    public:
    int printTask();
};

#endif