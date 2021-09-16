#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

class Nodo
{
public:
    char cadena;
    Nodo* next;
    Nodo(char _string = '0', Nodo* _next = nullptr):cadena(_string), next(_next){}
};

class Pila
{
private:
    Nodo* top;
    int size;
public:
    Pila(Nodo* _top = nullptr, int _size = 0):top(_top), size(_size){}
    int getSize() { return this->size; }
    void lessSize() { size--; }
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
        size--;
    }
};

class verificador : public Pila
{
private:
    std::string cad1;
    std::string cad2;
public:
    verificador(std::string _cad1 = "", std::string _cad2 = "") : cad1(_cad1), cad2(_cad2) {}
    
    std::string getCad1() { return this->cad1; }
    std::string getCad2() { return this->cad2; }
    bool lecturaDatos()
    {
        std::string cadena1 = "";
        std::string cadena2 = "";
        std::ifstream inFile("2.txt", std::ios::in);
        bool validate = false;
        if(inFile.fail()) { std::cout << "Error404!\n"; }
        auto lambda = [=]() {
               bool isInt = false;
               for(auto v : cadena1) { if(isdigit(v)) isInt = true; else return false; } 
               for(auto v : cadena2) { if(isdigit(v)) isInt = true; else return false; } 
               return validate;
           };
        bool Int = lambda();
        while(!inFile.eof())
        {
           inFile >> cadena1 >> cadena2;
           if(cadena1.length() > 0 && cadena2.length() > 0 && Int)
           {
                cad1 = cadena1;
                cad2 = cadena2;
                validate = true;
           }
        }
        inFile.close();
        return validate;
    }

    void verificar()
    {
        if(lecturaDatos())
        {
            Pila* codigo1 = new Pila();
            Pila* codigo2 = new Pila();
            for(auto value : cad1)
            {
                if(value != '0')
                    codigo1->push(value);
                else
                    codigo1->pop();
            }
            for(auto value : cad2)
            {
                if(value != '0')
                    codigo2->push(value);
                else
                    codigo2->pop();
            }
            // std::cout << codigo1->getTop() << " " << codigo2->getTop();
            cad1 = "";
            cad2 = "";
            int i = 0;
            while(codigo1->getSize() != 0)
            {
                cad1.push_back(codigo1->getTop());
                codigo1->lessSize();
                i++;
            }
            i = 0;
            while(codigo2->getSize() != 0)
            {
                cad2.push_back(codigo2->getTop());
                codigo2->lessSize();
                i++;
            }
            if(cad1.compare(cad2) == 0) std::cout << "true\n"; 
            else std::cout << "false\n";; 
        } else { std::cout << "Valores invalidos!!\n"; }
    }
};

int main()
{
    verificador* obj = new verificador();
    // validacion tambien analizando el top de la pila
    obj->verificar();
    return 0;
}

