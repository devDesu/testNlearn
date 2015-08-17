#include "12.4.h"
#include <iostream>

Stack::Stack(int n){
    pitems = new Item[n];
    top = 0;
    size = n;
}

Stack::Stack(const Stack& s){
    pitems = new Item[s.size];
    for(int i=0;i<s.size;i++){
        pitems[i] = s.pitems[0];
    }
    top = s.top;
}

bool Stack::isempty() const{
    return top == 0;
}

bool Stack::isfull() const{
    return top == size;
}

Stack::~Stack(){
    delete [] pitems;
}

bool Stack::pop(Item& it){
    if(top==0){
        return false;
    }else{
        it = pitems[top];
        top--;
        return top;
    }
}

bool Stack::push(const Item& it){
    if(top==size){
        return false;
    }else{
        pitems[top] = it;
        top++;
        return top;
    }
}

Stack& Stack::operator=(const Stack & st){
    if(size!=st.size){
        std::cout<<"Different size! Exiting...";
        throw;
    }else{
        for(int i=0;i<size;i++){
            pitems[i] = st.pitems[i];
            top = st.top;
        }
    }
}

void Stack::show() const{
    for(int i=0;i<size;i++){
        std::cout<<"Item at: "<<i<<" is: "<<pitems[i]<<" top at: "<<top<<std::endl;
    }
}
