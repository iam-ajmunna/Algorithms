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
        for (j = 1; j < n; j++) {
             key = arr[i];
             i = j - 1;
            while (i >=0 && arr[i] > key) {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = key;
        }
    }
};



#endif // INSERTIONSORT_H_INCLUDED
