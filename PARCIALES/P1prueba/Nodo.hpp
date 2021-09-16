#ifndef __NODO_HPP__
#define __NODO_HPP__

template <class T>
class Node
{
public:
    T element;
    Node* next;
    Node(T _element = nullptr, Node* _next = nullptr) : element(_element), next(_next) {}
};

#endif // __NODO_HPP__