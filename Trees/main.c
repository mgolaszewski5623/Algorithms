#include <stdio.h>
#include "Trees.h"

void DisplayMenu();
void Task16(Tree mainTree);

int main() {
    Tree tree = NULL;
    int choice = 0, value = 0;
    do {
        DisplayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddNode(&tree, value);
                break;
            case 2:
                printf("\nEnter value to remove:\t");
                scanf("%d", &value);
                RemoveValue(&tree, value);
                break;
            case 3:
                printf("\nEnter value to search:\t");
                scanf("%d", &value);
                Search(&tree, value);
                break;
            case 4:
                printf("\nMinimum value is:\t%d", GetMinMax(&tree, 0));
                break;
            case 5:
                printf("\nMaximum value is:\t%d", GetMinMax(&tree, 1));
                break;
            case 6:
                printf("\nPredecessor value is:\t%d", GetSuccessorPredecessor(&tree, 0));
                break;
            case 7:
                printf("\nSuccessor value is:\t%d", GetSuccessorPredecessor(&tree, 1));
                break;
            case 8:
                PrintTree(tree);
                break;
            case 9:
                SaveTree(tree);
                break;
            case 10:
                FreeTree(&tree);
                LoadTree(&tree);
                break;
            case 11:
                Task16(tree);
                break;
        }
    } while(choice != 0);

    return 0;
}

void DisplayMenu() {
    printf("\n\n\t\t\tMENU\n");
    printf("\n\t1.\tAdd element.");
    printf("\n\t2.\tRemove element.");
    printf("\n\t3.\tSearch element.");
    printf("\n\t4.\tFind minimum.");
    printf("\n\t5.\tFind maximum.");
    printf("\n\t6.\tFind predecessor.");
    printf("\n\t7.\tFind successor.");
    printf("\n\t8.\tPrint tree.");
    printf("\n\t9.\tSave tree.");
    printf("\n\t10.\tLoad tree.");
    printf("\n\t11.\tCompare trees.");
    printf("\n\t0.\tExit.");
    printf("\nYour choice:\t");
}

void Task16(Tree mainTree) {
    Tree tree = NULL;
    int choice = 0, value = 0;
    do {
        DisplayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter value to add:\t");
                scanf("%d", &value);
                AddNode(&tree, value);
                break;
            case 2:
                printf("\nEnter value to remove:\t");
                scanf("%d", &value);
                RemoveValue(&tree, value);
                break;
            case 3:
                printf("\nEnter value to search:\t");
                scanf("%d", &value);
                Search(&tree, value);
                break;
            case 4:
                printf("\nMinimum value is:\t%d", GetMinMax(&tree, 0));
                break;
            case 5:
                printf("\nMaximum value is:\t%d", GetMinMax(&tree, 1));
                break;
            case 6:
                printf("\nPredecessor value is:\t%d", GetSuccessorPredecessor(&tree, 0));
                break;
            case 7:
                printf("\nSuccessor value is:\t%d", GetSuccessorPredecessor(&tree, 1));
                break;
            case 8:
                printf("\nPrint main tree(1) or secondary tree(0):\t");
                scanf("%d", &value);
                if(value) {
                    PrintTree(mainTree);
                } else {
                    PrintTree(tree);
                }
                break;
            case 9:
                SaveTree(tree);
                break;
            case 10:
                FreeTree(&tree);
                LoadTree(&tree);
                break;
            case 11:
                value = CompareTrees(&mainTree, &tree);
                if(value) {
                    printf("\nTrees have identical values.");
                } else {
                    printf("\nTrees don't have identical values.");
                }
                break;
        }
    } while(choice != 0);
    FreeTree(&tree);
}