#include <iostream>
#include <vector>

#include "binarySearch.hpp"
#include "binaryTree.hpp"

namespace binarySearch
{
    void search()
    {
        std::vector<int> vect = {1, 3, 5, 7};
        BinSearch<int> objBinarySearch;
        int index = objBinarySearch.binarySearch(vect, 1);
        if(index != -1)
            std::cout << "El elemento se encuentra en el indice "<< index << " \n";
        else std::cout << "El elemento no existe\n";

        int index2 = objBinarySearch.binarySearchRecurs(vect, 0, vect.size() - 1, 1);
        if(index2 != -1)
            std::cout << "El elemento se encuentra en el indice "<< index2 << " \n";
        else std::cout << "El elemento no existe\n";
    }
}

namespace binaryMenu
{
    unsigned int menu()
    {
        system("cls");
        unsigned int option = 0;
        std::cout << "Menu:\n";
        std::cout << "1. Insert Node.\n";
        std::cout << "2. Search Node \n";
        std::cout << "3. Delete Node \n";
        std::cout << "4. Print BST values \n";
        std::cout << "5. Height Tree \n";
        std::cout << "0. Exit \n";
        std::cout << "Option : ";
        std::cin >> option;
        std::cin.ignore();
        return option;
    }

    void main()
    {
        BinaryTree<int>* obj = new BinaryTree<int>();
        Node<int>* node;

        unsigned int op = 0;
        do
        {
            op = menu();
            switch (op)
            {
            case 1:
                int value;
                std::cout << "Insert Value : ";
                std::cin >> value;
                (obj->insertUI(value)) ? std::cout << "Inserted value!\n" : std::cout << "Error!\n";
                break;
            case 2:
                int search;
                std::cout << "Value to search : ";
                std::cin >> search;
                node = obj->searchUI(search);
                (node != nullptr) ? std::cout << "\n" << node->getData() << " exist!\n" : std::cout << "\n" << search << " no exist!\n"; 
                break;
            case 3:
                int deleted;
                std::cout << "Value to delete: ";
                std::cin >> deleted;
                node = obj->removeUI(deleted);
                (node != nullptr) ? std::cout << "\n" << deleted << " deleted!\n" : std::cout << "\n" << deleted << " no exist!\n"; 
                break;
            case 4:
                obj->print2dUI(5);
                std::cout << "\nPre-Order : ";
                obj->preOrderUI();
                std::cout << "\nIn-Order : ";
                obj->inOrderUI();
                std::cout << "\nPost-Order : ";
                obj->postOrderUI();
                std::cout << "\nLevel-Order : ";
                obj->LevelOrderUI();
                break;
            case 5:
                std::cout << "Tree Height : " << obj->heightTreeUI() << "\n";
                break;
            case 0:
                std::cout << "\nExit...\n";
                break;
            default:
                std::cout << "Invalid Option!\n";
                break;
            }
            system("pause>0");  
        } while (op != 0);
    }
    
}


int main()
{
    
    binaryMenu::main();

    system("pause>0");    
    return 0;
}

// IMPORTANT TREE TERMS
// 1. Root - el primer nodo y el unico que no tiene padre
// 2. Parent Node - el nodo predecesor de un nodo
// 3. Chil node - el nodo sucesor de un nodo
// 4. Siblings - nodos con mismo predecesor
// 5. Leaf - últimos nodos de arbol sin sucesores
// 6. Edge - la conexion entre nodos sucesores y predecesores
// 7. Path - números de conexiones de un nodo desde el primer nodo
// 8. Degreee of Node - numero de sucesores de un nodo
// 9. Height of Node - numero de conexiones de la ruta mas larga entre ese nodo y una hoja
// 10. Height of tree - numero de conexiones de la ruta mas larga entre el primer nodo y una hoja

// 1) Arbol binario estricto / adecuado : cada nodo tiene 2 o 0 hijos
// 2) Arbol binario completo : todos los niveles, excepto el de las hojas, estan completos y los nodos estan de izquierda a derecha
// 3) Arbol binario perfecto : todos los niveles completos con sus 2 hijos cada uno
//  - Maximo numero de nodos en un nivel = 2^x ( n = nivel )
// - Para un arbol binario, el maximo de nodos con altura 'h' = 2^( h + 1) - 1
// 4) Arbol binario balanceado : si la diferencia entre la altura del subarbol de la izquierda y la derecha no es mas que un k (mayormente k = 1)
// 