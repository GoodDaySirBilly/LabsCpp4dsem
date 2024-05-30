#include "MyQueuePubl.h"

int MyQueuePubl::printTask(){
    MyQueue *cop = this->copy();
    int len = 0;
    int sum = 0;
    while(!cop->isEmpty()){
        len++;
        sum+=cop->pop();
    }
    delete cop;
    
    cop = this->copy();
    double ar = 0;
    if(len!=0) ar = sum/len;
    else{
        std::cout<<"Queue is empty!"<<std::endl;
        return false;
    }
    int tmp;
    while(!cop->isEmpty()){
        tmp = cop->pop();
        if(tmp>ar){
            std::cout<<"Task value:"<<tmp<<std::endl;
            break;
        }
    }
    delete cop;
    return tmp;

}