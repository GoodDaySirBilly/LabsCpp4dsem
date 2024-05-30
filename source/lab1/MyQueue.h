#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include "../libs/libs.h"
class MyQueue
{
private:
    class Node{
    public:
        int value;
        Node *next;
        Node(int value);
    };

    Node *head;

public:
    MyQueue();
    bool add(int value);
    int get();
    int pop();
    bool print();
    MyQueue* copy();
    bool isEmpty();
    ~MyQueue();
};



MyQueue* unite(MyQueue* first, MyQueue *second);

#endif