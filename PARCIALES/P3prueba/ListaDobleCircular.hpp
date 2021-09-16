#include <iostream>

#include "Nodo.hpp"

template <class T>
class DCL
{
private:
    Node<T>* begin;
    Node<T>* end;
    int size;
public:
    class Iterator : public Node<T>
    {
    private:
        Node<T>* current;
        unsigned int pos;
    public:
        Iterator(Node<T>* _current = nullptr, unsigned int _pos = 0) : current(_current), pos(_pos) {}
        unsigned int getPos() { return pos; }
        void operator ++() {  pos++; current = current->next; }
        bool operator !=(Iterator it) { return pos != it.pos; }
        T operator *() { return current->element; }
    };
    Iterator beginIt() { return Iterator(begin, 0); }
    Iterator endIt() { return Iterator(nullptr, size); }

    DCL(Node<T>* _begin = nullptr,  Node<T>* _end = nullptr, int _size = 0) : begin(_begin), end(_end), size(_size){}
    ~DCL() = default;
    int getSize() { return this->size; }
    // bool itsEmpty() { return (begin == nullptr || end == nullptr); }
    void addInitial(T element)
    {
        if(begin == nullptr || end == nullptr)
        {
            Node<T>* newNode = new Node<T>(element, newNode, newNode);
            begin = newNode;
            end = newNode;
        }
        else
        {
            Node<T>* newNode = new Node<T>(element, end, begin);
            begin->previous = newNode;
            end->next = newNode;
            begin = newNode;
        }
        size++;
    }
    void addPos(T element, int pos)
    {
        if(pos < 0 || pos > size) return;
        if(pos == 0) addInitial(element);
        else if(pos == size)
        {
            Node<T>* newNode = new Node<T>(element, end, begin);
            end->next = newNode;
            begin->previous = newNode;
            end = newNode;
            size++;
        }
        else
        {
            Node<T>* current = begin;
            while(pos > 1) { current = current->next; pos--; }
            Node<T>* newNode = new Node<T>(element, current, current->next);
            current->next->previous = newNode;
            current->next = newNode;
            size++;
        }
    }
    void addEnd(T element) { addPos(element, size); }

    void deleteInitial()
    {
        Node<T>* current = begin;
        end->next = current->next;
        current->next->previous = end;
        begin = current->next;
        free(current); // buena practicar para liberar memoria
        size--;
    }
    // posible error 
    void deletePos(unsigned int pos)
    {
        if(pos < 0 || pos > size) return;
        if(pos == 0) deleteInitial();
        else if(pos == size)
        {
            Node<T>* current = end;
            begin->previous = current->previous;
            current->previous->next = begin;
            end = current->previous;
            free(current);
            size--;
        }
        else
        {
            Node<T>* current = begin;
            while(pos > 1) { current = current->next; pos--;}
            current->next = current->next->next;
            current->next->next->previous = current;
            free(current);
            size--;
        }
    }

    void deleteFinal() { deletePos(size); }

    T getInitial() { getPos(0); }

    T getPos(int pos)
    {
        if(pos >= 0 && pos < size)
        {
            Node<T>* current = begin;
            for(unsigned int i = 0; i < pos; ++i)
                current = current->next;
            return current->element;
        }
        else return nullptr;
    }

    T getFinal() { getPos(size - 1); }
};