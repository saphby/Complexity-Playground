#include <iostream>
#include <cctype>
#include <vector>
#include <array>
#include <ctime>

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
            std::cout << container[i] << std::endl; 
        }

    }
    return container;
}

int main() {
    srand(time(0));
    return 0;
}