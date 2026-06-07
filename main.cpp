#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <array>
#include <ctime>
#include <chrono>


int main() {
    srand(time(0));
    long long totalTime = 0;
    for (int i = 0; i < 50; i++) {
        auto startTime = std::chrono::steady_clock::now();
        auto endTime = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        totalTime += duration;
    }
    long long averageTime = totalTime / 50;
    std::cout << "Execution Time: " << averageTime << " microseconds" << std::endl;
    return 0;
}