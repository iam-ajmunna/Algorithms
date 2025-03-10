#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include "StrategyContext.h"
using namespace std;

class QuickSort : public SortingStrategy {
public:
    void sort(vector<int>& arr){
        quickSort(arr, 0, arr.size() - 1);
    }

private:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high], i = low - 1;

        for (int j = low; j < high-1; j++) {
            if (arr[j] < pivot)
                swap(arr[++i], arr[j]);
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};




#endif // QUICKSORT_H_INCLUDED
