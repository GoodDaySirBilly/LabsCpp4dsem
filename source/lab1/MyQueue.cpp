#include "MyQueue.h"

MyQueue::Node::Node(int value = 0){
    this->value = value;
    this->next = nullptr;
}

MyQueue::MyQueue(){
    head = nullptr;
}

MyQueue::~MyQueue(){
    if(isEmpty()) return;
    Node *finder = head;
    
    Node *deleter = finder;

    while(finder->next!=nullptr){
        deleter = finder;
        finder = finder->next;
        delete deleter;
    }
    delete finder;
}

bool MyQueue::add(int value){
    if(isEmpty()){
        head = new Node(value);
        return true;
    }
    Node *finder = head;
    
    while(finder->next!=nullptr) finder = finder->next;

    Node *element = new Node(value);
    finder->next = element;
    return true;
}

int MyQueue::get(){
    if(isEmpty())
        return head->value;
    else 
        return -1;
}

int MyQueue::pop(){
    if(isEmpty()) return -1;
    int result = head->value;
    Node *finder = head;
    head = head->next;
    delete finder;
    return result;
}

bool MyQueue::print(){
    if(isEmpty()){
        std::cout<<"Queue is empty!"<<std::endl;
        return false;
    }
    Node *finder = head;
    while(finder->next!=nullptr){
        std::cout<< finder->value<<" ";
        finder = finder->next;
    }
    std::cout<<finder->value<<std::endl;
    return true;
}

bool MyQueue::isEmpty(){
    if(head == nullptr) return true;
    else return false;
}

MyQueue* MyQueue::copy(){
    if(isEmpty()) return new MyQueue();
    MyQueue* result = new MyQueue();
    
    Node *finder = head;
    while(finder->next!=nullptr){
        result->add(finder->value);
        finder = finder->next;
    }
    result->add(finder->value);


    return result;
}

MyQueue* unite(MyQueue* first, MyQueue *second){
    MyQueue *result = first->copy();
    MyQueue *tmp = second->copy();
    while(!tmp->isEmpty()){
        result->add(tmp->pop());
    }
    delete tmp;
    return result;
}

