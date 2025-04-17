#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Edge {
    int vertex;
    int weight;
    struct Edge* next;
};
typedef struct Edge Edge;
typedef Edge* EdgePtr;

struct Graph {
    int vertexCount;
    EdgePtr* adjacencyList;
};
typedef struct Graph Graph;

Graph* CreateGraph(int count);

void AddEdge(Graph* g, int u, int v, int weight);

void Initialize(Graph* g, int start, int distance[], int predecessor[]);

int Relax(int u, int v, int weight, int distance[], int predecessor[]);

int GetMin(int distance[], int vertices[], int count);

void Dijkstra(Graph* g, int start, int distance[], int predecessor[]);

void PrintResults(int distance[], int predecessor[], int start, int count);