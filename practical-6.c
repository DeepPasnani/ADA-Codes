#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF  9999
#define MAX  10

typedef struct 
{
    int u, v, weight;
} Edge;

int parent[MAX];

int find(int x) 
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void mergeComp(int x, int y) 
{
    parent[find(x)] = find(y);
}

int compareEdge(const void *a, const void *b) 
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Edge edges[], int edgeCount, int n) 
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    qsort(edges, edgeCount, sizeof(Edge), compareEdge);

    printf("--- Kruskal's MST ---\n");
    printf("Edge     | Weight | Status\n");
    printf("------------------------------\n");

    int totalWeight = 0, edgesUsed = 0;

    for (int i = 0; i < edgeCount && edgesUsed < n - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].weight;

        if (find(u) != find(v)) 
        {
            mergeComp(u, v);
            totalWeight += w;
            edgesUsed++;
            printf("{%d, %d}   |   %2d   | Added\n", u, v, w);
        } 
        else 
        {
            printf("{%d, %d}   |   %2d   | Rejected (cycle)\n", u, v, w);
        }
    }

    printf("------------------------------\n");
    printf("Total MST Weight: %d\n", totalWeight);
}

void prim(int graph[MAX][MAX], int n) 
{
    int inB[MAX]     = {0};
    int nearest[MAX];
    int minDist[MAX];

    inB[1] = 1;
    for (int i = 2; i <= n; i++) 
    {
        minDist[i] = graph[1][i];
        nearest[i] = 1;
    }

    printf("--- Prim's MST (start: node 1) ---\n");
    printf("Edge     | Weight\n");
    printf("-------------------\n");

    int totalWeight = 0;

    for (int iter = 0; iter < n - 1; iter++) 
    {
        int minW = INF, v = -1;
        for (int i = 2; i <= n; i++)
            if (!inB[i] && minDist[i] < minW) { minW = minDist[i]; v = i; }

        printf("{%d, %d}   |   %2d\n", nearest[v], v, minW);
        totalWeight += minW;
        inB[v] = 1;

        for (int i = 2; i <= n; i++)
            if (!inB[i] && graph[v][i] < minDist[i]) 
            {
                minDist[i] = graph[v][i];
                nearest[i] = v;
            }
    }

    printf("-------------------\n");
    printf("Total MST Weight: %d\n", totalWeight);
}

int main() 
{
    int n = 7;

    int graph[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    int edges[][3] = 
    {
        {1,2,1},{2,3,2},{4,5,3},{6,7,4},
        {1,4,4},{2,5,7},{4,7,4},{3,5,8},
        {2,4,9},{3,6,9},{5,7,9},{5,6,10}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < edgeCount; i++) 
    {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        graph[u][v] = graph[v][u] = w;
    }

    Edge edgeList[50];
    for (int i = 0; i < edgeCount; i++) 
    {
        edgeList[i].u      = edges[i][0];
        edgeList[i].v      = edges[i][1];
        edgeList[i].weight = edges[i][2];
    }

    kruskal(edgeList, edgeCount, n);
    printf("\n");
    prim(graph, n);

    return 0;
}
