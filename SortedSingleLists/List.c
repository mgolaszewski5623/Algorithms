#include "List.h"

// Functions with sentinel
void AddSentinel(List *list){
    List newNode = (List)malloc(sizeof(ListNode));
    newNode->key = INT_MAX;
    newNode->next = NULL;
    *list = newNode;
}

void AddWithSentinel(List *list, int value){
    while((*list)->key < value){
        list = &((*list)->next);
    }
    List newNode = (List)malloc(sizeof(ListNode));
    newNode->key = value;
    newNode->next = *list;
    *list = newNode;
}

int GetFirstWithSentinel(List *list){
    int value;
    if((*list)->next != NULL){
        List temp = *list;
        *list = (*list)->next;
        value = temp->key;
        free(temp);
    }
    return value;
}

int GetLastWithSentinel(List *list){
    int value;
    if((*list)->key != INT_MAX){
        while(((*list)->next)->key != INT_MAX) {
            list = &((*list)->next);
        }
        List temp = *list;
        *list = (*list)->next;
        value = temp->key;
        free(temp);
    }
    return value;
}

List* SearchElementWithSentinel(List *list, int value){
    int index = 0;
    while((*list)->key < value){
        list = &((*list)->next);
        index++;
    }
    if((*list)->key == value){
        printf("\nNumber %d found at position:\t%d", value, index);
        return list;
    }else{
        printf("\nNumber %d not found.", value);
        return NULL;
    }
}

void DisplayWithSentinel(List list){
    while(list != NULL){
        if(list->next != NULL){
            printf("\n%d", list->key);
        }
        list = list->next;
    }
}

List MergeWithSentinel(List list1, List list2){
    List mergedList = NULL;
    List *current = &mergedList;
    while((list1->key != INT_MAX) && (list2->key != INT_MAX)){
        if(list1->key < list2->key){
            *current = list1;
            list1 = list1->next;
        }else{
            *current = list2;
            list2 = list2->next;
        }
        current = &((*current)->next);
    }
    if(list1->key != INT_MAX){
        *current = list1;
    }else{
        *current = list2;
    }
    return mergedList;
}

void CompareListsWithSentinel(List *list1, List *list2){
    while ((*list1)->key != INT_MAX && (*list2)->key != INT_MAX) {
        if ((*list1)->key == (*list2)->key) {
            int value = (*list1)->key;
            RemoveElement(list1, value);
            RemoveElement(list2, value);
        } else if ((*list1)->key < (*list2)->key) {
            list1 = &(*list1)->next;
        } else {
            list2 = &(*list2)->next;
        }
    }
}

// Functions without sentinel
void Add(List *list, int value){
    while((*list != NULL) && ((*list)->key < value)){
        list = &((*list)->next);
    }
    List newNode = (List)malloc(sizeof(ListNode));
    newNode->key = value;
    newNode->next = *list;
    *list = newNode;
}

int GetFirst(List *list){
    int value;
    if(*list != NULL){
        List temp = *list;
        *list = (*list)->next;
        value = temp->key;
        free(temp);
    }
    return value;
}

int GetLast(List *list){
    int value;
    if(*list != NULL){
        while((*list)->next != NULL){
            list = &(*list)->next;
        }
        value = (*list)->key;
        free(*list);
        *list = NULL;
    }
    return value;
}

void Display(List list){
    while(list != NULL){
        printf("\n%d", list->key);
        list = list->next;
    }
}

List* SearchElement(List *list, int value){
    int index = 0;
    while(((*list) != NULL) && ((*list)->key < value)){
        list = &((*list)->next);
        index++;
    }
    if(((*list) != NULL) && ((*list)->key == value)){
        printf("\nNumber %d found at position:\t%d", value, index);
        return list;
    }else{
        printf("\nNumber %d not found.", value);
        return NULL;
    }
}

List Merge(List list1, List list2){
    List mergedList = NULL;
    List *current = &mergedList;
    while((list1 != NULL) && (list2 != NULL)){
        if(list1->key < list2->key){
            *current = list1;
            list1 = list1->next;
        }else{
            *current = list2;
            list2 = list2->next;
        }
        current = &((*current)->next);
    }
    if(list1 != NULL){
        *current = list1;
    }else{
        *current = list2;
    }
    return mergedList;
}

void CompareLists(List *list1, List *list2) {
    while (*list1 != NULL && *list2 != NULL) {
        if ((*list1)->key == (*list2)->key) {
            int value = (*list1)->key;
            RemoveElement(list1, value);
            RemoveElement(list2, value);
        } else if ((*list1)->key < (*list2)->key) {
            list1 = &(*list1)->next;
        } else {
            list2 = &(*list2)->next;
        }
    }
}

// Common functions
void FreeList(List *list){
    List current = *list;
    while(current){
        *list = (*list)->next;
        free(current);
        current = *list;
    }
}

int RemoveElement(List *list, int value){
    List *found = SearchElement(&(*list), value);
    if(*found != NULL){
        List temp = *found;
        *found = (*found)->next;
        free(temp);
        return value;
    }
    return INT_MAX;
}

void LoadFromFile(List *list){
    int value;
    FILE *file;
    file = fopen("list.txt", "r");
    if(file == NULL) {
        printf("\nError");
    }
    while (fscanf(file, "%d", &value) == 1) {
        Add(list, value);
    }
    fclose(file);
}

void SaveToFile(List list){
    FILE *file;
    file = fopen("list.txt", "w");
    if(file == NULL){
        printf("\nError");
    }else{
        while(list != NULL){
            if(list->key != INT_MAX)
                fprintf(file, "%d ", list->key);
            list = list->next;
        }
    }
    fclose(file);
}