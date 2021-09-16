#include <iostream>
#include <vector>
#include "ListaCircular.hpp"

using std::cout;
using std::cin;

void printData( CircularList<Persona*>* list)
{
    for(CircularList<Persona*>::Iterator it = list->beginIt(); it != list->endIt(); ++it)
    {
        Persona* current = *it;
        std::cout << current->getId() << " " << current->getNombre() << " " << current->getPromedio() << "\n";
    }
}

int main()
{
    CircularList<Persona*>* list = new CircularList<Persona*>();
    int N, M;
    int id; std::string nombre; float promedio;
    Persona* obj = new Persona(200, "rosa", 22.3);
    list->addEnd(obj);
    Persona* obj2 = new Persona(32, "juan", 23.3);
    list->addEnd(obj2);
    Persona* obj3 = new Persona(1, "victor", 23.0);
    list->addEnd(obj3);

    printData(list);
    list->ordenar();
    std::cout << "---------------------\n";
    printData(list);
    


    // std::string tipoDeOperacion;
    // int cantidadPruebas;
    // cin >> N >> M;
    // while(N > 0)
    // {
    //     cin >> id >> nombre >> promedio;
    //     Persona* obj = new Persona(id, nombre, promedio);
    //     list->addEnd(obj);
    //     std::cin.ignore();
    //     N--;
    // };
    // std::getline(cin, tipoDeOperacion);
    // std::cin >> cantidadPruebas;
    // int op;
    // std::vector<int> vector;
    // while(cantidadPruebas > 0)
    // {
    //     std::cin >> op;
    //     std::cin.ignore();
    //     vector.push_back(op);
    //     cantidadPruebas--;
    // }
    // if(tipoDeOperacion.compare("listarMenorPorColumna") == 0)
    // {
    // for(auto value : vector)
    // {
    //     std::cout << list->insertarMenorPorColumna(value)->getId() << " " <<
    //                 list->insertarMenorPorColumna(value)->getNombre() << " " <<
    //                 list->insertarMenorPorColumna(value)->getPromedio()<< "\n";
    // }
    // }

    // printData(list);
    
}