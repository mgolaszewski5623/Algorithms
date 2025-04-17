#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct FileElement {
    char* name;
    struct FileElement* next;
};
typedef struct FileElement FileElement;
typedef FileElement* FileElementPtr;

struct DirElement {
    char* name;
    struct DirElement** dirs;
    int count;
    FileElementPtr files;
    struct DirElement* parent;
};
typedef struct DirElement DirElement;
typedef DirElement* DirElementPtr;

void PrintSpaces(int level);
void CreateDirectory(DirElementPtr* dir, const char* name, DirElementPtr parent);
void AddFile(DirElementPtr* dir, const char* name);
void AddDirectory(DirElementPtr* dir, const char* name);
void DisplayStructure(DirElementPtr dir, int depth);
void DeleteDirectories(DirElementPtr* dir);
void DeleteFiles(FileElementPtr* f);
void DeleteFile(DirElementPtr* dir, const char* name);
void DeleteDirectory(DirElementPtr* dir, const char* name);
void EnterDirectory(DirElementPtr* dir, const int index);
void GoBackToParent(DirElementPtr* dir);
DirElementPtr SearchDirectory(DirElementPtr dir, const char* name);
void GoToRoot(DirElementPtr* dir);
void Display(DirElementPtr dir);