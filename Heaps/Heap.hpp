#pragma once
#ifndef __HEAP_HPP__
#define __HEAP_HPP__

#include <iostream>
#include <vector>

class Heap
{
private:
    unsigned short size;
    std::vector<int> vect;

    int parent(int i) { return i / 2; } // i / 2
    int left(int i) { return i * 2 + 1; } // i * 2 + 1
    int right(int i) { return i * 2 + 2; } // i * 2 + 2
public:
    Heap(unsigned short _size, std::vector<int> _vect);

    void push(int data) { vect.push_back(data); size++; }
    void maxHeapify(int currentIndex);
    void minHeapify(int currentIndex);

    void buildMaxHeap();
    void buildMinHeap();

    bool itsEmpty() const;

    int getMax() const;
    int getMin() const;

    int extractMax();
    int extractMin();

    void insertAndSortMax(int data);
    void insertAndSortMin(int data);

    void increaseKeyMaxH(int pos, int key);
    void decreaseKeyMaxH(int pos, int key);

    void increaseKeyMinH(int pos, int key);
    void decreaseKeyMinH(int pos, int key);

    void print();
    // -------------------------
    void deleteRandom();    
    void searchRandom();    
};

Heap::Heap(unsigned short _size = 0, std::vector<int> _vect = {}) : size(_size), vect(_vect) {}
void Heap::maxHeapify(int currentIndex)
{
    int largest = currentIndex;
    if(left(currentIndex) < size && vect[left(currentIndex)] > vect[currentIndex])
        largest = left(currentIndex);
    if(right(currentIndex) < size && vect[right(currentIndex)] > vect[largest])
        largest = right(currentIndex);
    if(largest != currentIndex)
    {
        std::swap(vect[currentIndex], vect[largest]);
        maxHeapify(largest);
    }
}
void Heap::minHeapify(int currentIndex)
{
    int smallest = currentIndex;
    if(left(currentIndex) < size && vect[left(currentIndex)] < vect[currentIndex])
        smallest = left(currentIndex);
    if(right(currentIndex) < size && vect[right(currentIndex)] < vect[smallest])
        smallest = right(currentIndex);
    if(smallest != currentIndex)
    {
        std::swap(vect[currentIndex], vect[smallest]);
        minHeapify(smallest);
    }
}
void Heap::buildMaxHeap()
{
    for(int i = size / 2 - 1; i >= 0; i--)
        maxHeapify(i);
}
void Heap::buildMinHeap()
{
     for(int i = size / 2 - 1; i >= 0; i--)
        minHeapify(i);
}
bool Heap::itsEmpty() const { return size == 0; }
int Heap::getMax() const { return vect.at(0); }
int Heap::getMin() const { return vect.at(0); }
void Heap::insertAndSortMax(int data)
{
    size++;
    vect.push_back(data);
    int i = size - 1;
    while(i > 0 && vect[parent(i)] < vect[i])
    {
        std::swap(vect[parent(i)], vect[i]);
        i /= 2;
    }
}
void Heap::insertAndSortMin(int data)
{
    size++;
    vect[size - 1] = data;
    int i = size - 1;
    while(i > 0 && vect[parent(i)] > vect[i])
    {
        std::swap(vect[parent(i)], vect[i]);
        i /= 2;
    }
}
int Heap::extractMax()
{
    if(size <= 0) return INT_MAX;
    if(size == 1) { size--; getMax(); }
    int max = getMax();
    vect[0] = vect[size - 1];
    vect.pop_back();
    size--;
    maxHeapify(0);
    return max;
}
int Heap::extractMin()
{
    if(size <= 0) return INT_MAX;
    if(size == 1) { size--; getMin(); }
    int min = getMin();
    vect[0] = vect[size - 1];
    size--;
    minHeapify(0);
    return min;
}
void Heap::increaseKeyMaxH(int pos, int key)
{
    if(key < vect[pos]) return;
    vect[pos] = key;
    while(pos > 0 && vect[parent(pos)] < vect[pos])
    {
        std::swap(vect[parent(pos)], vect[pos]);
        pos /= 2;
    }
}
void Heap::decreaseKeyMaxH(int pos, int key)
{
    if(key > vect[pos]) return;
    vect[pos] = key;
    maxHeapify(pos);
}
void Heap::increaseKeyMinH(int pos, int key)
{
    if(key < vect[pos]) return;
    vect[pos] = key;
    while(pos > 0 && vect[parent(pos)] > vect[pos])
    {
        std::swap(vect[parent(pos)], vect[pos]);
        pos /= 2;
    }
}
void Heap::decreaseKeyMinH(int pos, int key)
{
    if(key > vect[pos]) return;
    vect[pos] = key;
    minHeapify(pos);
}
void Heap::print()
{
    for(auto value : vect)
        std::cout << value << " ";
    std::cout << "\n";
}
#endif // __HEAP_HPP__