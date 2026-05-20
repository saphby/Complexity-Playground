#include <iostream>
#include <cctype>
#include <vector>
#include <array>
#include <ctime>
#include <chrono>

std::vector<int> inputGenerator(int size, bool isSort){
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

int main() {
    srand(time(0));
    auto startTime = std::chrono::steady_clock::now();
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "Execution Time: " << duration << " microseconds" << std::endl;
    return 0;
}