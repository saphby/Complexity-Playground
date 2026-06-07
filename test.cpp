#include <iostream>
#include <vector>
#include <cassert>     
#include <algorithm>   
#include "Algorithms.h"

void testBinarySearch() {
    std::cout << "Testing Binary Search...\n";
    std::vector<int> sortedData = {10, 20, 30, 40, 50};
    
    // Normal Case
    assert(binarySearch(30, sortedData) == 2); 
    assert(binarySearch(99, sortedData) == -1); 
    
    // Empty Vector
    std::vector<int> emptyData;
    assert(binarySearch(10, emptyData) == -1);
}

void testMergeSort() {
    std::cout << "Testing Merge Sort...\n";
    
    // Normal Case
    std::vector<int> normal = inputGenerator(1000, 3);
    mergeSort(normal, 0, normal.size() - 1);
    assert(std::is_sorted(normal.begin(), normal.end()) == true);

    // Single Index Vector
    std::vector<int> single = {42};
    mergeSort(single, 0, single.size() - 1);
    assert(std::is_sorted(single.begin(), single.end()) == true);

    // Stress Test: 500,000 items
    std::cout << "Running Merge Sort Stress Test (500k items)...\n";
    std::vector<int> stressData = inputGenerator(500000, 3);
    mergeSort(stressData, 0, stressData.size() - 1);
    assert(std::is_sorted(stressData.begin(), stressData.end()) == true);
}

void testLinearSearch() {
    std::cout << "Testing Linear Search... \n";
    std::vector<int> sortedData = {10, 20, 30, 40, 50};

    //Normal Case
    assert(linearSearch(30, sortedData) == 2); 
    assert(linearSearch(99, sortedData) == -1); // Target not found
    
    // Edge Case: Empty Vector
    std::vector<int> emptyData;
    assert(linearSearch(10, emptyData) == -1);
}

void testBubbleSort() {
    std::cout << "Testing Bubble Sort...\n";
    
    // Normal Case
    std::vector<int> normal = inputGenerator(1000, 3);
    bubbleSort(normal);
    assert(std::is_sorted(normal.begin(), normal.end()) == true);

    // Single Index Vector
    std::vector<int> single = {42};
    bubbleSort(single);
    assert(std::is_sorted(single.begin(), single.end()) == true);
}

int main() {
    std::cout << "--- Initializing Proving Grounds ---\n";
    
    testBinarySearch();
    testMergeSort();
    testLinearSearch();
    testBubbleSort();
    
    std::cout << "SUCCESS: All engines work correctly.\n";
    return 0;
}