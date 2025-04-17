#include <stdio.h>
#include "HSort.h"

int main() {
    char *fruits[] = {"apple", "banana", "grape", "cherry", "orange", "pear", "peach", "kiwi", "pineapple", "blueberry", "mango", "strawberry", "watermelon", "lime", "lemon"};
    int size = 15;
    
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", fruits[i]);
    }

    printf("\n");
    HeapSort(fruits, size);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", fruits[i]);
    }

    return 0;
}