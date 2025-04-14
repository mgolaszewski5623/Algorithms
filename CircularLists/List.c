#include "List.h"

// Single linked cyclic list

void AddFront(singleList *list, int value){
    singleList newNode = malloc(sizeof(singleListNode));
    if(*list == NULL){
        newNode->key = value;
        newNode->next = newNode;
        *list = newNode;
    }else{
        newNode->key = (*list)->key;
        (*list)->key = value;
        newNode->next = (*list)->next;
        (*list)->next = newNode;
    }
}

void AddEnd(singleList *list, int value){
    AddFront(list, value);
    (*list) = (*list)->next;
}

int RemoveFront(singleList *list){
    singleList temp;
    int value = INT_MAX;
    if(*list != NULL){
        value = (*list)->key;
        temp = (*list)->next;
        if(temp == *list){
            *list = NULL;
        }else{
            (*list)->key = temp->key;
            (*list)->next = temp->next;
        }
        free(temp);
    }
    return value;
}

int RemoveEnd(singleList *list){
    singleList temp;
    int value = INT_MAX;
    if(*list != NULL){
        if((*list)->next == *list){
            value = (*list)->key;
            free(*list);
            *list = NULL;
        }else{
            singleList current = *list;
            while(current->next->next != *list){
                current = current->next;
            }
            value = current->next->key;
            temp = current->next;
            current->next = *list;
            free(temp);
        }
    }
    return value;
}

singleList* Search(singleList *list, int value){
    if(*list == NULL){
        return NULL;
    }
    else if((*list)->key == value){
        return list;
    }
    singleList start = *list;
    do{
        list = &((*list)->next);
    }while(*list != start && (*list)->key != value);
    if(*list == start){
        return NULL;
    }else{
        return list;
    }
}

void AddBefore(singleList *list, int referenceValue, int newValue){
    singleList *found = Search(list, referenceValue);
    if(found != NULL){
        AddFront(found, newValue);
    }
}

void AddAfter(singleList *list, int referenceValue, int newValue){
    singleList *found = Search(list, referenceValue);
    if(found != NULL){
        AddFront(&((*found)->next), newValue);
    }
}

int RemoveSpecific(singleList *list, int value){
    int removedValue = INT_MAX;
    singleList *found = Search(list, value);
    if(found != NULL){
        removedValue = RemoveFront(found);
    }
    return removedValue;
}

void LoadFromFile(singleList *list){
    int value;
    FILE *file;
    file = fopen("single_list.txt", "r");
    if(file == NULL) {
        printf("\nError opening file");
    }
    while (fscanf(file, "%d", &value) == 1) {
        AddEnd(list, value);
    }
    fclose(file);
}

void SaveToFile(singleList list){
    FILE *file;
    singleList current = list;
    file = fopen("single_list.txt", "w");
    if(file == NULL){
        printf("\nError opening file");
    }else{
        do{
            fprintf(file, "%d ", list->key);
            list = list->next;
        }while(list != current);
    }
    fclose(file);
}

