#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Node{
    int vertex;
    struct Node* next;
} Node;

Node* graph[MAX_VERTICES];
int visited[MAX_VERTICES];
int n;

Node* createNode(int v){
    Node* n = malloc(sizeof(Node));

    n->vertex = v;
    n->next = NULL;

    return n;
}

void addEdge(int src, int dest){
    Node* d = createNode(dest);

    d->next = graph[src];
    graph[src] = d;

    // If Undirected

    Node* s = createNode(src);
    s->next = graph[dest];
    graph[dest] = s;
}

void init(){
    for (int i = 0; i < n; i++){
        visited[i] = 0;
        graph[i] = NULL;
    }
}

void dfs(int v){
    //Node* w;
    visited[v] = 1;
    printf("%5d", v);

    for (Node* w = graph[v]; w != NULL; w = w->next){
        if (!visited[w->vertex]){
            dfs(w->vertex);
        }
    }
}

void bfs(int v){
    printf("\nBFS: \n");

    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    int queue[n * n];
    int front = 0; 
    int rear = -1;

    visited[v] = 1;
    queue[++rear] = v;

    while (front <= rear){
        int w = queue[front++];

        for (Node* k = graph[w]; k; k = k->next){
            if (!visited[k->vertex]){
                queue[++rear] = k->vertex;
                visited[k->vertex] = 1;
            }
        }
        printf("%5d", w);
    }
}

int main(void){
    printf("Enter no of vertices: ");
    scanf("%d", &n);
    init();

    printf("Enter no of edges: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int u, v;
        printf("Enter edges: (source - destination): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Enter startEdge for DFS: ");
    scanf("%d", &start);

    dfs(start);
    bfs(start);
}