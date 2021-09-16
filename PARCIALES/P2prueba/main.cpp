#include <iostream>
#include <vector>
#include <string>
#include "Pila.hpp"

void validate(std::string cadena)
{
    Pila* codigo = new Pila();
    char apertura[3] = { '(', '[', '{'};
    std::vector<char> alones;
    for(char value : cadena)
    {
        if(value == '(' || value == '[' || value == '{')
            codigo->push(value);
        else 
        {
            if(value == ')')
                if(codigo->getTop() == apertura[0])
                    codigo->pop();
                else if(codigo->itsEmpty()) alones.push_back(value);
            if(value == ']')
                if(codigo->getTop() == apertura[1])
                    codigo->pop();
                else if(codigo->itsEmpty()) alones.push_back(value);
            if(value == '}')
                if(codigo->getTop() == apertura[2])
                    codigo->pop();
                else if(codigo->itsEmpty()) alones.push_back(value);
        }
    }
    if(codigo->itsEmpty() && (alones.size() == 0)) std::cout << "Correcto\n";
    else std::cout << "Incorrecto\n";
}

int main()
{
   
    int n;
    std::cin >> n;
    std::string linea;
    std::string cadena;
    std::cin.ignore();
    while(n > 0)
    {
        std::getline(std::cin, linea, '\n');
        cadena = cadena + linea;
        n--;
    }
    validate(cadena);
    return 0;
}