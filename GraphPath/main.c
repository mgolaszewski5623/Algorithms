#include "Graphs.h"

int main() {
    Graph* g = CreateGraph(6);

    AddEdge(g, 0, 1, 2);
    AddEdge(g, 0, 2, 4);
    AddEdge(g, 1, 2, 10);
    AddEdge(g, 1, 3, 7);
    AddEdge(g, 2, 3, 3);
    AddEdge(g, 3, 4, 1);
    AddEdge(g, 4, 5, 2);
    AddEdge(g, 2, 5, 5);

    int distance[g->vertexCount];
    int predecessor[g->vertexCount];

    int start = 0;

    Dijkstra(g, start, distance, predecessor);

    PrintResults(distance, predecessor, start, g->vertexCount);

    for (int i = 0; i < g->vertexCount; i++) {
        Edge* edge = g->adjacencyList[i];
        while (edge != NULL) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(g->adjacencyList);
    free(g);

    return 0;
}