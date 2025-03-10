#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <algorithm>
#include "StrategyContext.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"


using namespace std;
using namespace std::chrono;
/*
author: Assaduzzaman Munna
ID : 2211796042

About Code: Used Strategy Design Pattern to Use the Family of Algorithms
*/


//Function to generate random dataset
vector<int> generateDataset(int size)
{
    vector<int> dataset(size);

    for(int &num : dataset)
    {
        num = rand() % size;
    }

    return dataset;
}

// Function to measure execution time
void measureExecutionTime(SortContext& context, vector<int> arr, string algoName) {
    auto start = high_resolution_clock::now();
    context.executeStrategy(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << algoName << " took " << duration.count() << " ms\n";
}


int main() {

    // Create context Object
    SortContext context;

    // InsertionSort Object Creation
    InsertionSort insertionSort;

    // MergeSort Object Creation
    MergeSort mergeSort;

    // HeapSort Object Creation
    HeapSort heapSort;

    // QuickSort Object Creation
    QuickSort quickSort;


    //Setting Dataset Sizes For Examination
    vector<int> datasetSizes = {50};


    srand(time(0)); // To make Sure Pure Random Variable generation
    for (int size : datasetSizes) {
        cout << "\nDataset size: " << size << "\n";
        vector<int> dataset = generateDataset(size);

        context.setStrategy(&insertionSort); // Insertion Sort
        measureExecutionTime(context, dataset, "Insertion Sort");

        context.setStrategy(&heapSort); // Heap Sort
        measureExecutionTime(context, dataset, "Heap Sort");

        context.setStrategy(&mergeSort); // Merge Sort
        measureExecutionTime(context, dataset, "Merge Sort");

        context.setStrategy(&quickSort); // Quick Sort
        measureExecutionTime(context, dataset, "Quick Sort");
    }


    return 0;
}
