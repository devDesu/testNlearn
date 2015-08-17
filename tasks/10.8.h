#ifndef TASK_10_8_H_INCLUDED
#define TASK_10_8_H_INCLUDED
//typedef int T;
#include <iostream>

template <typename T>
class List
{
private:
    struct elem
    {
        T val;
        elem* pre;
        elem* next;
    };
    int total = 0;
    bool empty = true;
    elem* first;
    elem* end;
    List::elem& get(int index) const
    {
        if(index<total)
        {
            elem* tempor;
            if(index>total/2)  //start from end down to index
            {
                tempor = end;
                for(int i=total; i>index; i--)
                    tempor = tempor->pre;
            }
            else
            {
                tempor = first;
                for(int i=0; i<=index; i++)
                    tempor = tempor->next;
            }
            return *tempor;
        }
        else
        {
            std::cout<<"Error in index, returning first elem"<<std::endl;
            return *first;
        }
    }
public:
    explicit List() //empty list
    {
        first = new elem;
        end = new elem;
        first->next = end;
        end->pre = first;
    };
    explicit List(int n): empty(n){
        first = new elem;
        end = new elem;
        first->next = end;
        end->pre = first;
        for(int i=0;i<n;i++){
            add(0);
        }
    }
    List(const List& l){ //copy constructor
        elem* iter;
        first = new elem;
        end = new elem;
        first->next = end;
        end->pre = first;
        iter = l.first->next;
        for(int i=0;i<l.total;i++){
            add(iter->val);
            iter = iter->next;
        }
    };
    List & operator=(const List& l){
        if(this==&l)
            return *this;
        elem* iter;
        iter = l.first->next;
        for(int i=0;i<l.total;i++){
            if(i<total)
                (*this)[i]=(iter->val);
            else
                add(iter->val);
            iter = iter->next;
        }
        while(total>l.total)
            pop();
        return *this;
    }
    ~List()
    {
        elem* temp = first;
        for(int i=0; i<total+1; i++)
        {
            //std::cout<<temp<<" deleted"<<std::endl;
            temp=temp->next;
            delete temp->pre;
        }
        delete end;
    }
    bool isEmpty() const //returns if list is empty(no user data)
    {
        return empty;
    };
    bool isFull() const //always false, linked list has no limits
    {
        return false;
    };
    void show() const; //shows all list values
    void show(int) const; //shows int list value
    bool add(T); //adds T to the total index
    void at(int, T) const; //writes value at index int into T
    void set(int, T); //sets T value at index int
    T pop(int); //deletes element int and returns it's value
    T pop(){return pop(total);}
    void visit(void (*pf)(T&)); //applies given func to all elements
    T& operator[](int);
    friend std::ostream& operator<<(std::ostream& os, const List& l)
    {
        os << "Total elements: "<<l.total<<" empty: "<<l.empty<<std::endl;
        l.show();
        return os;
    }
};

template <typename T>
void List<T>::show() const
{
    elem* temp = first;
    std::cout<<std::endl;
    for(int i=0; i<total; i++)
    {
        temp = temp->next;
        std::cout<<"index: "<<i<<" address: "<<temp<<" value: "<<temp->val<<std::endl;
    }
}
template <typename T>
void List<T>::show(int index) const
{
    elem* temp = &get(index);
    std::cout<<std::endl<<"index: "<<index<<" address: "<<temp<<" value: "<<temp->val<<std::endl;
}
template <typename T>
bool List<T>::add(T el)
{
    elem* temp = new elem;
    temp->val = el;
    temp->next = end;
    temp->pre=end->pre;
    (end->pre)->next = temp;
    end->pre = temp;
    std::cout<<"Added elem "<<el<<" at: "<<temp<<" At index: "<<total<<std::endl;
    empty = false;
    total++;
    return 0;
}
template <typename T>
void List<T>::set(int index, T val)
{
    get(index).val = val;
}
template <typename T>
void List<T>::at(int index, T ret) const
{
    //std::cout<<"Requesting elem at index: "<<index<<std::endl;
    ret = this->get(index).val;
}
template <typename T>
void List<T>::visit(void (*pf)(T&))
{
    elem* temp = first;
    for(int i=0; i<total; i++)
    {
        pf((temp->next->val));
        temp = temp->next;
    }
}
template <typename T>
T List<T>::pop(int index)
{
    if(!empty)
    {
        elem* toPop = &(get(index));
        std::cout<<"Deleting elem at index: "<<index<<" with val: "<<toPop->val<<" at address: "<<toPop<<std::endl;
        if(index==0)
        {
            first->next = toPop->next;
            (toPop->next)->pre = first;
        }
        else if(index==total)
        {
            end->pre = toPop->pre;
            (toPop->pre)->next = end;
        }
        else
        {
            (toPop->pre)->next = (toPop->next);
            (toPop->next)->pre = (toPop->pre);
        }
        T val = toPop->val;
        delete toPop;
        total--;
        if(total==-1)
        {
            total=0;
            empty=true;
        }
        return val;
    }
    else
    {
        std::cout<<"Error popping, List is empty"<<std::endl;
    }
}
template <typename T>
T& List<T>::operator[](int index)
{
    return (get(index).val);
};
template <typename T>
void func(T& input)
{
    input*=2;
}
#endif // TASK_10_8_H_INCLUDED
