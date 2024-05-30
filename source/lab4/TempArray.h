//
// Created by user on 4/18/2024.
//

#ifndef CMAKEPROJECT_TEMPARRAY_H
#define CMAKEPROJECT_TEMPARRAY_H

#include <iostream>




template<typename T>
class TempArray {

public:

    explicit TempArray(unsigned length = 10);
    ~TempArray();
    unsigned getLen();
    T& operator [] (unsigned index);
    TempArray<T>& operator = (const TempArray<T>&);

    std::ostream& operator <<(std::ostream&);
    std::istream& operator >>(std::istream&);
    bool operator == (const TempArray<T>&);
private:
    unsigned len;
    T* array;
};

template<typename T>
void hardSwap(T* array, unsigned len,
              unsigned step = 1, unsigned swapStep = 1) {
    if(swapStep>=len){
        throw "Swap step > len of array!\n";
    }
    T tmp;
    for(unsigned i = 0; i<len;i+=step){
        if(i+swapStep>=len) break;
        tmp = array[i];
        array[i] = array[i+swapStep];
        array[i+swapStep] = tmp;
    }

}

template<typename T>
TempArray<T>::TempArray(unsigned length) :
        len(length>0?length:10),
        array(new T[length>0?length:10]){}


template<typename T>
TempArray<T>::~TempArray() {
    delete[] array;
}

template<typename T>
T &TempArray<T>::operator[](unsigned int index) {
    if(index >= len) throw "Index out of range!\n";
    else return array[index];
}

template<typename T>
TempArray<T> &TempArray<T>::operator=(const TempArray<T> &another) {
    delete[] array;
    len = another.len;
    array = new T[len];
    unsigned s = 0;
    while(s != len){
        array[s] = another.array[s];
        s++;
    }
    return *this;
}



template<typename T>
std::ostream& TempArray<T>::operator<<(std::ostream &os) {
    unsigned s = 0;
    while(s<len){
        os<<array[s]<<" ";
        s++;
    }
    return os;
}

template<typename T>
std::istream& TempArray<T>::operator>>(std::istream &is) {
    unsigned s = 0;
    while(s<len){
        is>>array[s];
        s++;
    }
    return is;
}

template<typename T>
bool TempArray<T>::operator==(const TempArray<T> &another) {
    if(len!=another.len) return false;
    unsigned s = 0;
    while(s<len){
        if(array[s]!=another.array[s]) return false;
        s++;
    }
    return true;
}

template<typename T>
unsigned TempArray<T>::getLen() {
    return len;
}



#endif //CMAKEPROJECT_TEMPARRAY_H
