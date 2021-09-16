#include <iostream>
#include <conio.h>
#include <string>

#define SPACE 10

template <typename Type>
class Node
{
public:
    Type data;
    Node* left;
    Node* right; 

    Node() : data(0), left(nullptr), right(nullptr) {}
    
    Node(Type _data) : data(_data), left(nullptr), right(nullptr) {}
    
};

template <class TypeNode>
class AVLTree
{
public:
    Node<TypeNode>* root;

    AVLTree() : root(nullptr) {}

    inline bool itsEmpty() { return (root == nullptr) ? true : false; }

    int height(Node<TypeNode>* n)
    {
        if(n == nullptr) 
            return -1;
        else
        {
            int lheight = height(n->left);
            int rheight = height(n->right);

            if(lheight > rheight)
                return lheight + 1;
            else    
                return rheight + 1;
        }
    }

    int getBalancedFactor(Node<TypeNode>* n)
    {
        if(n == nullptr) 
            return -1;
        else
            return height(n->left) - height(n->right);
    }

    Node<TypeNode>* rightRotate(Node<TypeNode>*& y)
    {
        Node<TypeNode>* x = y->left;
        Node<TypeNode>* T2 = x->right;
        x->right = y;
        y->left = T2;
        return x;
    }

    Node<TypeNode>* leftRotate(Node<TypeNode>*& x)
    {
        Node<TypeNode>* y = x->right;
        Node<TypeNode>* T2 = y->left;
        y->left = x;
        x->right = T2;
        return y;
    }

    Node<TypeNode>* insert(Node<TypeNode>*& n, TypeNode value)
    {
        if(n == nullptr)
        {
            n = new Node<TypeNode>(value);
            std::cout << "Insertado correctamente!" << std::endl;
            return n;
        }
        if(value < n->data)
            n->left = insert(n->left, value);
        else    
            if(value > n->data)
                n->right = insert(n->right, value);
            else
            {
                std::cout << "No se permiten valores duplicados!" << std::endl;
                return n;
            }
        
        int bf = getBalancedFactor(n);
        // left left case
        if(bf > 1 && value < n->left->data)
            return rightRotate(n);
        // right right case
        if(bf < -1 && value > n->right->data)
            return leftRotate(n);
        // left right case
        if(bf > 1 && value > n->left->data)
        {
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }
        // right left case
        if(bf < -1 && value < n->right->data)
        {
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }
        return n;
    }

    Node<TypeNode>* minValue(Node<TypeNode>* n)
    {
        Node<TypeNode>* currentNode = n;
        while(currentNode->left != nullptr)
            currentNode = currentNode->left;
        return currentNode;
    }

    Node<TypeNode>* deleteNode(Node<TypeNode>*& n, TypeNode value)
    {
        if(n == nullptr) 
            return n;
        else
            if(value < n->data)
                n->left = deleteNode(n->left, value);
            else    
                if(value > n->data)
                    n->right = deleteNode(n->right, value);
                else
                {
                    if(n->left == nullptr)
                    {
                        Node<TypeNode>* temp = n->right;
                        delete n;
                        return temp;
                    }
                    else
                        if(n->right == nullptr)
                        {
                            Node<TypeNode>* temp = n->left;
                            delete n;
                            return temp;
                        }
                        else
                        {
                            Node<TypeNode>* temp = minValue(n->right);
                            n->data = temp->data;
                            n->right = deleteNode(n->right, temp->data);
                        }
                }
        
        int bf = getBalancedFactor(n);
        // left left imbalance or right rotation
        if(bf == 2 && getBalancedFactor(n->left) >= 0)
            return rightRotate(n);
        // left right imbalance or LR rotation
        else 
            if(bf == 2 && getBalancedFactor(n->left) == -1)
            {
                n->left = leftRotate(n->left);
                return rightRotate(n);
            }
        // right right imbalance or left rotation
        else 
            if(bf == -2 && getBalancedFactor(n->right) <= -0)
            return leftRotate(n);
        // right left imbalance or RL rotation
        else
            if(bf == -2 && getBalancedFactor(n->right) == 1)
            {
                n->right = rightRotate(n->right);
                return leftRotate(n);
            }
        return n;
    }

    Node<TypeNode>* recursiveSearch(Node<TypeNode>* n, TypeNode value) 
    {
        if(n == nullptr || n->data == value)
            return n;
        else 
            if(value < n->data)
                return recursiveSearch(n->left, value);
            else
                return recursiveSearch(n->right, value);
    }

    void print2D(Node<TypeNode>* n, int space)
    {
        if(n == nullptr)
            return;
        space += SPACE;
        print2D(n->right, space);
        std::cout << std::endl;
        for(int i = SPACE; i < space; ++i)
            std::cout << " ";
        std::cout << n->data << "\n";
        print2D(n->left, space);
    }
};

int main()
{
    AVLTree<int>* tree = new AVLTree<int>();
    Node<int>* temp;
    int value = 0;
    char key = '\0';
    do
    {
        system("cls");
        std::cout << "1. Insertar\n";
        std::cout << "2. Eliminar\n";
        std::cout << "3. Imprimir\n";
        std::cout << "0. Salir\n";
        key = getch();
        switch (key)
        {
        case '1':
            std::cout << "Que valor desea insertar : ";
            std::cin >> value;
            tree->root = tree->insert(tree->root, value);
            break;
        case '2':
            std::cout << "Que valor desea eliminar : ";
            std::cin >> value;
            temp = tree->recursiveSearch(tree->root, value);
            if(temp != nullptr)
            {
                tree->root = tree->deleteNode(tree->root, value);
                std::cout << "Eliminado" << std::endl;
            }
            else
                std::cout << "No encontrado!" << std::endl;
            break;
        case '3':
            std::cout << "Tree  : \n\n";
            tree->print2D(tree->root, 5);
            break;
        case '0':
            break;
        
        default:
            break;
        }
        system("pause>0");
    } while (key != '0');
    
    return 0;
}