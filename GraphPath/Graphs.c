#include "Graphs.h"

Graph* CreateGraph(int count) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertexCount = count;
    g->adjacencyList = (EdgePtr*)malloc(count * sizeof(EdgePtr));
    for(int i = 0; i < count; i++) {
        g->adjacencyList[i] = NULL;
    }
    return g;
}

void AddEdge(Graph* g, int u, int v, int weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->vertex = v;
    edge->weight = weight;
    edge->next = g->adjacencyList[u];
    g->adjacencyList[u] = edge;
}

void Initialize(Graph* g, int start, int distance[], int predecessor[]) {
    for(int v = 0; v < g->vertexCount; v++) {
        distance[v] = INT_MAX;
        predecessor[v] = -1;
    }
    distance[start] = 0;
}

int Relax(int u, int v, int weight, int distance[], int predecessor[]) {
    if(distance[v] > distance[u] + weight) {
        distance[v] = distance[u] + weight;
        predecessor[v] = u;
        return 1;
    }
    return 0;
}

int GetMin(int distance[], int vertices[], int count) {
    int min = INT_MAX;
    int minIndex = -1;
    for(int i = 0; i < count; i++) {
        if(vertices[i] != -1 && distance[vertices[i]] < min) {
            min = distance[vertices[i]];
            minIndex = i;
        }
    }
    return (minIndex != -1) ? vertices[minIndex] : -1;
}

void Dijkstra(Graph* g, int start, int distance[], int predecessor[]) {
    Initialize(g, start, distance, predecessor);
    int* vertices = (int*)malloc(g->vertexCount * sizeof(int));
    for(int i = 0; i < g->vertexCount; i++) {
        vertices[i] = i;
    }

    while(1) {
        int u = GetMin(distance, vertices, g->vertexCount);
        if(u == -1) {
            break;
        }
        vertices[u] = -1;
        for(Edge* e = g->adjacencyList[u]; e != NULL; e = e->next) {
            int v = e->vertex;
            int weight = e->weight;
            Relax(u, v, weight, distance, predecessor);
        }
    }
    free(vertices);
}

void PrintResults(int distance[], int predecessor[], int start, int count) {
    for (int v = 0; v < count; v++) {
        if (distance[v] == INT_MAX) {
            printf("No path to vertex %d\n", v);
        } else {
            printf("Distance to vertex %d: %d\n", v, distance[v]);
        }
    }
}