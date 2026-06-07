#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

std::vector<int> inputGenerator(int size, int mode);

int linearSearch(int target, const std::vector<int>& data);
int binarySearch(int target, const std::vector<int>& data);
void bubbleSort(std::vector<int>& data);
void mergeSort(std::vector<int>& data, int left, int right);
void merge(std::vector<int>& data, int left, int mid, int right);

#endif