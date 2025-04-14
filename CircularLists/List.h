#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Single linked cyclic list
struct singleNode{
    int key;
    struct singleNode *next;
};
typedef struct singleNode singleListNode;
typedef singleListNode* singleList;

void AddFront(singleList *list, int value);
void AddEnd(singleList *list, int value);
int RemoveFront(singleList *list);
int RemoveEnd(singleList *list);
singleList* Search(singleList *list, int value);
void AddBefore(singleList *list, int referenceValue, int newValue);
void AddAfter(singleList *list, int referenceValue, int newValue);
int RemoveSpecific(singleList *list, int value);
void LoadFromFile(singleList *list);
void SaveToFile(singleList list);
void DisplayList(singleList list);
void DisplayReverse(singleList list, singleList start, int counter);
void FreeList(singleList *list);

// Double linked cyclic list
struct doubleNode{
    int key;
    struct doubleNode *next;
    struct doubleNode *prev;
};
typedef struct doubleNode doubleListNode;
typedef doubleListNode* doubleList;

void AddFront2(doubleList *list, int value);
void AddEnd2(doubleList *list, int value);
int RemoveFront2(doubleList *list);
int RemoveEnd2(doubleList *list);
doubleList* Search2(doubleList *list, int value);
void AddBefore2(doubleList *list, int referenceValue, int newValue);
void AddAfter2(doubleList *list, int referenceValue, int newValue);
int RemoveSpecific2(doubleList *list, int value);
void LoadFromFile2(doubleList *list);
void SaveToFile2(doubleList list);
void DisplayList2(doubleList list);
void DisplayReverse2(doubleList list, doubleList start, int counter);
void FreeList2(doubleList *list);

// Task 11
void RemoveEveryKthElement(doubleList *list);
void RemoveEveryKth(doubleList *list, int k);

// Task 12
void RemoveAllOccurrences(singleList *list, int value);
void RemoveSecondaryListValues(singleList mainList, singleList *secondaryList);