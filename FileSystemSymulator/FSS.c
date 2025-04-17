#include "FSS.h"

void PrintSpaces(int level) {
    for (int i = 0; i < level * 5; i++) {
        printf(" ");
    }
}

void CreateDirectory(DirElementPtr* dir, const char* name, DirElementPtr parent) {
    *dir = (DirElementPtr)malloc(sizeof(DirElement));
    (*dir)->name = strdup(name);
    (*dir)->dirs = NULL;
    (*dir)->count = 0;
    (*dir)->files = NULL;
    (*dir)->parent = parent;
}

void AddFile(DirElementPtr* dir, const char* name) {
    if (*dir == NULL) {
        return;
    }

    FileElementPtr newFile = (FileElementPtr)malloc(sizeof(FileElement));
    newFile->name = strdup(name);
    newFile->next = NULL;

    if ((*dir)->files == NULL) {
        (*dir)->files = newFile;
    } else {
        FileElementPtr current = (*dir)->files;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newFile;
    }
}

void AddDirectory(DirElementPtr* dir, const char* name) {
    if (*dir == NULL) {
        return;
    }

    DirElementPtr newDirectory = NULL;
    CreateDirectory(&newDirectory, name, *dir);

    (*dir)->dirs = (DirElementPtr*)realloc((*dir)->dirs, ((*dir)->count + 1) * sizeof(DirElementPtr));
    (*dir)->dirs[(*dir)->count] = newDirectory;
    (*dir)->count++;
}

void DisplayStructure(DirElementPtr dir, int depth) {
    if (dir == NULL) {
        return;
    }

    PrintSpaces(depth);
    printf("d-%s\n", dir->name);

    FileElementPtr f = dir->files;
    while (f) {
        PrintSpaces(depth + 1);
        printf("f-%s\n", f->name);
        f = f->next;
    }

    for (int i = 0; i < dir->count; i++) {
        DisplayStructure(dir->dirs[i], depth + 1);
    }
}

void DeleteFiles(FileElementPtr* f) {
    while (*f) {
        FileElementPtr temp = *f;
        *f = (*f)->next;
        free(temp->name);
        free(temp);
    }
}

void DeleteDirectories(DirElementPtr* dir) {
    if (*dir == NULL) {
        return;
    }

    DeleteFiles(&(*dir)->files);

    for (int i = 0; i < (*dir)->count; i++) {
        DeleteDirectories(&(*dir)->dirs[i]);
    }
    free((*dir)->dirs);
    free((*dir)->name);
    free(*dir);
    *dir = NULL;
}

void DeleteFile(DirElementPtr* dir, const char* name) {
    if (*dir == NULL || (*dir)->files == NULL) {
        return;
    }

    FileElementPtr* current = &(*dir)->files;
    while (*current) {
        if (strcmp((*current)->name, name) == 0) {
            FileElementPtr temp = *current;
            *current = (*current)->next;
            free(temp->name);
            free(temp);
            return;
        }
        current = &((*current)->next);
    }
}

void DeleteDirectory(DirElementPtr* dir, const char* name) {
    if (*dir == NULL || (*dir)->count == 0) return;

    for (int i = 0; i < (*dir)->count; i++) {
        if (strcmp((*dir)->dirs[i]->name, name) == 0) {
            DeleteDirectories(&((*dir)->dirs[i]));

            if (i != (*dir)->count - 1) {
                (*dir)->dirs[i] = (*dir)->dirs[(*dir)->count - 1];
            }

            (*dir)->count--;
            (*dir)->dirs = (DirElementPtr*)realloc((*dir)->dirs, (*dir)->count * sizeof(DirElementPtr));
            return;
        }
    }
}

void EnterDirectory(DirElementPtr* dir, const int index) {
    int idx = abs(index);
    if (*dir == NULL || idx >= (*dir)->count) {
        return;
    }

    (*dir) = (*dir)->dirs[idx];
}

void GoBackToParent(DirElementPtr* dir) {
    if (*dir == NULL || (*dir)->parent == NULL) {
        return;
    }

    *dir = (*dir)->parent;
}

DirElementPtr SearchDirectory(DirElementPtr dir, const char* name) {
    if (dir == NULL) {
        return NULL;
    }

    if (strcmp(dir->name, name) == 0) {
        return dir;
    }

    for (int i = 0; i < dir->count; i++) {
        DirElementPtr foundDir = SearchDirectory(dir->dirs[i], name);
        if (foundDir != NULL) {
            return foundDir;
        }
    }

    return NULL;
}

void GoToRoot(DirElementPtr* dir) {
    while (*dir != NULL && (*dir)->parent != NULL) {
        *dir = (*dir)->parent;
    }
}

void Display(DirElementPtr dir) {
    if (dir == NULL) {
        return;
    }

    printf("d-%s\n", dir->name);

    FileElementPtr f = dir->files;
    while (f) {
        PrintSpaces(1);
        printf("f-%s\n", f->name);
        f = f->next;
    }

    for (int i = 0; i < dir->count; i++) {
        PrintSpaces(1);
        printf("d-%s\n", dir->dirs[i]->name);
    }
}