void FreeList(singleList *list){
    if(*list){
        singleList current = *list;
        singleList nextNode;
        singleList last = *list;
        while(last->next != *list){
            last = last->next;
        }
        last->next = NULL;
        while(current != NULL){
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }
    *list = NULL;
}

void DisplayList(singleList list){
    if(list == NULL){
        printf("\nList is empty");
    }else if(list->next == list){
        printf("\nValue:\t%d", list->key);
    }else{
        singleList current = list;
        do{
            printf("\nValue:\t%d", list->key);
            list = list->next;
        }while(list != current);
    }
}

void DisplayReverse(singleList list, singleList start, int counter){
    if(list != NULL){
        if(list == list->next){
            printf("\nValue:\t%d", list->key);
        }else{
            if(list != start){
                DisplayReverse(list->next, start, counter);
                printf("\nValue:\t%d", list->key);
            }else{
                if(counter == 0){
                    counter++;
                    DisplayReverse(list->next, start, counter);
                    printf("\nValue:\t%d", list->key);
                }
            }
        }
    }
}

// Double linked cyclic list

void AddFront2(doubleList *list, int value){
    doubleList newNode;
    newNode = malloc(sizeof(doubleListNode));
    newNode->key = value;
    if(*list == NULL){
        *list = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }else{
        newNode->next = *list;
        newNode->prev = (*list)->prev;
        (*list)->prev->next = newNode;
        (*list)->prev = newNode;
        *list = newNode;
    }
}

void AddEnd2(doubleList *list, int value){
    AddFront2(list, value);
    *list = (*list)->next;
}

int RemoveFront2(doubleList *list){
    doubleList temp;
    int value = INT_MAX;
    if(*list == 0){
        return value;
    }
    value = (*list)->key;
    if(*list == (*list)->prev){
        free(*list);
        *list = 0;
    }else{
        temp = *list;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        *list = temp->next;
        free(temp);
    }
    return value;
}

int RemoveEnd2(doubleList *list){
    if(*list == 0){
        return RemoveFront2(list);
    }else{
        list = &((*list)->prev);
        return RemoveFront2(list);
    }
}

doubleList* Search2(doubleList *list, int value){
    if(*list == NULL){
        return NULL;
    }
    else if((*list)->key == value){
        return list;
    }
    doubleList start = *list;
    do{
        list = &((*list)->next);
    }while(*list != start && (*list)->key != value);
    if(*list == start){
        return NULL;
    }else{
        return list;
    }
}

void AddBefore2(doubleList *list, int referenceValue, int newValue){
    doubleList *found = Search2(list, referenceValue);
    if(found != NULL){
        AddFront2(found, newValue);
    }
}

void AddAfter2(doubleList *list, int referenceValue, int newValue){
    doubleList *found = Search2(list, referenceValue);
    if(found != NULL){
        doubleList *nextNode = &((*found)->next);
        AddFront2(nextNode, newValue);
    }
}

int RemoveSpecific2(doubleList *list, int value){
    int removedValue = INT_MAX;
    doubleList *found = Search2(list, value);
    if(found != NULL){
        removedValue = RemoveFront2(found);
    }
    return removedValue;
}

void LoadFromFile2(doubleList *list){
    int value;
    FILE *file;
    file = fopen("double_list.txt", "r");
    if(file == NULL) {
        printf("\nError opening file");
    }
    while (fscanf(file, "%d", &value) == 1) {
        AddEnd2(list, value);
    }
    fclose(file);
}

void SaveToFile2(doubleList list){
    FILE *file;
    doubleList current = list;
    file = fopen("double_list.txt", "w");
    if(file == NULL){
        printf("\nError opening file");
    }else{
        do{
            fprintf(file, "%d ", list->key);
            list = list->next;
        }while(list != current);
    }
    fclose(file);
}

void FreeList2(doubleList *list){
    if(*list){
        doubleList current = *list;
        doubleList nextNode;
        (*list)->prev->next = NULL;
        while(current != NULL){
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }
    *list = NULL;
}

void DisplayList2(doubleList list){
    doubleList current = list;
    if(list != NULL){
        do{
            printf("\nValue:\t%d", current->key);
            current = current->next;
        }while(current != list);
    }
}

void DisplayReverse2(doubleList list, doubleList start, int counter){
    if(list != NULL){
        if(list == list->next){
            printf("\nValue:\t%d", list->key);
        }else{
            if(list != start){
                DisplayReverse2(list->next, start, counter);
                printf("\nValue:\t%d", list->key);
            }else{
                if(counter == 0){
                    counter++;
                    DisplayReverse2(list->next, start, counter);
                    printf("\nValue:\t%d", list->key);
                }
            }
        }
    }
}

// Task 11

void RemoveEveryKthElement(doubleList *list){
    if((*list == NULL) || (*list == (*list)->next)){
        printf("\nFunction cannot be executed!");
        return;
    }
    int value = 0;
    printf("\nEnter starting value:\t");
    scanf("%d", &value);
    doubleList *found = Search2(list, value);
    if(*found == NULL){
        printf("\nFunction cannot be executed!");
        return;
    }else{
        *list = *found;
    }
    printf("\nEnter k value for removal:\t");
    scanf("%d", &value);
    if(value < 2){
        printf("\nFunction cannot be executed!");
        return;
    }
    RemoveEveryKth(list, value);
}

void RemoveEveryKth(doubleList *list, int k) {
    doubleList current = *list;
    doubleList toRemove;
    while ((*list)->next != *list) {
        for(int i = 1; i <= k; i++){
            current = current->next;
        }
        toRemove = current;
        current = current->next;
        if(toRemove == *list){
            *list = (*list)->next;
        }
        RemoveFront2(&toRemove);
    }
}

void RemoveAllOccurrences(singleList *list, int value){
    if(*list == NULL){
        return;
    }
    singleList current = *list;
    singleList previous = NULL;
    while(*list != NULL && (*list)->key == value){
        RemoveFront(list);
        current = *list;
        if(*list == NULL){
            return;
        }
    }
    previous = *list;
    current = (*list)->next;
    while(current != *list){
        if(current->key == value){
            previous->next = current->next;
            free(current);
            current = previous->next;
        }else{
            previous = current;
            current = current->next;
        }
    }
    if((*list)->key == value){
        RemoveFront(list);
    }
}

void RemoveSecondaryListValues(singleList mainList, singleList *secondaryList){
    if(mainList == NULL || *secondaryList == NULL){
        return;
    }
    singleList start = mainList;
    do{
        int value = mainList->key;
        RemoveAllOccurrences(secondaryList, value);
        mainList = mainList->next;
    }while(mainList != start);
}