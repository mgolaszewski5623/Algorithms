#include <string.h>

#define LEFT_CHILD(i) (2 * (i) + 1)
#define RIGHT_CHILD(i) (2 * (i) + 2)

void Heapify(char *array[], int index, int heapSize);
void BuildHeap(char *array[], int size);
void HeapSort(char *array[], int size);