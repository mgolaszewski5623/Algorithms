#include <stdio.h>
#include "List.h"

void PrintMenu();
List MergeLists(List list1);
List MergeListsWithSentinel(List list1);
void SecondaryMenu();

int main() {
    int choice = 0;
    int value = 0;
    List myList = NULL;

    printf("\nDo you want to use list with sentinel(1) or without(0)");
    scanf("%d", &choice);
    if(choice){
        AddSentinel(&myList);
        do{
            PrintMenu();
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("\nEnter value to add:\t");
                    scanf("%d", &value);
                    AddWithSentinel(&myList, value);
                    break;
                case 2:
                    printf("\nFirst element:\t%d", GetFirstWithSentinel(&myList));
                    break;
                case 3:
                    printf("\nLast element:\t%d", GetLastWithSentinel(&myList));
                    break;
                case 4:
                    printf("\nEnter value to search:\t");
                    scanf("%d", &value);
                    SearchElementWithSentinel(&myList, value);
                    break;
                case 5:
                    printf("\nEnter value to remove:\t");
                    scanf("%d", &value);
                    value = RemoveElement(&myList, value);
                    if(value != INT_MAX)
                        printf("\nRemoved value:\t%d", value);
                    break;
                case 6:
                    SaveToFile(myList);
                    break;
                case 7:
                    FreeList(&myList);
                    AddSentinel(&myList);
                    LoadFromFile(&myList);
                    break;
                case 8:
                    myList = MergeListsWithSentinel(myList);
                    break;
                case 10:
                    DisplayWithSentinel(myList);
                    break;
            }
        }while(choice != 0);
    }else{
        do{
            PrintMenu();
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("\nEnter value to add:\t");
                    scanf("%d", &value);
                    Add(&myList, value);
                    break;
                case 2:
                    printf("\nFirst element:\t%d", GetFirst(&myList));
                    break;
                case 3:
                    printf("\nLast element:\t%d", GetLast(&myList));
                    break;
                case 4:
                    printf("\nEnter value to search:\t");
                    scanf("%d", &value);
                    SearchElement(&myList, value);
                    break;
                case 5:
                    printf("\nEnter value to remove:\t");
                    scanf("%d", &value);
                    value = RemoveElement(&myList, value);
                    if(value != INT_MAX)
                        printf("\nRemoved value:\t%d", value);
                    break;
                case 6:
                    SaveToFile(myList);
                    break;
                case 7:
                    FreeList(&myList);
                    LoadFromFile(&myList);
                    break;
                case 8:
                    myList = MergeLists(myList);
                    break;
                case 10:
                    Display(myList);
                    break;
            }
        }while(choice != 0);
    }
    FreeList(&myList);
    myList = NULL;

    return 0;
}

void PrintMenu(){
    printf("\n\n\n\t\t\tMENU\t\t\t");
    printf("\n1.\tAdd element.");
    printf("\n2.\tGet first element.");
    printf("\n3.\tGet last element.");
    printf("\n4.\tFind element.");
    printf("\n5.\tRemove element.");
    printf("\n6.\tSave to file.");
    printf("\n7.\tLoad from file.");
    printf("\n8.\tMerge lists.");
    printf("\n10.\tDisplay list.");
    printf("\n0.\tExit program.");
}

void SecondaryMenu(){
    printf("\n\n\n\t\tMENU\t\t\t");
    printf("\n1.\tAdd element.");
    printf("\n7.\tLoad from file.");
    printf("\n8.\tMerge lists.");
    printf("\n9.\tCompare lists.");
    printf("\n10.\tDisplay list.");
    printf("\n11.\tDisplay main list.");
    printf("\n0.\tExit program.");
}

List MergeLists(List list1){
    List list2 = NULL;
    int choice = 1;
    int value = 0;
    do{
        SecondaryMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                Add(&list2, value);
                break;
            case 7:
                FreeList(&list2);
                LoadFromFile(&list2);
                break;
            case 8:
                list1 = Merge(list1, list2);
                break;
            case 9:
                CompareLists(&list1, &list2);
            case 10:
                Display(list2);
                break;
            case 11:
                Display(list1);
                break;
        }
    }while(choice != 0);
    list2 = NULL;
    return list1;
}

List MergeListsWithSentinel(List list1){
    List list2 = NULL;
    AddSentinel(&list2);
    int choice = 1;
    int value = 0;
    do{
        SecondaryMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddWithSentinel(&list2, value);
                break;
            case 7:
                FreeList(&list2);
                AddSentinel(&list2);
                LoadFromFile(&list2);
                break;
            case 8:
                list1 = MergeWithSentinel(list1, list2);
                break;
            case 9:
                CompareListsWithSentinel(&list1, &list2);
                break;
            case 10:
                DisplayWithSentinel(list2);
                break;
            case 11:
                DisplayWithSentinel(list1);
                break;
        }
    }while(choice != 0);
    list2 = NULL;
    return list1;
}