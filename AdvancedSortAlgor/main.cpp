#include <iostream>
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

void merge(int arr[], int left, int middle, int right)
{
    int s1 = middle - left + 1;
    int s2 = right - middle;
    int* arrLeft = new int[s1];
    int* arrRight = new int[s2];
    for(int i = 0; i < s1; ++i)
        arrLeft[i] = arr[left + i];
    for(int j = 0; j < s2; ++j)
        arrRight[j] = arr[middle + j + 1];
    int i = 0;
    int j = 0;
    int k = left;
    while(i < s1 && j < s2)
    {
        if(arrLeft[i] < arrRight[j])
        {
            arr[k] = arrLeft[i];
            i++;
        }else
        {
            arr[k] = arrRight[j];
            j++;
        }
        k++; 
    }
    while(i < s1)
    {
        arr[k] = arrLeft[i];
        k++; i++;
    }
    while(j < s2)
    {
        arr[k] = arrRight[j];
        k++; j++;
    }
    delete[] arrLeft;
    delete[] arrRight;
}

void mergeSort(int arr[], int left, int right)
{
    if(left >= right) return;
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; ++j)
        if(arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if(low >= high) return;
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

int KthSmallest(int arr[], int left, int right, int k)
{
    if(k > 0 && k <= right - left + 1)
    {
        int index = partition(arr, left, right);
        if(index - left == k - 1)
            return arr[index];
        if(index - left > k - 1)
            return KthSmallest(arr, left, index - 1, k);
        return KthSmallest(arr, index + 1, right, k - index + left - 1);
    }
    return INT_MAX;
}

const int RUN = 32;
void insertionSort(int arr[], int left, int right)
{
    for(int i = left + 1; i <= right; ++i)
    {
        int temp = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void timSort(int arr[], int n)
{
    for(int i = 0; i < n; i += RUN)
        insertionSort(arr, i,std::min((i + RUN - 1), (n - 1)));
    for(int size = RUN; size < n; size = 2 * size)
        for(int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));
            if(mid < right)
                merge(arr, left, mid, right);
        }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[i])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for(int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void foo()
{
    Timer t;
    for(int i = 0; i < 10000; ++i) std::cout << "asdadada\n";
}
int main()
{
    int arr[] = {2, 43, 53, 0, 0, 2, 1, 1, 43, 54, 403, 32 , 3, 4, 1, 3, 1, 4, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    foo();
    // for(int i = 0; i < size; ++i) std::cout << arr[i] << " ";
    return 0;
}