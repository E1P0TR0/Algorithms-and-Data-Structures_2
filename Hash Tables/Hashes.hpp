#pragma once
#ifndef __HASH_HPP__
#define __HASH_HPP__

#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class Hash
{
private:
    std::vector<T> vect;
public:
    Hash(int size);
    int hash(T data);
    void insert(T data);
    int search(T data);
    void dleted(T data);
    bool primeNumber(T data);
    void hashPrime(T data);
    void print();
};

template <typename T>
Hash<T>::Hash(int size)
{
    vect.resize(size);
}

template <typename T>
void Hash<T>::insert(T data)
{
    int index = hash(data);
    vect.at(index) = data;
}

template <typename T>
int Hash<T>::search(T data)
{
    int index = hash(data);
    return (data == (vect.at(index))) ? index : -1;
}

template <typename T>
void Hash<T>::dleted(T data)
{
    int index = search(data);
    if(index != -1)
        vect.at(index) = "deleted";
}

template <typename T>
int Hash<T>::hash(T data)
{
   unsigned int hashValue = 0;
   int length = data.length() - 1;
   for(auto value : data)
   {
       hashValue += ( (value - 96) * (pow(27, length)) );
       length--;
   }
       std::cout << hashValue % vect.size()<< " ";
   return hashValue % vect.size();
}

template <typename T>
bool Hash<T>::primeNumber(T data)
{
    for(int i = 2; i < data; ++i)
        if(data % i == 0)
            return false;
    return true;
}

template <typename T>
void Hash<T>::hashPrime(T data) { return data % 19; }


template <typename T>
void Hash<T>::print()
{
    for(auto value : vect) std::cout << value << " ";
    std::cout << "\n";
}

#endif