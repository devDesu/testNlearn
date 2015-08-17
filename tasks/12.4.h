#ifndef TASK_12_4_H_INCLUDED
#define TASK_12_4_H_INCLUDED
// stack.h — объявление класса для АТД стека
typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10}; // константа, специфичная для класса
    Item * pitems; // хранит элементы стека
    int size; // количество элементов в стеке
    int top; // индекс для верхнего элемента стека
public:
    Stack(int n = 10); // создает стек с п элементами
    Stack(const Stack& st) ;
    ~Stack();
    bool isempty() const;
    bool isfull() const;
// push() возвращает значение false, если стек уже полный,
// и true в противном случае
    bool push(const Item& item); // добавление элемента в стек
// pop () возвращает значение false, если стек уже пустой,
// и true в противном случае
    bool pop(Item& item); // извлечение элемента из стека
    Stack& operator=(const Stack & st);
    void show() const;
};



#endif // TASK_12_4_H_INCLUDED
