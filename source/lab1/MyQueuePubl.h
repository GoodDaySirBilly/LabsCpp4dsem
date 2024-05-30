#ifndef MY_QUEUE_PUBL_H
#define MY_QUEUE_PUBL_H

#include "MyQueue.h"

class MyQueuePubl : public MyQueue{
    using MyQueue::MyQueue;
    public:
    int printTask();

};

#endif