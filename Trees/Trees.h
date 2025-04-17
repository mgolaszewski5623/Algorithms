#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *right;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *parent;
};
typedef struct BinaryTreeNode BinaryTreeNode;
typedef BinaryTreeNode* Tree;

// Wrapper functions
int GetMinMax(Tree *tree, int isMax);
int GetSuccessorPredecessor(Tree *tree, int isSuccessor);

// Main functions
void PrintTreeRecursive(Tree tree, int depth);
void PrintTree(Tree tree);
void AddNode(Tree *tree, int value);
Tree* Search(Tree *tree, int value);
void RemoveValue(Tree *tree, int value);
void RemoveNode(Tree *tree);
Tree *FindMax(Tree *tree);
Tree *FindMin(Tree *tree);
Tree *GetSuccessor(Tree *tree);
Tree *GetPredecessor(Tree *tree);
void SaveTree(Tree tree);
void SaveTreeRecursive(FILE *file, Tree tree);
void LoadTree(Tree *tree);
void FreeTree(Tree *tree);
int CompareTrees(Tree *tree1, Tree *tree2);