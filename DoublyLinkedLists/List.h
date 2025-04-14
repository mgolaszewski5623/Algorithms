#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct ListNode{
    int key;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode ListNode;
typedef ListNode* List;

// Unsorted doubly linked list
void AddFront(List *list, int value);
void AddBack(List *list, int value);
int RemoveFront(List *list);
int RemoveBack(List *list);
List* Find(List *list, int value);
void AddBefore(List *list, int referenceValue, int newValue);
void AddAfter(List *list, int referenceValue, int newValue);
int RemoveNode(List *list, int value);
void LoadFromFile(List *list);
void SaveToFile(List list);
void Display(List list);
void DisplayReverse(List list);
void FreeList(List *list);

// Sorted doubly linked list without sentinel
void InsertSorted(List *list, int value);
int PopFront(List *list);
int PopBack(List *list);
List* Search(List *list, int value);
int RemoveSpecific(List *list, int value);

// Sorted doubly linked list with sentinel
void AddSentinel(List *list);
void RemoveSentinel(List *list);
void InsertSortedWithSentinel(List *list, int value);
int PopFrontWithSentinel(List *list);
int PopBackWithSentinel(List *list);
List* SearchWithSentinel(List *list, int value);
int RemoveSpecificWithSentinel(List *list, int value);