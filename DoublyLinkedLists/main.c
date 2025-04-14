#include <stdio.h>
#include "List.h"

void DisplayMenu();
void HandleUnsortedList();
void DisplaySortedMenu();
void HandleSortedList();
void HandleSortedListWithSentinel();

int main() {
    int choice;
    printf("\nDoubly linked list - unsorted(0) or sorted(1):\t");
    scanf("%d", &choice);
    if(choice){
        printf("\nList with sentinel(0) or without(1):\t");
        scanf("%d", &choice);
        if(choice){
            HandleSortedList();
        }else{
            HandleSortedListWithSentinel();
        }
    }else{
        HandleUnsortedList();
    }
    return 0;
}

void DisplayMenu(){
    printf("\n\t\t\tMENU:\n");
    printf("\n\t1.\tAdd element at the beginning of the list.");
    printf("\n\t2.\tAdd element at the end of the list.");
    printf("\n\t3.\tRemove first element from the list.");
    printf("\n\t4.\tRemove last element from the list.");
    printf("\n\t5.\tFind specified element.");
    printf("\n\t6.\tAdd new element before or after specified one.");
    printf("\n\t7.\tRemove specified element.");
    printf("\n\t8.\tLoad list from file.");
    printf("\n\t9.\tSave list to file.");
    printf("\n\t10.\tDisplay list content.");
    printf("\n\t0.\tExit program.");
}

void HandleUnsortedList(){
    List myList = NULL;
    int choice = 0;
    int value = 0;
    int secondValue = 0;
    int secondChoice = 0;
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
                AddBack(&myList, value);
                break;
            case 3:
                printf("\nRemoved value:\t%d", RemoveFront(&myList));
                break;
            case 4:
                printf("\nRemoved value:\t%d", RemoveBack(&myList));
                break;
            case 5:
                printf("\nEnter value to find:\t");
                scanf("%d", &value);
                Find(&myList, value);
                break;
            case 6:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                printf("\nEnter reference value:\t");
                scanf("%d", &secondValue);
                printf("\nAdd before (0) or after (1):\t");
                scanf("%d", &secondChoice);
                if(secondChoice){
                    AddAfter(&myList, secondValue, value);
                }else{
                    AddBefore(&myList, secondValue, value);
                }
                break;
            case 7:
                printf("\nEnter value to remove:\t");
                scanf("%d", &value);
                RemoveNode(&myList, value);
                break;
            case 8:
                FreeList(&myList);
                LoadFromFile(&myList);
                break;
            case 9:
                SaveToFile(myList);
                break;
            case 10:
                printf("\nDisplay from beginning (0) or end (1):\t");
                scanf("%d", &secondChoice);
                if(secondChoice){
                    DisplayReverse(myList);
                }else{
                    Display(myList);
                }
                break;
        }
    }while(choice);
    FreeList(&myList);
}

void DisplaySortedMenu(){
    printf("\n\t\t\tMENU:\n");
    printf("\n\t1.\tAdd element.");
    printf("\n\t2.\tRemove first element from the list.");
    printf("\n\t3.\tRemove last element from the list.");
    printf("\n\t4.\tFind specified element.");
    printf("\n\t5.\tRemove specified element.");
    printf("\n\t6.\tLoad list from file.");
    printf("\n\t7.\tSave list to file.");
    printf("\n\t8.\tDisplay list content.");
    printf("\n\t0.\tExit program.");
}

void HandleSortedList(){
    List myList = NULL;
    int choice = 0;
    int value = 0;
    do{
        DisplaySortedMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                InsertSorted(&myList, value);
                break;
            case 2:
                printf("\nRemoved value:\t%d", PopFront(&myList));
                break;
            case 3:
                printf("\nRemoved value:\t%d", PopBack(&myList));
                break;
            case 4:
                printf("\nEnter value to find:\t");
                scanf("%d", &value);
                Search(&myList, value);
                break;
            case 5:
                printf("\nEnter value to remove:\t");
                scanf("%d", &value);
                printf("\nRemoved value:\t%d", RemoveSpecific(&myList, value));
                break;
            case 6:
                FreeList(&myList);
                LoadFromFile(&myList);
                break;
            case 7:
                SaveToFile(myList);
                break;
            case 8:
                Display(myList);
                break;
        }
    }while(choice);
    FreeList(&myList);
}

void HandleSortedListWithSentinel(){
    List myList = NULL;
    int choice = 0;
    int value = 0;
    AddSentinel(&myList);
    do{
        DisplaySortedMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                InsertSortedWithSentinel(&myList, value);
                break;
            case 2:
                printf("\nRemoved value:\t%d", PopFrontWithSentinel(&myList));
                break;
            case 3:
                printf("\nRemoved value:\t%d", PopBackWithSentinel(&myList));
                break;
            case 4:
                printf("\nEnter value to find:\t");
                scanf("%d", &value);
                SearchWithSentinel(&myList, value);
                break;
            case 5:
                printf("\nEnter value to remove:\t");
                scanf("%d", &value);
                printf("\nRemoved value:\t%d", RemoveSpecificWithSentinel(&myList, value));
                break;
            case 6:
                FreeList(&myList);
                LoadFromFile(&myList);
                break;
            case 7:
                RemoveSentinel(&myList);
                SaveToFile(myList);
                AddSentinel(&myList);
                break;
            case 8:
                Display(myList);
                break;
        }
    }while(choice);
    FreeList(&myList);
}