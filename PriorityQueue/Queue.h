#include <stdlib.h>
#include <stdio.h>

// Priority queue
struct Element {
    int priority;
    char value;
    struct Element *next;
};
typedef struct Element ListElement;
typedef ListElement* List;

void AddElement(List *l, int p, char w);
char GetElement(List *l);
List* FindElement(List *l, char c);
void ChangePriority(List *l, int p, char w);
void PrintList(List l);