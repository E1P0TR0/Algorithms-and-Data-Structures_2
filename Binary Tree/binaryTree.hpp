#pragma once
#ifndef __BINARY_TREE_HPP__
#define __BINARY_TREE_HPP__

#include "binaryTreeNode.hpp"

#define SPACE 10
// Numeros de nodos = 2 ( # hojas ) - 1
// Nivel de hijo = nivel de Padre - 1
// Altura = max ( altura .izq, altura .der)
// Padre = i -> hijo izq = 2 * i + 1, & hijo der = 2 * i + 2
// Recorridos:
// Pre-orden : raiz - izq - der
// En-orden : izq - raiz - der
// Post-orden : izq - der - raiz

template <typename T>
class BinaryTree
{
private:
    Node<T>* root;
    unsigned int size;

    bool insert(Node<T>*& node, T data);

    Node<T>* search(Node<T>* node, T data);

    Node<T>* minValueNode(Node<T>* node);
    Node<T>* remove(Node<T>* node, T data); // revision

    void preOrder(Node<T>* node);
    void inOrder(Node<T>* node);
    void postOrder(Node<T>* node);

    void levelOrderBFS(Node<T>* node);
    void givenLevel(Node<T>* node, unsigned int level);

    int heightTree(Node<T>* node);

    void print2D(Node<T>* node, int space);
public:
    BinaryTree();
    bool itsEmpty();
    bool insertUI(T data);
    
    Node<T>* searchUI(T data);

    Node<T>* removeUI(T data);

    void preOrderUI();
    void inOrderUI();
    void postOrderUI();

    void LevelOrderUI();

    int heightTreeUI();

    void print2dUI(int space);
public:
    Node<T>* getRoot();

};

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr), size(0) {}

template <typename T>
bool BinaryTree<T>::itsEmpty() { return this->root == nullptr; }

template <typename T>
bool BinaryTree<T>::insert(Node<T>*& node, T value)
{
    if(node == nullptr)
    {
        node = new Node<T>(value);
        size++; // caso base
        return true;
    }
    else 
        if(value == node->getData()) 
            return false;  // no valores repetidos
    else 
        if(value > node->getData()) 
            return insert(node->left, value); // insertar por izq // REVISAR POO
        else 
            return insert(node->right, value); // insertar por der // REVISAR POO
}

template <typename T>
bool BinaryTree<T>::insertUI(T data) { return insert(root, data); }

template <typename T>
Node<T>* BinaryTree<T>::search(Node<T>* node, T value)
{
    if(node == nullptr || node->getData() == value) 
        return node;
    else 
        if(value < node->getData())
            return search(node->getLeft(), value);
        else    
            return search(node->getRight(), value);        
}

template <typename T>
Node<T>* BinaryTree<T>::searchUI(T value) { return search(root, value); }

template <typename T>
Node<T>* BinaryTree<T>::minValueNode(Node<T>* node)
{
    Node<T>* current = root;
    while(current->getLeft() != nullptr)
        current = current->getLeft();
    return current;
}

// VER VIDEO Y CORREGIR https://www.youtube.com/watch?v=zUt2KB2hTQg&list=PLIY8eNdw5tW_zX3OCzX7NJ8bL1p6pWfgG&index=80
template <typename T>
Node<T>* BinaryTree<T>::remove(Node<T>* node, T data) // error to delete only node
{
    if (node == NULL)
        return node;
    if (node->getData() > data) 
    {
        node->left = remove(node->left, data);
        return node;
    }
    else if (node->getData() < data) 
    {
        node->right = remove(node->right, data);
        return node;
    }
    if (node->left == NULL) 
    {
        Node<T>* temp = node->right;
        delete node;
        return temp;
    }
    else if (node->right == NULL) 
    {
        Node<T>* temp = node->left;
        delete node;
        return temp;
    }
    else {
        Node<T>* succParent = node;
 
        Node<T>* succ = node->right;
        while (succ->left != NULL) 
        {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != node)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        node->data = succ->getData();
 
        delete succ;
        return node;
    }
}

template <typename T>
Node<T>* BinaryTree<T>::removeUI(T data) { return remove(root, data); }

template <typename T>
void BinaryTree<T>::preOrder(Node<T>* node) // root - left - right
{
    if(node == nullptr) 
        return;
    std::cout << node->getData() << " ";
    preOrder(node->getLeft());
    preOrder(node->getRight());
}

template <typename T>
void BinaryTree<T>::inOrder(Node<T>* node) // left - root - right
{
    if(node == nullptr) 
        return;
    inOrder(node->getLeft());
    std::cout << node->getData() << " ";
    inOrder(node->getRight());
}

template <typename T>
void BinaryTree<T>::postOrder(Node<T>* node) // left - right - root 
{
    if(node == nullptr) 
        return;
    postOrder(node->getLeft());
    postOrder(node->getRight());
    std::cout << node->getData() << " ";
}

template <typename T>
void BinaryTree<T>::preOrderUI() { preOrder(root); }

template <typename T>
void BinaryTree<T>::inOrderUI() { inOrder(root); }

template <typename T>
void BinaryTree<T>::postOrderUI() { postOrder(root); }

template <typename T>
void BinaryTree<T>::levelOrderBFS(Node<T>* node)
{
    int height = heightTree(node);
    for(int i = 0; i <= height; ++i)
        givenLevel(node, i);
}

template <typename T>
void BinaryTree<T>::givenLevel(Node<T>* node, unsigned int level)
{
    if(node == nullptr) return;
    else    
        if(level == 0) std::cout << node->getData() << " ";
        else
        {
            givenLevel(node->getLeft(), level - 1);
            givenLevel(node->getRight(), level - 1);
        }
}

template <typename T>
void BinaryTree<T>::LevelOrderUI() { levelOrderBFS(root); }

template <typename T>
int BinaryTree<T>::heightTree(Node<T>* node)
{
    if(node == nullptr) return -1;
    else
    {
        int heightLeft = heightTree(node->getLeft());
        int heightRight = heightTree(node->getRight());
        if(heightLeft > heightRight)
            return heightLeft + 1;
        else    
            return heightRight + 1;
    }
}

template <typename T>
int BinaryTree<T>::heightTreeUI() { return heightTree(root); }

template <typename T>
void BinaryTree<T>::print2D(Node<T>* node, int space)
{
    if(node == nullptr) 
        return;
    space += SPACE;
    print2D(node->getRight(), space);
    std::cout << "\n";
    for(int i = SPACE; i < space; i++)
        std::cout << " ";
    std::cout << node->getData() << "\n";
    print2D(node->getLeft(), space);
}

template <typename T>
void BinaryTree<T>::print2dUI(int space) { print2D(root, space); }

template <typename T>
Node<T>* BinaryTree<T>::getRoot() { return this->root; }
#endif
