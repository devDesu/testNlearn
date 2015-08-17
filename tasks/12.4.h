#ifndef TASK_12_4_H_INCLUDED
#define TASK_12_4_H_INCLUDED
// stack.h � ���������� ������ ��� ��� �����
typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10}; // ���������, ����������� ��� ������
    Item * pitems; // ������ �������� �����
    int size; // ���������� ��������� � �����
    int top; // ������ ��� �������� �������� �����
public:
    Stack(int n = 10); // ������� ���� � � ����������
    Stack(const Stack& st) ;
    ~Stack();
    bool isempty() const;
    bool isfull() const;
// push() ���������� �������� false, ���� ���� ��� ������,
// � true � ��������� ������
    bool push(const Item& item); // ���������� �������� � ����
// pop () ���������� �������� false, ���� ���� ��� ������,
// � true � ��������� ������
    bool pop(Item& item); // ���������� �������� �� �����
    Stack& operator=(const Stack & st);
    void show() const;
};



#endif // TASK_12_4_H_INCLUDED
