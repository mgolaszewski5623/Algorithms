#include "HSort.h"
#include <string.h>

void Heapify(char *array[], int index, int heapSize) {
    int left, right, largest;
    left = LEFT_CHILD(index);
    right = RIGHT_CHILD(index);
    largest = index;

    if (left < heapSize && strcmp(array[left], array[index]) > 0) {
        largest = left;
    }
    if (right < heapSize && strcmp(array[right], array[largest]) > 0) {
        largest = right;
    }
    if (largest != index) {
        char *temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        Heapify(array, largest, heapSize);
    }
}

void BuildHeap(char *array[], int size) {
    for (int i = (size - 1) / 2; i >= 0; i--) {
        Heapify(array, i, size);
    }
}

void HeapSort(char *array[], int size) {
    BuildHeap(array, size);
    for (int i = size - 1; i > 0; i--) {
        char *temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        Heapify(array, 0, i);
    }
}