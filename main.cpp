#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <ctime>
#include <chrono>
#include "Algorithms.h"


int main() {
    srand(time(0));
    int choice = 0;

    while (true) {
        std::cout << "\n=== ALGORITHM COMPLEXITY PLAYGROUND ===\n";
        std::cout << "\nBelow is a fun list of algorithms for YOU to test!\n";
        std::cout << "1. Linear Search O(n)\n";
        std::cout << "2. Binary Search O(log n)\n";
        std::cout << "3. Bubble Sort O(n^2)\n";
        std::cout << "4. Merge Sort O(n log n)\n";
        std::cout << "5. Exit\n";
        std::cout << "Select an engine (1-5): ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 5) {
            std::cout << "Shutting down...\n";
            break;
        }

        std::vector<int> testSizes = {1000, 10000, 1000000};

        switch (choice) {
            case 1:
                std::cout << "\nRunning Linear Search Benchmark...\n";
                for (int size : testSizes) {       
        
                    std::vector<int> testData = inputGenerator(size, 3);           
                
                    auto startTime = std::chrono::steady_clock::now();               
                
                    linearSearch(10000001, testData);               

                    auto endTime = std::chrono::steady_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                    std::cout << "Size: " << size << " items | Time: " << duration << " microseconds\n";
                }       
                                  
                break;

            case 2:
                std::cout << "\nRunning Binary Search Benchmark...\n";
                for (int size : testSizes) {    
                    
                    std::vector<int> testData = inputGenerator(size, 1);           
                
                    auto startTime = std::chrono::steady_clock::now();               
                
                    binarySearch(10000001, testData);               

                    auto endTime = std::chrono::steady_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();

                    std::cout << "Size: " << size << " items | Time: " << duration << " nanoseconds\n";
                }       
                                  
                break;

            case 3: {
                std::vector<int> bubbleSizes = {1000, 5000, 10000}; // Different Input Sizes for Bubble Sort as larger sizes(1,000,000) could lead to incredibly high compute times
                std::cout << "\nRunning Bubble Sort Benchmark...\n";
                for (int size : bubbleSizes) {    
        
                    std::vector<int> testData = inputGenerator(size, 2);           
                
                    auto startTime = std::chrono::steady_clock::now();               
                
                    bubbleSort(testData);               

                    auto endTime = std::chrono::steady_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                    std::cout << "Size: " << size << " items | Time: " << duration << " microseconds\n";
                }    
                break;
            }

            case 4:
            std::cout << "\nRunning Merge Sort Benchmark...\n"; 
            for (int size : testSizes) {       
        
                std::vector<int> testData = inputGenerator(size, 3);           
            
                auto startTime = std::chrono::steady_clock::now();               
            
                mergeSort(testData, 0, testData.size() - 1);               

                auto endTime = std::chrono::steady_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                std::cout << "Size: " << size << " items | Time: " << duration << " microseconds\n";
            }       
                                  
                break;
                
            default:
                std::cout << "Invalid input. Try again.\n";
        }
    }
    return 0;
}