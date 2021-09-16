#include <iostream>

template <class T>
class Node
{
public:   
    T element;
    Node* next;
    Node* previous;
    Node(T _element = nullptr, Node* _previous = nullptr, Node* _next = nullptr) : element(_element), previous(_previous), next(_next){}
};