#ifndef __LISTACIRCULAR_HPP__
#define __LISTACIRCULAR_HPP__

#include "Nodo.hpp"
#include "ClaseGeneral.hpp"
#include <iostream>

template <class T>
class CircularList
{
private:
    Node<T>* begin;
    Node<T>* end;
    unsigned int size;
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
    CircularList(Node<T>* _begin = nullptr, Node<T>* _end = nullptr, unsigned int _size = 0) : begin(_begin), end(_end), size(_size) {}
    ~CircularList() = default;
    unsigned int getSize() { return this->size; }
    void addInitial(T element)
    {
        if(begin == nullptr)
        {
            Node<T>* newNode = new Node<T>(element, newNode);
            begin = end = newNode;
        }
        else
        {
            Node<T>* newNode = new Node<T>(element, begin);
            begin = newNode;
            end->next = newNode;
        }
        size++;
    }
    void addPos(T element, unsigned int pos)
    {
        if(pos < 0 && pos > size) return;
        if(pos == 0) addInitial(element);
        else if(pos == size)
        {
            Node<T>* newNode = new Node<T>(element, begin);
            end->next = newNode;
            end = newNode;
            size++;
        }
        else
        {
            Node<T>* current = begin;
            for(unsigned int i = 1; i < pos; ++i)
                current = current->next;
            Node<T>* newNode = new Node<T>(element, current->next);
            current->next = newNode;
            size++;
        }
    }
    void addEnd(T element) { return addPos(element, size); }
    T insertarMenorPorColumna(int type)
    {
        // Node<T>* current = begin;
        T menor;
        switch (type)
        {
        case 0:
            for(CircularList<T>::Iterator it = beginIt(); it != endIt(); ++it)
            {
                T current = *it;
                for(CircularList<T>::Iterator it2 = beginIt(); it2 != endIt(); ++it2)
                {
                    T current2 = *it2;
                    if(current->getId() < current2->getId())
                        menor = current;
                }
            }
            break;
        case 1:
            for(CircularList<T>::Iterator it = beginIt(); it != endIt(); ++it)
            {
                T current = *it;
                for(CircularList<T>::Iterator it2 = beginIt(); it2 != endIt(); ++it2)
                {
                    T current2 = *it2;
                    if(current->getNombre().compare(current2->getNombre()) == -1)
                        menor = current;
                }
            }
            break;
        case 2:
            for(CircularList<T>::Iterator it = beginIt(); it != endIt(); ++it)
            {
                T current = *it;
                for(CircularList<T>::Iterator it2 = beginIt(); it2 != endIt(); ++it2)
                {
                    T current2 = *it2;
                    if(current->getPromedio() < current2->getPromedio())
                        menor = current;
                }
            }
            break;
        
        default:
            break;
        }
        return menor;
    }
    void ordenar()
    {
        Node<T> *i = begin;
        Node<T> *aux = nullptr;
        T obj;
        while(i->next != begin)
        {
            aux = i->next;
            while(aux != begin)
            {
                if(i->element->getId() > aux->element->getId())
                {
                    obj = aux->element;
                    aux->element = i->element;
                    i->element = obj;
                }
                aux = aux->next;
            }
            i = i->next;
        }
    }
};

#endif // __LISTACIRCULAR_HPP__