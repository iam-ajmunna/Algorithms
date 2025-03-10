#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include "StrategyContext.h"
using namespace std;

class InsertionSort : public SortingStrategy {
public:
    void sort(vector<int>& arr)  {
        int n = arr.size();
        int i,j,key;
        for (i = 1; i < n; i++) {
             key = arr[i];
             j = i - 1;
            while (j >=0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};



#endif // INSERTIONSORT_H_INCLUDED
