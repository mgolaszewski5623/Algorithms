#include "Sorting.h"

void InitializeResults(Results *r) {
    r->minSwaps = -1;
    r->maxSwaps = -1;
    r->totalSwaps = 0LL;
    r->minComparisons = -1;
    r->maxComparisons = -1;
    r->totalComparisons = 0LL;
}

void UpdateResults(Results *r, int swaps, int comparisons) {
    if(r->minComparisons == -1 || r->minComparisons > comparisons) {
        r->minComparisons = comparisons;
    }
    if(r->maxComparisons == -1 || r->maxComparisons < comparisons) {
        r->maxComparisons = comparisons;
    }
    r->totalComparisons += comparisons;

    if(r->minSwaps == -1 || r->minSwaps > swaps) {
        r->minSwaps = swaps;
    }
    if(r->maxSwaps == -1 || r->maxSwaps < swaps) {
        r->maxSwaps = swaps;
    }
    r->totalSwaps += swaps;
}

void BubbleSort(int array[], int size, Results *r) {
    long long swaps = 0LL, comparisons = 0LL;

    int i, j, temp;
    for(i = 1; i < size; i++) {
        swaps++;
        comparisons++;

        for(j = size - 1; j >= i; j--) {
            swaps++;
            comparisons++;

            comparisons++;
            if(array[j-1] > array[j]) {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
                swaps += 3;
            }
        }
    }

    UpdateResults(r, swaps, comparisons);
}

void InsertSort(int array[], int size, Results *r) {
    long long swaps = 0LL, comparisons = 0LL;

    int i, j, temp;
    for(i = 1; i < size; i++) {
        comparisons++;
        swaps++;

        comparisons++;
        if(array[i] < array[0]) {
            temp = array[0];
            array[0] = array[i];
            swaps += 2;
        } else {
            temp = array[i];
            swaps++;
        }
        for(j = i - 1; temp < array[j]; j--) {
            comparisons++;
            swaps++;

            array[j + 1] = array[j];
            swaps++;
        }
        array[j + 1] = temp;
        swaps++;
    }

    UpdateResults(r, swaps, comparisons);
}

void ShellSort(int array[], int size, Results *r) {
    long long comparisons = 0LL, swaps = 0LL;
    int i, j, temp, gap;

    gap = size/2;
    swaps++;
    while(gap > 0) {
        comparisons++;

        for(i = gap; i < size; i++) {
            swaps++;
            comparisons++;

            temp = array[i];
            swaps++;

            j = i;
            swaps++;
            while(j >= gap && array[j - gap] > temp) {
                comparisons += 2;

                array[j] = array[j - gap];
                j -= gap;
                swaps += 2;
            }
            array[j] = temp;
            swaps++;
        }
        gap /= 2;
        swaps++;
    }

    UpdateResults(r, swaps, comparisons);
}

void QuickSortStart(int array[], int size, Results *r) {
    long long swaps = 0LL, comparisons = 0LL;

    QuickSort(array, 0, size - 1, &swaps, &comparisons);

    UpdateResults(r, swaps, comparisons);
}

int Partition(int array[], int low, int high, long long *swaps, long long *comparisons) {
    int pivot, temp, i, j;
    pivot = array[high];
    i = low - 1;
    (*swaps) += 2;

    for (j = low; j <= high - 1; j++) {
        (*swaps)++;
        (*comparisons)++;

        (*comparisons)++;
        if (array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            (*swaps) += 4;
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    (*swaps) += 3;

    return i + 1;
}

void QuickSort(int array[], int low, int high, long long *swaps, long long *comparisons) {
    int pivot;
    (*comparisons)++;
    if(low < high) {
        pivot = Partition(array, low, high, swaps, comparisons);
        (*swaps)++;

        QuickSort(array, low, pivot - 1, swaps, comparisons);
        QuickSort(array, pivot + 1, high, swaps, comparisons);
    }
}

void Start(int range) {
    int tests, size, random;
    Results bubbleResults;
    Results insertResults;
    Results shellResults;
    Results quickResults;
    InitializeResults(&bubbleResults);
    InitializeResults(&insertResults);
    InitializeResults(&shellResults);
    InitializeResults(&quickResults);
    srand(time(NULL));
    tests = 950 + rand() % 101;
    size = 9950 + rand() % 101;
    tests = 1;

    for(int i = 0; i < tests; i++) {
        int *bubbleArray = (int *)malloc(size * sizeof(int));
        int *insertArray = (int *)malloc(size * sizeof(int));
        int *shellArray = (int *)malloc(size * sizeof(int));
        int *quickArray = (int *)malloc(size * sizeof(int));

        for(int j = size; j >= 1; j--) {
            random = j;
            bubbleArray[j] = random;
            insertArray[j] = random;
            shellArray[j] = random;
            quickArray[j] = random;
        }

        BubbleSort(bubbleArray, size, &bubbleResults);
        InsertSort(insertArray, size, &insertResults);
        ShellSort(shellArray, size, &shellResults);
        QuickSortStart(quickArray, size, &quickResults);

        free(bubbleArray);
        free(insertArray);
        free(shellArray);
        free(quickArray);
    }

    PrintResults(bubbleResults, insertResults, shellResults, quickResults, tests);
    printf("\n\n\tARRAY SIZE:\t%d", size);
}

void PrintResults(Results bubbleResults, Results insertResults, Results shellResults, Results quickResults, int tests) {
    printf("\n\t\t\tSORTING ALGORITHMS SUMMARY (%d cases):\n", tests);

    printf("\nBubble Sort:\n");
    printf("Minimum swaps: %lld\n", bubbleResults.minSwaps);
    printf("Maximum swaps: %lld\n", bubbleResults.maxSwaps);
    printf("Average swaps: %.2f\n", (float)bubbleResults.totalSwaps / tests);
    printf("Minimum comparisons: %lld\n", bubbleResults.minComparisons);
    printf("Maximum comparisons: %lld\n", bubbleResults.maxComparisons);
    printf("Average comparisons: %.2f\n", (float)bubbleResults.totalComparisons / tests);

    printf("\nInsert Sort:\n");
    printf("Minimum swaps: %lld\n", insertResults.minSwaps);
    printf("Maximum swaps: %lld\n", insertResults.maxSwaps);
    printf("Average swaps: %.2f\n", (float)insertResults.totalSwaps / tests);
    printf("Minimum comparisons: %lld\n", insertResults.minComparisons);
    printf("Maximum comparisons: %lld\n", insertResults.maxComparisons);
    printf("Average comparisons: %.2f\n", (float)insertResults.totalComparisons / tests);

    printf("\nShell Sort:\n");
    printf("Minimum swaps: %lld\n", shellResults.minSwaps);
    printf("Maximum swaps: %lld\n", shellResults.maxSwaps);
    printf("Average swaps: %.2f\n", (float)shellResults.totalSwaps / tests);
    printf("Minimum comparisons: %lld\n", shellResults.minComparisons);
    printf("Maximum comparisons: %lld\n", shellResults.maxComparisons);
    printf("Average comparisons: %.2f\n", (float)shellResults.totalComparisons / tests);

    printf("\nQuick Sort:\n");
    printf("Minimum swaps: %lld\n", quickResults.minSwaps);
    printf("Maximum swaps: %lld\n", quickResults.maxSwaps);
    printf("Average swaps: %.2f\n", (float)quickResults.totalSwaps / tests);
    printf("Minimum comparisons: %lld\n", quickResults.minComparisons);
    printf("Maximum comparisons: %lld\n", quickResults.maxComparisons);
    printf("Average comparisons: %.2f\n", (float)quickResults.totalComparisons / tests);
}