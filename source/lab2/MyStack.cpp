//
// Created by user on 3/1/2024.
//

#include "MyStack.h"

MyStack::Node::Node() {
    value = 0.;
    next = nullptr;
    prev = nullptr;
}

MyStack::Node::~Node() = default;

double MyStack::Node::getValue() const {
    return value;
}

MyStack::Node *MyStack::Node::getNext() {
    return next;
}

MyStack::Node *MyStack::Node::getPrev() {
    return prev;
}

bool MyStack::Node::setValue(double point) {
    value = point;
    return true;
}

bool MyStack::Node::setNext(Node* node) {
    next = node;
    return true;
}

bool MyStack::Node::setPrev(Node* node) {
    prev = node;
    return true;
}

MyStack::MyStack() {
    head = nullptr;
    end = nullptr;
    len = 0;
}

MyStack::MyStack(int numOfNuls) {
    head = nullptr;
    end = nullptr;
    len = 0;
    while(numOfNuls-->0) add();
}

MyStack::MyStack(const MyStack &obj) {
    head = nullptr;
    end = nullptr;
    len = 0;
    Node *cpr = obj.head;
    while(cpr!= nullptr) {
        add(cpr->getValue());
        cpr = cpr->getNext();
    }
}

MyStack::~MyStack() {
    if(isEmpty()) return;
    Node* finder = head;
    Node* deleter;
    while(finder->getNext()!= nullptr){
        deleter = finder;
        finder = finder->getNext();
        delete deleter;
    }
    delete finder;
}

bool MyStack::isEmpty() const {
    if(head == nullptr && end == nullptr) return true;
    else return false;
}

bool MyStack::add(double point) {
    Node* node = new Node();
    node->setValue(point);
    if(isEmpty()){
        head = node;
    }else end->setNext(node);

    node->setPrev(end);
    node->setNext(nullptr);
    end = node;
    len++;
    return true;
}

double MyStack::pop() {
    if(isEmpty()){
        std::cout<<"Stack is empty!\n";
        return 0.;
    }

    Node* val = end;
    double p = val->getValue();
    if(val->getPrev() == nullptr){
        delete val;
        head = end = nullptr;
        len--;
        return p;
    }

    val->getPrev()->setNext(nullptr);
    end = val->getPrev();
    delete val;
    len--;
    return p;

}

int MyStack::getLen() const {
    return len;
}

bool MyStack::contain(double a) const{
    if(isEmpty()){
        return false;
    }
    Node* finder = head;

    while(finder->getNext()!= nullptr){
        if(finder->getValue() == a) return true;
        finder = finder->getNext();
    }
    if(finder->getValue() == a) return true;
    return false;

}

bool MyStack::remove(double a) {
    if(isEmpty()){
        return false;
    }
    Node* finder = head;
    if(finder->getValue() == a){
        finder->getNext()->setPrev(finder->getPrev());
        head = finder->getNext();
        delete finder;
        return true;
    }
    while(finder->getNext()!= nullptr){
        if(finder->getValue() == a){
            finder->getPrev()->setNext(finder->getNext());
            finder->getNext()->setPrev(finder->getPrev());
            delete finder;
            return true;
        }
        finder = finder->getNext();
    }
    if(finder->getValue() == a){
        finder->getPrev()->setNext(finder->getNext());
        end = finder->getPrev();
        delete finder;
        return true;
    }
    return true;
}

bool MyStack::clear() {
    while(!isEmpty()) pop();
    return true;
}

MyStack &MyStack::operator=( const MyStack &obj) {
    if(&obj != this){

        clear();
        Node *cpr = obj.head;
        while(cpr!= nullptr) {
            add(cpr->getValue());
            cpr = cpr->getNext();
        }
    }
    return *this;
}

bool operator==(const MyStack &orig,const MyStack &obj) {
    MyStack a,b;
    a = orig;
    b = obj;
    if(a.isEmpty() && b.isEmpty()) return true;
    else if(a.isEmpty() || b.isEmpty()) return false;
    else{
        while(!a.isEmpty() && !b.isEmpty()){
            if(a.pop()!=b.pop()) return false;
        }
        if(a.isEmpty() && b.isEmpty()) return true;
        else return false;
    }
}

bool MyStack::operator<(const MyStack &obj) const {
    return getLen()<obj.getLen();
}

bool MyStack::operator>(const MyStack &obj) const {
    return getLen()>obj.getLen();
}

MyStack MyStack::operator!() const {
    MyStack z, res;
    z = *this;
    while(!z.isEmpty()) res.add(z.pop());
    return res;
}

MyStack &MyStack::operator-=(const MyStack &obj) {
    if(*this>obj){
         MyStack z;
         z = obj;

         while(!z.isEmpty()){
             z.pop();
             pop();
         }
    }else{
        clear();
    }
    return *this;
}

MyStack MyStack::operator-(const MyStack &obj) const {
    MyStack z;
    z = *this;
    z-=obj;
    return z;
}

MyStack &operator/=(MyStack &orig, const MyStack &obj) {
    MyStack z;
    z = obj;
    while(!z.isEmpty()){
        double a = z.pop();
        if(obj.contain(a)) orig.remove(a);
    }
    return orig;
}

MyStack operator/(MyStack &orig, const MyStack &obj) {
    MyStack z;
    z = orig;
    z/=obj;
    return z;
}

std::ostream &operator<<(std::ostream &os, const MyStack &obj) {
    MyStack z;
    z = !obj;
    if(z.isEmpty()) return os<<"Stack is empty!";
    while(!z.isEmpty()) os<<z.pop()<<" ";
    return os;
}

std::istream &operator>>(std::istream &in,  MyStack &obj) {
    int num;
    double var;
    in>>num;
    do {
        in >> var;
        if (in)
            obj.add(var);
    }while(--num>0);


    return in;
}
