// Concepts: HEAP IS A COMPLETE BINARY TREE

// PARENT = i // THEN LEFT CHILD = (2 * i) + 1 // AND RIGHT CHILD = (2 * i) + 2 // CHILD = i // PARENT = (i / 2) - 1
// HEIGH = h
// THEN MAX NODES ONLY AT HEIGHT h -> 2^h
// AND MAX NODES IN THE ENTIRE TREE -> 2^(h + 1) - 1

// IN A PERFECT BINARY TREE:
// NUMBERS OF INTERNAL NODES = NUMBERS OF LEAVES - 1 

// HEIGHT OF TREE = <LOG_2 (N)> N = Numbers of nodes

// RANGE OF LEAVES = (N / 2) + 1 to N
// RANGE OF INTERNAL NODES = 1 to (N / 2) 

#include <iostream>
#include "Heap.hpp"

namespace HeapArray
{
    void maxHeapify(int A[], int n, int i) // A = array, n = size, i = currentIndex // O(log N)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && A[left] > A[i])
        largest = left;
    if(right < n && A[right] > A[largest])
        largest = right;
    if(largest != i)
    {
        std::swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}
    void minHeapify(int A[], int n, int i) // A = array, n = size, i = currentIndex // O(log N)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && A[left] < A[i])
        smallest = left;
    if(right < n && A[right] < A[smallest])
        smallest = right;
    if(smallest != i)
    {
        std::swap(A[i], A[smallest]);
        minHeapify(A, n, smallest);
    }
}

    void buildMaxHeap(int A[], int n) // A = array, n = size, // O(N)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, n, i);
}
    void buildMinHeap(int A[], int n) // A = array, n = size, // O(N)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        minHeapify(A, n, i);
}

    int extractMax(int A[], int n) // A = array, n = size, // O(N) // O(log N)
{
    if(n <= 0) return INT_MAX;
    if(n == 1) { n--; return A[0]; }
    int max = A[0];
    A[0] = A[n - 1];
    n--;
    maxHeapify(A, n, 0);
    return max;
}
    int extractMin(int A[], int n) // A = array, n = size, // O(N) // O(log N)
{
    if(n <= 0) return INT_MAX;
    if(n == 1) { n--; return A[0]; }
    int min = A[0];
    A[0] = A[n - 1];
    n--;
    minHeapify(A, n, 0);
    return min;
}

    void increaseKey(int A[], int i, int key) // A = array, n = size, // O(log N) // O(1)
{
    if(key < A[i]) return;
    A[i] = key;
    while(i > 0 && A[i / 2] < A[i])
    {
        std::swap(A[i / 2], A[i]);
        i /= 2;
    }
}
    void decreaseKey(int A[], int n, int i, int key) // A = array, n = size, // O(log N) // O(log N)
{
    if(key > A[i]) return;
    A[i] = key;
    maxHeapify(A, n, i);
}

    void insertElement(int A[], int n, int value)
{
    n++;
    A[n - 1] = value;
    int i = n - 1;
    while(i < 0 && A[i / 2] < A[i])
    {
        std::swap(A[i / 2], A[i]);
        i /= 2;
    }
}
}


int main()
{
    Heap heap;
    heap.push(12);
    heap.push(2);
    heap.push(313);
    heap.push(54);
    heap.push(21);
    heap.push(3);
    heap.print();
    heap.buildMaxHeap();
    heap.print();
    heap.insertAndSortMax(3043);
    heap.print();

    return 0;
}