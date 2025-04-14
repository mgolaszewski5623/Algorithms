#include "List.h"

void AddAtBeginning(List *list, int value) {
    List newNode = (List)malloc(sizeof(ListNode));
    newNode->key = value;
    newNode->next = *list;
    *list = newNode;
}

void AddAtEnd(List *list, int value) {
    List newNode = (List)malloc(sizeof(ListNode));
    newNode->key = value;
    newNode->next = 0;
    while (*list) {
        list = &(*list)->next;
    }
    *list = newNode;
}

void RemoveFirst(List *list) {
    List temp;
    if (*list != 0) {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

void RemoveLast(List *list) {
    if (*list == 0) {
        return;
    }
    while ((*list)->next) {
        list = &(*list)->next;
    }
    free(*list);
    *list = 0;
}

List* SearchElement(List *list, int value) {
    int index = 0;
    while ((*list != NULL) && ((*list)->key != value)) {
        list = &((*list)->next);
        index++;
    }
    if (list != NULL) {
        printf("\nValue found at position\t%d", index);
    } else {
        printf("\nValue not found.");
    }
    return list;
}

void InsertValue(List *list, int value) {
    int targetValue;
    printf("\nEnter the value next to which you want to insert:\t");
    scanf("%d", &targetValue);
    List *found = SearchElement(&(*list), targetValue);
    if (*found != NULL) {
        printf("\nInsert before (0) or after (1)?");
        scanf("%d", &targetValue);
        if (targetValue) {
            AddAtBeginning(&((*found)->next), value);
        } else {
            AddAtBeginning(found, value);
        }
    }
}

void RemoveValue(List *list) {
    int targetValue;
    printf("\nEnter value to remove:\t");
    scanf("%d", &targetValue);
    List *found = SearchElement(&(*list), targetValue);
    if (*found != NULL) {
        RemoveFirst(&(*found));
    }
}

void LoadFromFile(List *list) {
    int value;
    FILE *file;
    file = fopen("list.txt", "r");
    if (file == NULL) {
        printf("\nError");
    }
    while (fscanf(file, "%d", &value) == 1) {
        AddAtEnd(list, value);
    }
    fclose(file);
}

void SaveToFile(List list) {
    FILE *file;
    file = fopen("list.txt", "w");
    if (file == NULL) {
        printf("\nError");
    } else {
        while (list != NULL) {
            fprintf(file, "%d ", list->key);
            list = list->next;
        }
    }
    fclose(file);
}

void DisplayContent(List list) {
    int choice;
    printf("\nDisplay from beginning (0) or end (1)?");
    scanf("%d", &choice);
    if (choice) {
        DisplayFromEnd(list);
    } else {
        DisplayFromBeginning(list);
    }
}

void DisplayFromBeginning(List list) {
    while (list != NULL) {
        printf("\nValue:\t%d", list->key);
        list = list->next;
    }
}

void DisplayFromEnd(List list) {
    if (list) {
        if (list->next == 0) {
            printf("\nValue:\t%d", list->key);
        } else {
            DisplayFromEnd(list->next);
            printf("\nValue:\t%d", list->key);
        }
    }
}

void RemoveOccurrences(List *list, int value) {
    while (*list != NULL) {
        if ((*list)->key == value) {
            RemoveFirst(&(*list));
        } else {
            list = &(*list)->next;
        }
    }
}

void RemoveOccurrencesRecursive(List *list, int value) {
    if (*list == NULL) {
        return;
    }
    if ((*list)->key == value) {
        RemoveFirst(&(*list));
        RemoveOccurrencesRecursive(&(*list), value);
    } else {
        RemoveOccurrencesRecursive(&(*list)->next, value);
    }
}

void FreeList(List *list) {
    List current = *list;
    while (current) {
        *list = (*list)->next;
        free(current);
        current = *list;
    }
}

int FindMostFrequent(List list) {
    List current = list, iterator;
    int result = 0, maxCount = 0, count;

    while (current != NULL) {
        count = 0;
        iterator = current;
        while (iterator != NULL) {
            if (current->key == iterator->key) {
                count++;
            }
            iterator = iterator->next;
        }
        if (count > maxCount) {
            maxCount = count;
            result = current->key;
        }
        current = current->next;
    }
    return result;
}

void RemoveDivisible(List *list, int divisor) {
    if (*list == NULL) {
        return;
    }
    if ((*list)->key % divisor == 0) {
        RemoveFirst(&(*list));
        RemoveDivisible(&(*list), divisor);
    } else {
        RemoveDivisible(&(*list)->next, divisor);
    }
}

void Reverse(List *list) {
    List current, previous, next;
    current = *list;
    next = NULL;
    previous = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *list = previous;
}

List ReverseRecursive(List list) {
    if (list == NULL) {
        return NULL;
    } else if (list->next == NULL) {
        return list;
    } else {
        List rest = ReverseRecursive(list->next);
        list->next->next = list;
        list->next = NULL;
        return rest;
    }
}