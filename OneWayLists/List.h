#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *next;
};

typedef struct Node ListNode;
typedef ListNode *List;

void AddAtBeginning(List *list, int value);
void AddAtEnd(List *list, int value);
void RemoveFirst(List *list);
void RemoveLast(List *list);
List* SearchElement(List *list, int value);
void InsertValue(List *list, int value);
void RemoveValue(List *list);
void LoadFromFile(List *list);
void SaveToFile(List list);
void DisplayContent(List list);
void DisplayFromBeginning(List list);
void DisplayFromEnd(List list);
void FreeList(List *list);
void RemoveOccurrences(List *list, int value);
void RemoveOccurrencesRecursive(List *list, int value);
int FindMostFrequent(List list);
void RemoveDivisible(List *list, int divisor);
void Reverse(List *list);
List ReverseRecursive(List list);