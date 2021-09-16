#pragma once
#ifndef __HASHTABLE_HPP__
#define __HASHTABLE_HPP__

#include <vector>
#include <iostream>
#include <iomanip>
#include "Persona.hpp"

template <class T>
class HashTable
{
private:
    unsigned short tableSize;
    std::vector<T> table;
public:
    HashTable(unsigned short _size);
    void initTable();
    unsigned int hash(int grupo);
    bool insert(T obj);
    void print();
};

template <class T>
HashTable<T>::HashTable(unsigned short _size) : tableSize(_size) { table.resize(tableSize); initTable(); }

template <class T>
void HashTable<T>::initTable()
{
    for(int i = 0; i < tableSize; ++i)
        table.at(i) = NULL;
}

template <class T>
unsigned int HashTable<T>::hash(int grupo)
{
    unsigned int hashValue = 0;
    hashValue = (grupo * 37) % tableSize;
    return hashValue;
}

template <class T>
bool HashTable<T>::insert(T obj)
{
    if(obj == NULL) return false;
    unsigned int index = hash(obj->getGrupo());
    obj->setNext(table.at(index));
    table.at(index) = obj;
    return true;
}

template <class T>
void HashTable<T>::print()
{
    std::cout << "Table : \n";
    std::cout << "  " << std::left << std::setw(14) << "Name"  << "Dni" << "\n";
    for(int i = 0; i < tableSize; ++i)
    {
        if(table.at(i) == NULL)
            std::cout << i << " ---------\t---\n";
        else
        {
            T temp = table.at(i);
            while(temp != NULL)
            {
                std::cout << i  << " " << std::left << std::setw(10) <<  temp->getName() << "\t" << 
                        temp->getDni() << " | ";
                temp = temp->getNext();
            }
            std::cout << "\n";
        }
    }
}

#endif
