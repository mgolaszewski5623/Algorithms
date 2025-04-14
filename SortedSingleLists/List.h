#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
    int key;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
typedef ListNode *List;

void AddSentinel(List *list);
void AddWithSentinel(List *list, int value);
void Add(List *list, int value);
int GetFirstWithSentinel(List *list);
int GetFirst(List *list);
int GetLast(List *list);
int GetLastWithSentinel(List *list);
List* SearchElement(List *list, int value);
List* SearchElementWithSentinel(List *list, int value);
void Display(List list);
void DisplayWithSentinel(List list);
void FreeList(List* list);
int RemoveElement(List *list, int value);
void SaveToFile(List list);
void LoadFromFile(List *list);
List Merge(List list1, List list2);
List MergeWithSentinel(List list1, List list2);
void CompareLists(List *list1, List *list2);
void CompareListsWithSentinel(List *list1, List *list2);