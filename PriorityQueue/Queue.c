#include "Queue.h"

void AddElement(List *l, int p, char w) {
    while((*l != NULL) && ((*l)->priority > p)) {
        l = &((*l)->next);
    }
    List newElement = (List)malloc(sizeof(ListElement));
    newElement->priority = p;
    newElement->value = w;
    newElement->next = *l;
    *l = newElement;
}

char GetElement(List *l) {
    char result;
    if(*l != NULL) {
        List temp = *l;
        *l = (*l)->next;
        result = temp->value;
        free(temp);
    }
    return result;
}

List* FindElement(List *l, char c) {
    while((*l != NULL) && ((*l)->value != c)) {
        l = &((*l)->next);
    }
    return l;
}

void ChangePriority(List *l, int p, char w) {
    List *found = FindElement(l, w);
    if(*found != NULL) {
        char value = GetElement(found);
        AddElement(l, p, value);
        printf("\nOperation successful.");
    } else {
        printf("\nOperation failed.");
    }
}

void PrintList(List l) {
    int i = 1;
    while(l != NULL) {
        printf("\nElement no %d", i++);
        printf("\n\tPriority:\t%d", l->priority);
        printf("\n\tValue:\t%c", l->value);
        l = l->next;
    }
}