//
// Created by user on 3/1/2024.
//

#ifndef CMAKEPROJECT_MYSTACK_H
#define CMAKEPROJECT_MYSTACK_H
#include <iostream>

class MyStack {
private:

    class Node{
    private:
        double value;
        Node* next;
        Node* prev;
    public:
        Node();
        ~Node();
        [[nodiscard]] double getValue() const;
        Node* getNext();
        Node* getPrev();
        bool setValue(double);
        bool setNext(Node*);
        bool setPrev(Node*);
    };

    Node *head,*end;
    int len;

protected:

    [[nodiscard]] bool contain(double) const;
    bool remove(double);

public:

    explicit MyStack();
    explicit MyStack(int);
    MyStack(const MyStack&);
    ~MyStack();
    bool add(double point = 0.);

    double pop();
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int getLen() const;
    bool clear();
// ? . :: .* sizeof typeid cast
// method  = -> [] () ->* conv mem
    MyStack& operator = ( const MyStack&);
    MyStack operator ! () const;
    bool operator < (const MyStack&) const;
    bool operator > (const MyStack&) const;
    friend bool operator == (const MyStack&, const MyStack&);

    MyStack& operator -=(const MyStack&);
    MyStack operator - (const MyStack&) const;
    friend MyStack& operator /=(MyStack&, const MyStack&);
    friend MyStack operator / (MyStack&, const MyStack&);

    friend std::ostream& operator<<(std::ostream&, const  MyStack&);
    friend std::istream& operator>>(std::istream&,  MyStack&);

};

#endif //CMAKEPROJECT_MYSTACK_H