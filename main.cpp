#include <iostream>
#include <cctype>
#include <vector>
#include <array>
#include <ctime>
#include <chrono>

std::vector<int> inputGenerator(int size, bool isSort) {
    std::vector<int> container;
    container.reserve(size);

    if (isSort) {
        for (int i = 0; i < size; i++) {
            container.push_back(i + 1);           
        }
    } else {
        for (int i = 0; i < size; i++) {
            container.push_back(rand() % 101); 
        }

    }
    return container;
}

int linearSearch(int target, const std::vector<int>& data) {    
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i] == target) {
            return i;
        } 
    }
    return -1;
}

void bubbleSort(std::vector<int>& data) {
    for (size_t i = data.size() - 1; i > 0; i--) {
        for(size_t j = 0; j < i; j++) {
            if (data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0));
    long long totalTime = 0;
    for (int i = 0; i < 50; i++) {
        std::vector<int> bubbleSortInput = inputGenerator(10000, false);
        auto startTime = std::chrono::steady_clock::now();
        bubbleSort(bubbleSortInput);
        auto endTime = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        totalTime += duration;
    }
    long long averageTime = totalTime / 50;
    std::cout << "Execution Time: " << averageTime << " microseconds" << std::endl;
    return 0;
}