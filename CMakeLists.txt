cmake_minimum_required(VERSION 3.2)

project(cmakeproject)

add_executable(lab1
        source/main/main.cpp
        source/lab1/lab1.cpp
        source/lab1/MyQueue.cpp
        source/lab1/MyQueuePriv.cpp
        source/lab1/MyQueueProt.cpp
        source/lab1/MyQueuePubl.cpp
        source/lab2/lab2.h source/lab2/lab2.cpp)

add_executable(lab2
        source/main/main.cpp
        source/lab2/lab2.cpp
        source/lab2/MyStack.cpp
        source/lab2/Point.cpp)

add_executable(lab3
        source/main/main.cpp
        source/lab3/lab3.cpp
        source/lab3/Figure.h
        source/lab3/Rectangle.cpp
        source/lab3/Circle.cpp
        source/lab3/RectTriangle.cpp
        source/lab3/Trapezoid.cpp)

add_executable(lab4
        source/main/main.cpp
        source/lab4/lab4.cpp)