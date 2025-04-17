#include "Trees.h"

// Wrapper functions
int GetMinMax(Tree *tree, int isMax) {
    Tree *result;
    if(isMax) {
        result = FindMax(tree);
    } else {
        result = FindMin(tree);
    }
    if(*result != NULL) {
        return (*result)->key;
    } else {
        return INT_MAX;
    }
}

int GetSuccessorPredecessor(Tree *tree, int isSuccessor) {
    Tree *result;
    if(isSuccessor) {
        result = GetSuccessor(tree);
    } else {
        result = GetPredecessor(tree);
    }
    if(*result != NULL) {
        return (*result)->key;
    } else {
        return INT_MAX;
    }
}

// Main functions
void PrintTreeRecursive(Tree tree, int depth) {
    if(tree == 0) {
        return;
    }
    PrintTreeRecursive(tree->left, depth + 1);
    for (int i = 0; i < depth; i++) {
        putchar('\t');
    }
    printf("%d\n", tree->key);
    PrintTreeRecursive(tree->right, depth + 1);
}

void PrintTree(Tree tree) {
    PrintTreeRecursive(tree, 0);
    putchar('\n');
}

void AddNode(Tree *tree, int value) {
    Tree parent = *tree;
    Tree newNode = (Tree)malloc(sizeof(BinaryTreeNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    while(*tree != NULL) {
        parent = *tree;
        if((*tree)->key >= value) {
            tree = &((*tree)->left);
        } else {
            tree = &((*tree)->right);
        }
    }
    *tree = newNode;
    newNode->parent = parent;
}

Tree* Search(Tree *tree, int value) {
    while((*tree != NULL) && ((*tree)->key != value)) {
        tree = ((*tree)->key > value) ? &((*tree)->left) : &((*tree)->right);
    }
    return tree;
}

void RemoveNode(Tree *tree) {
    Tree nodeToRemove, **maxLeft;
    if(*tree != NULL) {
        if(((*tree)->left != NULL) && ((*tree)->right != NULL)) {
            maxLeft = FindMax(&(*tree)->left);
            (*tree)->key = (*maxLeft)->key;
            nodeToRemove = *maxLeft;
            *maxLeft = nodeToRemove->left;
        } else {
            nodeToRemove = *tree;
            *tree = (nodeToRemove->left != NULL) ? nodeToRemove->left : nodeToRemove->right;
        }
        if (*tree != NULL) {
            (*tree)->parent = nodeToRemove->parent;
        }
        free(nodeToRemove);
    }
}

Tree *FindMax(Tree *tree) {
    if(*tree != NULL) {
        while((*tree)->right != NULL) {
            tree = &((*tree)->right);
        }
    }
    return tree;
}

Tree *FindMin(Tree *tree) {
    if(*tree != NULL) {
        while((*tree)->left != NULL) {
            tree = &((*tree)->left);
        }
    }
    return tree;
}

void RemoveValue(Tree *tree, int value) {
    Tree *node = Search(tree, value);
    if(*node != NULL) {
        RemoveNode(node);
    }
}

Tree *GetSuccessor(Tree *tree) {
    if(*tree == NULL) {
        return NULL;
    }
    if((*tree)->right != NULL) {
        Tree *minNode = FindMin(&((*tree)->right));
        return minNode;
    } else {
        Tree *parent = &((*tree)->parent);
        Tree *current = tree;
        while(*parent != NULL && *current == (*parent)->right) {
            current = parent;
            parent = &((*parent)->parent);
        }
        return parent;
    }
}

Tree *GetPredecessor(Tree *tree) {
    if(*tree == NULL) {
        return NULL;
    }
    if((*tree)->left != NULL) {
        Tree *maxNode = FindMax(&((*tree)->left));
        return maxNode;
    } else {
        Tree *parent = &((*tree)->parent);
        Tree *current = tree;
        while(*parent != NULL && *current == (*parent)->left) {
            current = parent;
            parent = &((*parent)->parent);
        }
        return parent;
    }
}

void SaveTreeRecursive(FILE *file, Tree tree) {
    if (tree != NULL) {
        fprintf(file, "%d ", tree->key);
        SaveTreeRecursive(file, tree->left);
        SaveTreeRecursive(file, tree->right);
    }
}

void SaveTree(Tree tree) {
    FILE *file = fopen("tree.txt", "w");
    if (file == NULL) {
        printf("\nError");
        return;
    }
    SaveTreeRecursive(file, tree);
    fclose(file);
}

void LoadTree(Tree *tree) {
    int value;
    FILE *file = fopen("tree.txt", "r");
    if(file == NULL) {
        printf("\nError");
        return;
    }
    while (fscanf(file, "%d", &value) == 1) {
        AddNode(tree, value);
    }
    fclose(file);
}

void FreeTree(Tree *tree) {
    while(*tree != NULL) {
        RemoveNode(tree);
    }
}

int CompareTrees(Tree *tree1, Tree *tree2) {
    Tree *current1 = FindMin(tree1);
    Tree *current2 = FindMin(tree2);
    while(*current1 && *current2) {
        if((*current1)->key != (*current2)->key) {
            return 0;
        }
        current1 = GetSuccessor(current1);
        current2 = GetSuccessor(current2);
    }
    return *current1 == *current2;
}