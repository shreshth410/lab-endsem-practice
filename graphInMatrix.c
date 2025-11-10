#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX];

void createGraph(int n, int edges, int directed){
    if (n > MAX){
        return;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            graph[i][j] = 0;
        }
    }

    int u, v;
    printf("Enter edges one by one: \n");
    for (int i = 0; i < edges; i++){
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        if (!directed){
            graph[v][u] = 1;
        }
    }
}

void dfs(int n, int src){
    printf("DFS: \n");

    int visited[n];
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    int u, v;
    int stack[n];
    int top = -1;

    stack[++top] = src;
    visited[src] = 1;

    while (top != -1){
        u = stack[top--];

        for (v = 0; v < n; v++){
            if (graph[u][v] == 1 && visited[v] == 0){
                stack[++top] = v;
                visited[v] = 1;
            }
        }
        printf("%d\t", u);
    }
}

void bfs(int n, int src){
    printf("\nBFS: \n");

    int queue[n * n];
    int visited[n];
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    int front = 0, rear = -1;
    queue[++rear] = src;
    visited[src] = 1;

    while (front <= rear){
        int u = queue[front++];

        for (int v = 0; v < n; v++){
            if (graph[u][v] == 1 && visited[v] == 0){
                visited[v] = 1;
                queue[++rear] = v;
            }
        }
        printf("%d\t", u);
    }
}

int main(void){
    int n;
    printf("Enter no of vertices: ");
    scanf("%d", &n);

    int edges;
    printf("Enter no of edges: ");
    scanf("%d", &edges);

    int directed;
    printf("Directed/Undirected(1/0): ");
    scanf("%d", &directed);

    createGraph(n, edges, directed);

    int src;
    printf("Enter start node: ");
    scanf("%d", &src);
    dfs(n, src);
    bfs(n, src);
}