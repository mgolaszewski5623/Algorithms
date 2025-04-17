#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct {
    long long minComparisons;
    long long maxComparisons;
    long long totalComparisons;
    long long minSwaps;
    long long maxSwaps;
    long long totalSwaps;
} Results;

void InitializeResults(Results *r);

void UpdateResults(Results *r, int swaps, int comparisons);

// Bubble sort
void BubbleSort(int array[], int size, Results *r);

// Insert sort
void InsertSort(int array[], int size, Results *r);

// Shell sort (based on insert sort)
void ShellSort(int array[], int size, Results *r);

// Quick sort
void QuickSortStart(int array[], int size, Results *r);

int Partition(int array[], int low, int high, long long *swaps, long long *comparisons);

void QuickSort(int array[], int low, int high, long long *swaps, long long *comparisons);

// Functions for testing algorithms
void Start(int range);

void PrintResults(Results bubbleResults, Results insertResults, Results shellResults, Results quickResults, int tests);