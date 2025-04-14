#include "List.h"

// Unsorted doubly linked list

void AddFront(List *list, int value){
    List newNode = (List)malloc(sizeof(ListNode));
    newNode->key = value;
    newNode->next = *list;
    if(*list != NULL){
        newNode->prev = (*list)->prev;
        (*list)->prev = newNode;
    }else{
        newNode->prev = NULL;
    }
    *list = newNode;
}

void AddBack(List *list, int value){
    List lastNode = NULL;
    while(*list != NULL) {
        lastNode = *list;
        list = &((*list)->next);
    }
    AddFront(list, value);
    (*list)->prev = lastNode;
}

int RemoveFront(List *list) {
    int value;
    if(*list == NULL){
        return value;
    }
    value = (*list)->key;
    List temp = *list;
    if((*list)->next == NULL){
        *list = NULL;
    }else{
        *list = (*list)->next;
        (*list)->prev = temp->prev;
    }
    free(temp);
    return value;
}

int RemoveBack(List *list){
    int value;
    if(*list == NULL){
        return value;
    }
    while((*list)->next){
        list = &((*list)->next);
    }
    value = (*list)->key;
    free(*list);
    *list = NULL;
    return value;
}

List* Find(List *list, int value){
    while((*list != NULL) && ((*list)->key != value)){
        list = &((*list)->next);
    }
    return list;
}

void AddBefore(List *list, int referenceValue, int newValue){
    list = Find(list, referenceValue);
    if(*list){
        AddFront(list, newValue);
    }
}

void AddAfter(List *list, int referenceValue, int newValue){
    List *nextNode;
    list = Find(list, referenceValue);
    if(*list){
        nextNode = &((*list)->next);
        AddFront(nextNode, newValue);
        (*nextNode)->prev = *list;
    }
}

int RemoveNode(List *list, int value){
    List *nodeToRemove = Find(list, value);
    return RemoveFront(nodeToRemove);
}

void LoadFromFile(List *list){
    int value;
    FILE *file;
    file = fopen("list.txt", "r");
    if(file == NULL){
        printf("\nError");
    }else{
        while(fscanf(file, "%d", &value) == 1){
            AddBack(list, value);
        }
    }
    fclose(file);
}

void SaveToFile(List list){
    FILE *file;
    file = fopen("list.txt", "w");
    if(file == NULL){
        printf("\nError");
    }else{
        while(list){
            fprintf(file, "%d ", list->key);
            list = list->next;
        }
    }
    fclose(file);
}

void Display(List list){
    while(list != NULL){
        printf("\nValue:\t%d", list->key);
        list = list->next;
    }
}

void DisplayReverse(List list){
    if(list){
        if(!list->next) {
            printf("\nValue:\t%d", list->key);
        }else{
            DisplayReverse(list->next);
            printf("\nValue:\t%d", list->key);
        }
    }
}

void FreeList(List *list){
    List temp = *list;
    while(temp){
        *list = (*list)->next;
        free(temp);
        temp = *list;
    }
}

// Sorted doubly linked list without sentinel

void InsertSorted(List *list, int value){
    while((*list) && ((*list)->key < value)){
        list = &((*list)->next);
    }
    List newNode = malloc(sizeof(ListNode));
    newNode->key = value;
    newNode->next = *list;
    if(*list){
        newNode->prev = (*list)->prev;
        (*list)->prev = newNode;
    }else{
        newNode->prev = NULL;
    }
    *list = newNode;
}

int PopFront(List *list){
    int value = INT_MAX;
    if(*list == NULL){
        return value;
    }
    value = (*list)->key;
    List temp = *list;
    if((*list)->next == NULL){
        *list = NULL;
    }else{
        *list = (*list)->next;
        (*list)->prev = temp->prev;
    }
    free(temp);
    return value;
}

int PopBack(List *list){
    int value = INT_MAX;
    if(*list){
        while((*list)->next){
            list = &((*list)->next);
        }
        value = (*list)->key;
        free(*list);
        *list = NULL;
    }
    return value;
}

List* Search(List *list, int value){
    while((*list != NULL) && ((*list)->key < value)){
        list = &((*list)->next);
    }
    if((*list) != NULL && (*list)->key == value){
        return list;
    }else{
        return NULL;
    }
}

int RemoveSpecific(List *list, int value){
    int result = INT_MAX;
    List *node = Search(list, value);
    if(node){
        result = RemoveFront(node);
    }
    return result;
}

// Sorted doubly linked list with sentinel

void AddSentinel(List *list){
    AddBack(list, INT_MAX);
}

void RemoveSentinel(List *list){
    while((*list)->next){
        list = &((*list)->next);
    }
    if((*list)->key == INT_MAX){
        free(*list);
        *list = NULL;
    }
}

void InsertSortedWithSentinel(List *list, int value){
    while((*list)->key < value){
        list = &((*list)->next);
    }
    List newNode = malloc(sizeof(ListNode));
    newNode->key = value;
    newNode->next = *list;
    if(*list){
        newNode->prev = (*list)->prev;
        (*list)->prev = newNode;
    }else{
        newNode->prev = NULL;
    }
    *list = newNode;
}

int PopFrontWithSentinel(List *list){
    int value = INT_MAX;
    if((*list)->key != INT_MAX){
        value = (*list)->key;
        List temp = *list;

        *list = (*list)->next;
        (*list)->prev = temp->prev;
        free(temp);
    }
    return value;
}

int PopBackWithSentinel(List *list){
    int value = INT_MAX;
    if((*list)->key != INT_MAX){
        while(((*list)->next)->key != INT_MAX){
            list = &((*list)->next);
        }
        List temp = *list;
        value = (*list)->key;
        *list = (*list)->next;
        (*list)->prev = temp->prev;
        free(temp);
    }
    return value;
}

List* SearchWithSentinel(List *list, int value){
    while((*list)->key < value){
        list = &((*list)->next);
    }
    if((*list)->key != INT_MAX && (*list)->key == value){
        return list;
    }else{
        return NULL;
    }
}

int RemoveSpecificWithSentinel(List *list, int value){
    List *node = SearchWithSentinel(list, value);
    printf("ok");
    if(node){
        printf("ok");
        return RemoveFront(node);
    }else{
        printf("?");
        return INT_MAX;
    }
}