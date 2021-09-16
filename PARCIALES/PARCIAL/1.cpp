#include <iostream>
#include <string>

template <class T>
class Node
{
public:
    T element;
    Node* next;
    Node* previous;
    Node(T _element = nullptr, Node* _previous = nullptr, Node* _next = nullptr) : element(_element), previous(_previous), next(_next){}
};

template <typename T>
class CList
{
    Node<T>* begin;
    Node<T>* end;
    int size;
    // Comp compare;
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
        void operator --() {  pos--; current = current->previous; }
        bool operator !=(Iterator it) { return pos != it.pos; }
        T operator *() { return current->element; }
    };

    Iterator beginIt() { return Iterator(begin, 0); }
    Iterator endIt() { return Iterator(nullptr, size); }
    
    Iterator rbeginIt() { return Iterator(end, size - 1); }
    Iterator rendIt() { return Iterator(nullptr, -1); }

    CList(Node<T>* _begin = nullptr,  Node<T>* _end = nullptr, int _size = 0) : begin(_begin), end(_end), size(_size){}
    // CList(Comp);
    ~CList() = default;

    int getSize() { return this->size; }
    bool itsEmpty() { return this->size == 0;} 
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
    void addFinal(T element) { addPos(element, size);}

    CList<T>* ordenar()
    {
        CList<T>* sorted = new CList<T>();
        
        int pos = 1;
        for(CList<T>::Iterator it = beginIt(); it != endIt(); ++it)
        {
            T aux = *it;
            if(aux->getTipo() != 'F') sorted->addFinal(aux);
            else
            {
                if(aux->getTipo() == 'F') sorted->addInitial(aux);
                else
                {
                    if(aux->getTipo() == sorted->begin->element->getTipo())
                    {    
                        sorted->addPos(aux, pos);
                        pos++;
                    }
                    else sorted->addInitial(aux);
                }
            }
        }
        return sorted;
    }

    CList<T>* reverse()
    {
        CList<T>* reverse = new CList<T>();
        
        int pos = 1;
        for(CList<T>::Iterator it = beginIt(); it != endIt(); --it)
        {
            T aux = *it;
            if(it != beginIt()) reverse->addInitial(aux);
            else reverse->addFinal(aux);
        }
        return reverse;
    }
};

class Pokemon
{
    private:
        std::string nombre;
        int fuerza;
        char tipo;
    public:
        Pokemon(std::string _nombre = "", int _fuerza = 0, char _tipo = '0') : nombre(_nombre), fuerza(_fuerza), tipo(_tipo) {}
        std::string getNombre() {return this->nombre;}
        int getFuerza() { return this->fuerza;}
        char getTipo() { return this->tipo;}
};

int menu()
{
    system("CLS");
    int op = 0;
    std::cout << "MENU\n";
    std::cout << "1. Insertar Pokemon\n";
    std::cout << "2. Ordenar segun criterio (F > P)\n";
    std::cout << "3. Imprimir Lista\n";
    std::cout << "4. Imprimir al reves\n";
    std::cout << "0. Salir\n";
    std::cout << "\tIngrese opcion : ";
    std::cin >> op;
    std::cin.ignore();
    return op;
} 

template <typename T>
void addPokemon(CList<T>* list)
{
    std::string name = "";
    int power = 0;
    char type = '0';
    std::cout << "Ingrese pokemon: \n";
    std::cout << "Nombre: "; std::getline(std::cin, name); 
    std::cout << "Poder: "; std::cin >> power; std::cin.ignore();
    std::cout << "Tipo: "; std::cin.get(type);
    Pokemon* element = new Pokemon(name, power, type);
    list->addFinal(element);
}

auto printList = [](CList<Pokemon*>* _list)
    {
        for(CList<Pokemon*>::Iterator it = _list->beginIt(); it != _list->endIt(); ++it)
        {
            Pokemon* _current = *it;
            std::cout << _current->getNombre() << " " << _current->getFuerza() << " " << _current->getTipo() << "\n";
        }
    };

template <typename T>
void sortList(CList<T>* list)
{
    CList<T>* aux = list->ordenar();
    printList(aux);
}

template <typename T>
void printReverse(CList<T>* list)
{
    for(CList<Pokemon*>::Iterator it = list->rbeginIt(); it != list->rendIt(); --it)
    {
        Pokemon* _current = *it;
        std::cout << _current->getNombre() << " " << _current->getFuerza() << " " << _current->getTipo() << "\n";
    }
}

int main()
{
    CList<Pokemon*>* list = new CList<Pokemon*>();
    int op = 0;
    do
    {
        op = menu();
        switch (op)
        {
        case 1: 
            addPokemon(list);
            break;
        case 2:
            sortList(list);
            break;
        case 3:
            printList(list);
            break;
        case 4:
            printReverse(list);
            break;
        default:
            break;
        }
        system("pause>nul");
    } while (op != 0);
        
}