#include <iostream>
#include <string>
class Nodo
{
public:
    char cadena;
    Nodo* next;
    Nodo(char _string = '0', Nodo* _next = nullptr):cadena(_string), next(_next){}
};