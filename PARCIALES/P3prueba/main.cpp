#include <iostream>
#include <ctime>

#include "ListaDobleCircular.hpp"
#include "Apostador.hpp"

#define maxPersonas 150000
#define minDado 25000
#define maxDado 15000000
#define minParaJugar 1000

// implementar estas funciones luego en una clase Juego, para mejor orden
void printList(DCL<Apostador*>* list)
{
    for(DCL<Apostador*>::Iterator it = list->beginIt(); it != list->endIt(); ++it)
    {
        Apostador* current = *it;
        std::cout << current->getNombre() << " " <<
                     current->getMonto() << " " <<
                     current->getNronda() << "\n";
    }
}

int menu(int& ronda)
{
    system("cls");
    int op = 0;
    std::cout << "1. Ingresar Participantes ronda " << ronda << ".\n"; 
    std::cout << "2. Empezar juego!\n"; 
    std::cout << "0. Salir.\n";
    std::cout << "Opcion: ";
    std::cin >> op;
    return op;
}

void cobrarDeposito(DCL<Apostador*>* list, int& ronda)
{
    for(DCL<Apostador*>::Iterator it = list->beginIt(); it != list->endIt(); ++it)
    {
        Apostador* current = *it;
        if(current->getNronda() != ronda) current->restarMonto(5.0);
        else current->restarMonto(10.0);
    }
}

void disponibilidadDinero(DCL<Apostador*>* list)
{
    for(DCL<Apostador*>::Iterator it = list->beginIt(); it != list->endIt(); ++it)
    {
        Apostador* current = *it;
        if(current->getMonto() <= 0) list->deletePos(it.getPos());
    }
}

void requisitosRonda(DCL<Apostador*>* list, int& ronda)
{
    cobrarDeposito(list, ronda);
    disponibilidadDinero(list);
}

void generarApostadores(DCL<Apostador*>* list, int& ronda)
{
    char nombreAleatorio;
    float auxMonto = 0;
    srand(time(NULL));
    int addCantidad = 1 + rand() % (1000 - 1);
    if((list->getSize() + addCantidad) <= maxPersonas)
    {
        while(addCantidad > 0)
        {
            nombreAleatorio = 33 + rand() % (126 - 33);
            auxMonto = (5000 + rand() % (20000 - 5000)) / 100.0f;
            std::string toS(1, nombreAleatorio);
            Apostador* obj = new Apostador(toS, auxMonto, ronda);
            if(ronda == 1) list->addEnd(obj);
            else
            {
                int pos = 0 + rand() % (list->getSize());
                list->addPos(obj, pos);
            }
            addCantidad--;
        }
    } else std::cout << "La cantidad de personas para entrar excede el maximo!!\n";
}

int empezarJuego(DCL<Apostador*>* list, int& ronda)
{
    std::cout << "Cantidad de Personas: " << list->getSize() << "\n";
    if(list->getSize() >= minParaJugar && list->getSize() <= maxPersonas)
    {
        requisitosRonda(list, ronda);
        std::cout << "Empieza el juego!\n";
        //obtenerUltimo();
        // en la ronda 1, el ultimo que entro será quien lanze el dado
        // el participante que gano el premio de la ronda anterior será quien lanze el dado
        //lanzarDado(); 
        // se mueve x pos a la izquierda de la lista
        // sumarDinero(); 85% del deposito al ganador, 15% a la casa

        // Notas: faltaria acumular el dinero de cada participante

        ronda++;
        return ronda;
        // fin de ronda
    }
    else std::cout << "Cantidad insifuciente para empezar...\n";
    return ronda;
}

int main()
{
    DCL<Apostador*>* list = new DCL<Apostador*>();
    int ronda = 1;
    int op;
    do
    {
        op = menu(ronda);
        switch (op)
        {
        case 1:
            generarApostadores(list, ronda);
            break;
        case 2:
            ronda = empezarJuego(list, ronda);
            system("pause>nul");
            break;
        default:
            break;
        }

    }while(op != 0);
    
    printList(list);
    return 0;
}