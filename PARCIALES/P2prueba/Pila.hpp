#include "Nodo.hpp"

class Pila
{
private:
    Nodo* top;
    int size;
public:
    Pila(Nodo* _top = nullptr, int _size = 0):top(_top), size(_size){}
    int getSize() { return this->size; }
    bool itsEmpty() { return top == nullptr; }
    char getTop() { if(itsEmpty()) return '0'; else return top->cadena; }
    void push(char element)
    {
        if(itsEmpty())
            this->top = new Nodo(element);
        else
            this->top = new Nodo(element, this->top);
        size++;
    }
    void pop()
    {
        if(itsEmpty()) return;
        else
            top = top->next;
    }
};