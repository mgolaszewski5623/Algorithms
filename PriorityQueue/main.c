#include <stdio.h>
#include "Queue.h"

void DisplayMenu();

int main() {
    List list = NULL;
    int value = 0;
    int choice = 0;
    char character = '0';
    
    do {
        DisplayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter element value:\t");
                scanf(" %c", &character);
                printf("\nEnter element priority:\t");
                scanf("%d", &value);
                AddElement(&list, value, character);
                break;
            case 2:
                printf("\nRetrieved value:\t%c", GetElement(&list));
                break;
            case 3:
                printf("\nWhich element to change priority:\t");
                scanf(" %c", &character);
                printf("\nEnter new priority:\t");
                scanf("%d", &value);
                ChangePriority(&list, value, character);
                break;
            case 4:
                PrintList(list);
                break;
        }
    } while(choice != 0);
    
    return 0;
}

void DisplayMenu() {
    printf("\n\n\t\t\tMENU\n");
    printf("\n\t1.\tAdd element.");
    printf("\n\t2.\tGet element.");
    printf("\n\t3.\tChange priority.");
    printf("\n\t4.\tPrint queue.");
    printf("\n\t0.\tExit.");
}