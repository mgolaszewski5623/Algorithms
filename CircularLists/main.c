#include <stdio.h>
#include "List.h"

void DisplayMenu();

void SingleLinkedListMain();

void DoubleLinkedListMain();

singleList ProcessSecondaryList(singleList mainList);

int main() {
    int choice;
    printf("\nDo you want to operate on a single linked list (0) or a double linked list (1):\t");
    scanf("%d", &choice);
    if(choice){
        DoubleLinkedListMain();
    }else{
        SingleLinkedListMain();
    }
    return 0;
}

void DisplayMenu(){
    printf("\n\t\t\tMENU:\n");
    printf("\n\t1.\tAdd element at the beginning of the list.");
    printf("\n\t2.\tAdd element at the end of the list.");
    printf("\n\t3.\tRemove first element from the list.");
    printf("\n\t4.\tRemove last element from the list.");
    printf("\n\t5.\tSearch for a specific element.");
    printf("\n\t6.\tAdd new element before or after a specified one.");
    printf("\n\t7.\tRemove specified element.");
    printf("\n\t8.\tLoad list contents from file.");
    printf("\n\t9.\tSave list contents to file.");
    printf("\n\t10.\tDisplay list contents.");
    printf("\n\t11.\tRemove every k-th element (double linked list only).");
    printf("\n\t12.\tRemove values from secondary list (single linked list only)");
    printf("\n\t0.\tExit program.");
}

void SingleLinkedListMain(){
    int choice = 0;
    int value = 0;
    int subChoice = 0;
    int secondValue = 0;
    singleList myList = NULL;
    do{
        DisplayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddFront(&myList, value);
                break;
            case 2:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddEnd(&myList, value);
                break;
            case 3:
                printf("\nRemoved value:\t%d", RemoveFront(&myList));
                break;
            case 4:
                printf("\nRemoved value:\t%d", RemoveEnd(&myList));
                break;
            case 5:
                printf("\nEnter value to search for:\t");
                scanf("%d", &value);
                Search(&myList, value);
                break;
            case 6:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                printf("\nEnter reference value:\t");
                scanf("%d", &secondValue);
                printf("\nAdd before (0) or after (1):\t");
                scanf("%d", &subChoice);
                if(subChoice){
                    AddAfter(&myList, secondValue, value);
                }else{
                    AddBefore(&myList, secondValue, value);
                }
                break;
            case 7:
                printf("\nEnter value to remove:\t");
                scanf("%d", &value);
                RemoveSpecific(&myList, value);
                break;
            case 8:
                FreeList(&myList);
                LoadFromFile(&myList);
                break;
            case 9:
                SaveToFile(myList);
                break;
            case 10:
                printf("\nDisplay from start (0) or end (1):\t");
                scanf("%d", &subChoice);
                if(subChoice){
                    DisplayReverse(myList, myList, 0);
                }else{
                    DisplayList(myList);
                }
                break;
            case 12:
                myList = ProcessSecondaryList(myList);
                break;
        }
    }while(choice);
    FreeList(&myList);
}

void DoubleLinkedListMain(){
    int choice = 0;
    int value = 0;
    int subChoice = 0;
    int secondValue = 0;
    doubleList myList = NULL;
    do{
        DisplayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddFront2(&myList, value);
                break;
            case 2:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddEnd2(&myList, value);
                break;
            case 3:
                printf("\nRemoved value:\t%d", RemoveFront2(&myList));
                break;
            case 4:
                printf("\nRemoved value:\t%d", RemoveEnd2(&myList));
                break;
            case 5:
                printf("\nEnter value to search for:\t");
                scanf("%d", &value);
                Search2(&myList, value);
                break;
            case 6:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                printf("\nEnter reference value:\t");
                scanf("%d", &secondValue);
                printf("\nAdd before (0) or after (1):\t");
                scanf("%d", &subChoice);
                if(subChoice){
                    AddAfter2(&myList, secondValue, value);
                }else{
                    AddBefore2(&myList, secondValue, value);
                }
                break;
            case 7:
                printf("\nEnter value to remove:\t");
                scanf("%d", &value);
                RemoveSpecific2(&myList, value);
                break;
            case 8:
                FreeList2(&myList);
                LoadFromFile2(&myList);
                break;
            case 9:
                SaveToFile2(myList);
                break;
            case 10:
                printf("\nDisplay from start (0) or end (1):\t");
                scanf("%d", &subChoice);
                if(subChoice){
                    DisplayReverse2(myList, myList, 0);
                }else{
                    DisplayList2(myList);
                }
                break;
            case 11:
                RemoveEveryKthElement(&myList);
                break;
        }
    }while(choice);
    FreeList2(&myList);
}

singleList ProcessSecondaryList(singleList mainList){
    int choice = 0;
    int value = 0;
    int subChoice = 0;
    int secondValue = 0;
    singleList secondaryList = NULL;
    do{
        DisplayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddFront(&secondaryList, value);
                break;
            case 2:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddEnd(&secondaryList, value);
                break;
            case 3:
                printf("\nRemoved value:\t%d", RemoveFront(&secondaryList));
                break;
            case 4:
                printf("\nRemoved value:\t%d", RemoveEnd(&secondaryList));
                break;
            case 5:
                printf("\nEnter value to search for:\t");
                scanf("%d", &value);
                Search(&secondaryList, value);
                break;
            case 6:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                printf("\nEnter reference value:\t");
                scanf("%d", &secondValue);
                printf("\nAdd before (0) or after (1):\t");
                scanf("%d", &subChoice);
                if(subChoice){
                    AddAfter(&secondaryList, secondValue, value);
                }else{
                    AddBefore(&secondaryList, secondValue, value);
                }
                break;
            case 7:
                printf("\nEnter value to remove:\t");
                scanf("%d", &value);
                RemoveSpecific(&secondaryList, value);
                break;
            case 8:
                FreeList(&secondaryList);
                LoadFromFile(&secondaryList);
                break;
            case 9:
                SaveToFile(secondaryList);
                break;
            case 10:
                printf("\nDisplay main list (0) or secondary list (1)\t");
                scanf("%d", &subChoice);
                if(subChoice){
                    DisplayList(secondaryList);
                }else{
                    DisplayList(mainList);
                }
                break;
            case 12:
                RemoveSecondaryListValues(mainList, &secondaryList);
                break;
        }
    }while(choice != 0);
    return mainList;
}