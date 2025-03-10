#ifndef STRATEGYCONTEXT_H_INCLUDED
#define STRATEGYCONTEXT_H_INCLUDED
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;

// Strategy Interface
class SortingStrategy {
public:
    virtual void sort(vector<int>& arr) = 0;
    virtual ~SortingStrategy() {}
};


// Strategy Context
class SortContext {
private:
    SortingStrategy* strategy;

public:
    void setStrategy(SortingStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeStrategy(vector<int>& arr) {
        strategy->sort(arr);
    }
};


#endif // STRATEGYCONTEXT_H_INCLUDED
