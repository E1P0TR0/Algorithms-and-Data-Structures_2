#pragma once
#ifndef __BYNARY_TREE_NODE_HPP__
#define __BINARY_TREE_NODE_HPP__

template <class T>
class Node
{
public:
    T data;
    Node* left;
    Node* right;
public:
    Node();
    Node(T _data);
    T getData() const;
    Node* getLeft() const;
    Node* getRight() const;
};

template <class T>
Node<T>::Node() : data(nullptr), left(nullptr), right(nullptr) {}

template <class T>
Node<T>::Node(T _data) : data(_data), left(nullptr), right(nullptr) {}

template <class T>
T Node<T>::getData() const { return this->data; }

template <class T>
Node<T>* Node<T>::getLeft() const { return this->left; }

template <class T>
Node<T>* Node<T>::getRight() const{ return this->right; }

#endif 