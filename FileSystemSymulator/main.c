#include <stdio.h>
#include "FSS.h"

void PrintMenu();
void Menu();

int main() {
    Menu();
    return 0;
}

void PrintMenu() {
    printf("\n=======================================================\n");
    printf("\t\t\tMenu:\n");
    printf("1.  Add file\n");
    printf("2.  Add directory\n");
    printf("3.  Delete file\n");
    printf("4.  Delete directory\n");
    printf("5.  Display structure\n");
    printf("6.  Enter subdirectory\n");
    printf("7.  Go back to parent directory\n");
    printf("8.  Search directory\n");
    printf("9.  Go to root directory\n");
    printf("10. Display current directory\n");
    printf("0.  Exit\n");
    printf("========================================================\n");
    printf("\tYour choice: ");
}

void Menu() {
    DirElement* root = NULL;
    DirElement* temp = NULL;
    CreateDirectory(&root, "home", NULL);
    int choice, subChoice;
    char name[256];

    do {
        PrintMenu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                getchar();
                AddFile(&root, name);
                break;
            case 2:
                printf("Enter directory name: ");
                scanf("%s", name);
                getchar();
                AddDirectory(&root, name);
                break;
            case 3:
                printf("Enter file name to delete: ");
                scanf("%s", name);
                getchar();
                DeleteFile(&root, name);
                break;
            case 4:
                printf("Enter directory name to delete: ");
                scanf("%s", name);
                getchar();
                DeleteDirectory(&root, name);
                break;
            case 5:
                DisplayStructure(root, 0);
                break;
            case 6:
                printf("Enter directory index to enter: ");
                scanf("%d", &subChoice);
                getchar();
                EnterDirectory(&root, subChoice);
                break;
            case 7:
                GoBackToParent(&root);
                break;
            case 8:
                printf("Enter directory name to search: ");
                scanf("%s", name);
                getchar();
                temp = SearchDirectory(root, name);
                if (temp != NULL) {
                    root = temp;
                }
                break;
            case 9:
                GoToRoot(&root);
                break;
            case 10:
                Display(root);
                break;
        }
    } while (choice != 0);
    DeleteDirectories(&root);
}