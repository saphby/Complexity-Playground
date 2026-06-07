#include "Algorithms.h"
#include <cstdlib>
#include <vector>
#include <ctime>

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

int binarySearch(int target, const std::vector<int>& data) {
    int left = 0;
    int right = data.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (target == data[mid]) {
            return mid;
        } else if (target > data[mid]) {
            left = mid + 1;
        } else if (target < data[mid]) {
            right = mid - 1;
        }
    }

    return -1;
}

void merge(std::vector<int>& data, int left, int mid, int right) {
    int leftSize = (mid - left) + 1;
    int rightSize = right - mid;

    std::vector<int> leftVector(leftSize);
    std::vector<int> rightVector(rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftVector[i] = data[left + i];
    }

    for (int j = 0; j < rightSize; j++) {
        rightVector[j] = data[(mid + 1) + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (leftVector[i] <= rightVector[j]) {
            data[k] = leftVector[i];
            i++;
        } else {
            data[k] = rightVector[j];
            j++;
        }

        k++;
    }

    while (i < leftSize) {
        data[k] = leftVector[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        data[k] = rightVector[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& data, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}