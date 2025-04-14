#include <stdio.h>
#include "List.h"

void PrintMenu();

int main() {
    List myList = 0;
    int choice = 0;
    int value = 0;
    do {
        PrintMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter value:\t");
                scanf("%d", &value);
                AddAtBeginning(&myList, value);
                break;
            case 2:
                printf("\nEnter value:\t");
                scanf("%d", &value);
                AddAtEnd(&myList, value);
                break;
            case 3:
                RemoveFirst(&myList);
                break;
            case 4:
                RemoveLast(&myList);
                break;
            case 5:
                printf("\nEnter value:\t");
                scanf("%d", &value);
                SearchElement(&myList, value);
                break;
            case 6:
                printf("\nEnter value:\t");
                scanf("%d", &value);
                InsertValue(&myList, value);
                break;
            case 7:
                RemoveValue(&myList);
                break;
            case 8:
                FreeList(&myList);
                LoadFromFile(&myList);
                break;
            case 9:
                SaveToFile(myList);
                break;
            case 10:
                DisplayContent(myList);
                break;
            case 11:
                printf("\nRemove normally (0) or recursively (1)?\t");
                scanf("%d", &value);
                if (value) {
                    printf("\nEnter value to remove:\t");
                    scanf("%d", &value);
                    RemoveOccurrencesRecursive(&myList, value);
                } else {
                    printf("\nEnter value to remove:\t");
                    scanf("%d", &value);
                    RemoveOccurrences(&myList, value);
                }
                break;
            case 12:
                printf("\nMost frequent value is: %d", FindMostFrequent(myList));
                break;
            case 13:
                printf("\nRemove values divisible by:\t");
                scanf("%d", &value);
                RemoveDivisible(&myList, value);
                break;
            case 14:
                printf("\nReverse list normally (0) or recursively (1)?\t");
                scanf("%d", &value);
                if (value) {
                    myList = ReverseRecursive(myList);
                } else {
                    Reverse(&myList);
                }
                break;
        }
    } while (choice != 0);
    FreeList(&myList);
    return 0;
}

void PrintMenu() {
    printf("\nNext operation:");
    printf("\n1 - Add element at the beginning of the list");
    printf("\n2 - Add element at the end of the list");
    printf("\n3 - Remove first element of the list");
    printf("\n4 - Remove last element of the list");
    printf("\n5 - Search for an element");
    printf("\n6 - Add new element before or after a specified one");
    printf("\n7 - Remove specified element");
    printf("\n8 - Load list content from file");
    printf("\n9 - Save list content to file");
    printf("\n10 - Display list content");
    printf("\n11 - Remove all occurrences of a value");
    printf("\n12 - Most frequent element");
    printf("\n13 - Remove divisible values");
    printf("\n14 - Reverse list");
    printf("\n0 - Exit program");
}