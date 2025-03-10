#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include "StrategyContext.h"
using namespace std;

class HeapSort : public SortingStrategy {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void sort(vector<int>& arr){
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};




#endif // HEAPSORT_H_INCLUDED
