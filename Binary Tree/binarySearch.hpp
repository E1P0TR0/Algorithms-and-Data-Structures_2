#pragma once
#ifndef __BINARYSEARCH_HPP__
#define __BINARYSEARCH_HPP__

#include <chrono>

struct Timer
{
    std::chrono::system_clock::time_point m_start;
    Timer() { m_start = std::chrono::system_clock::now(); }
    ~Timer() 
    { 
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> duration = end - m_start;
        std::cout << duration.count() << "\n";
    }
};
template <typename T>
class BinSearch
{
public: 
    int binarySearch(const std::vector<T>& vect, const T& data)
    {
        //Timer t;
        int bottom = 0;
        int top = vect.size() - 1;
        while(bottom <= top)
        {
            int middle = (bottom + top) / 2;
            if(data < vect.at(middle))
                top = middle - 1;
            else if(data > vect.at(middle))
                bottom = middle + 1;
            else return middle;
        }
        return -1;
    }
    int binarySearchRecurs(const std::vector<T>& vect, int left, int right, const T& data)
    {
        //Timer t;
        if(right >= left)
        {
            int middle = left + (right - left) / 2;
            if(vect.at(middle) == data) return middle;
            if(vect.at(middle) > data) return binarySearchRecurs(vect, left, middle - 1, data);
            return binarySearchRecurs(vect, middle + 1, right, data);
        }
        return -1;
    }
};


#endif