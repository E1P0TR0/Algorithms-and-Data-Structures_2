#include "Nodo.hpp"

template <typename T>
class CQueue
{
private:
    Node<T>* begin;
    Node<T>* end;
    int size;
public:
    CQueue() : begin(nullptr), end(nullptr), size(0) {}
    int getSize() { return this->size; }
    bool itsEmpty() { return begin == nullptr; }
    void enQueue(T element)
    {
        Node<T>* newNode = new Node<T>(element);
        if(itsEmpty()) begin = end = newNode;
        else
        {
            end->next = newNode;
            end = newNode;
        }
        size++;
    }
    T deQueue()
    {
        T data = begin->element;
        if(begin == end) begin = end = nullptr;
        else begin = begin->next;
        return data;
    }
};