//BFS Matrix
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n;

bool emptyQueue(int f, int r) {
    return f > r;
}

int deque(int queue[], int *f, int *r) {
    if (emptyQueue(*f, *r)) {
        printf("Queue underflow\n");
        return -1;
    }
    return queue[(*f)++];
}

void enque(int key, int queue[], int *f, int *r) {
    if (*f == -1) {
        *f = 0;
        *r = 0;
    } else {
        (*r)++;
    }
    queue[*r] = key;
}

void BFS(int matrix[n][n], int start) {
    int visited[n], queue[20];
    int front = -1, rear = -1;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    enque(start, queue, &front, &rear);
    visited[start] = 1;

    while (!emptyQueue(front, rear)) {
        int w = deque(queue, &front, &rear);
        if (w == -1) break;  // Handle empty queue case
        printf(" %d ", w);

        for (int i = 0; i < n; i++) {
            if (matrix[w][i] == 1 && !visited[i]) {
                enque(i, queue, &front, &rear);
                visited[i] = 1;
            }
        }
    }
}

void display(int matrix[n][n]) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void createMatrix(int matrix[n][n], int m) {
    int x, y;
    for (int i = 0; i < m; i++) {
        printf("Enter edge %d (two vertices): ", i + 1);
        scanf("%d %d", &x, &y);
        if (x < n && y < n) {
            matrix[x][y] = 1;
            matrix[y][x] = 1;
        } else {
            printf("Invalid edge. Please enter vertices between 0 and %d.\n", n - 1);
            i--;  // Repeat the iteration for invalid input
        }
    }
}

int main() {
    printf("No of vertices: ");
    scanf("%d", &n);
    int matrix[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;

    int m;
    printf("No. of edges: ");
    scanf("%d", &m);

    createMatrix(matrix, m);
    display(matrix);

    int start;
    printf("Enter start vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal starting from vertex %d:", start);
    BFS(matrix, start);
    printf("\n");

    return 0;
}

//BFS List
#include <stdio.h>
#include <stdlib.h>

struct LL {
    int data;
    struct LL *next;
};

struct Queue{
    int data;
    struct Queue *next;
};

int deque(struct Queue **front, struct Queue **rear){
  int data = (*front)->data;
  struct Queue *temp = (*front);
  (*front) = temp->next;
  free(temp);
  return data;
}

void enque(int key, struct Queue **front, struct Queue **rear){
  
  struct Queue *node = (struct Queue*)malloc(sizeof(struct Queue));
  node->data = key;
  node->next= NULL;
  if((*front)==NULL){
    (*front) = (*rear) = node;
    (*front)->next = (*rear)->next = NULL;
    return;
  }
  (*rear)->next = node;
  (*rear) = node;
  
}


void bfs(struct LL *list[10], int no){
  
  int start;
  struct LL *temp;
  struct Queue *front=NULL, *rear=NULL;
  int visited[no];
  
  //clearing vistited array:
  for(int i=0;i<no;i++){
    visited[i]=0;
  }
  
  printf("Enter start Node: ");
  scanf("%d", &start);
  enque(start, &front, &rear);
  visited[start] =1;
  
  while(front!=NULL){
    int w = deque(&front, &rear);
    printf(" %d ", w);
    
    temp = list[w];
    
    while(temp!=NULL){
      if(visited[temp->data]==0){
        enque(temp->data, &front, &rear);
        visited[temp->data] = 1;
      }
      temp=temp->next;
    }
    
    
  }
}

void createList(struct LL *list[], int no) {
    int edges;
    struct LL *t1, *t2;
    int v1, v2;

    printf("Enter No. of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter vertices: ");
        scanf("%d %d", &v1, &v2);

        // Add v2 to the list of v1
        t1 = (struct LL*)malloc(sizeof(struct LL));
        t1->data = v2;
        t1->next = NULL;
        if (list[v1] == NULL) {
            list[v1] = t1;
        } else {
            t2 = list[v1];
            while (t2->next != NULL) {
                t2 = t2->next;
            }
            t2->next = t1;
        }

        // Add v1 to the list of v2
        t1 = (struct LL*)malloc(sizeof(struct LL));
        t1->data = v1;
        t1->next = NULL;
        if (list[v2] == NULL) {
            list[v2] = t1;
        } else {
            t2 = list[v2];
            while (t2->next != NULL) {
                t2 = t2->next;
            }
            t2->next = t1;
        }
    }
}

void printList(struct LL *list[], int no) {
    struct LL *temp;
    for (int i = 0; i < no; i++) {
        printf("Adjacency list of vertex %d\n head ", i);
        temp = list[i];
        while (temp) {
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int no;
    printf("Enter no. of vertices: ");
    scanf("%d", &no);

    struct LL *list[10];
    for (int i = 0; i < no; i++) {
        list[i] = NULL;
    }

    createList(list, no);
    printList(list, no);
    
    bfs(list, no);

    return 0;
}

// DFS Matrix
#include <stdio.h>
#include <stdbool.h>

int n;

bool empty(int top) {
    return top < 0;
}

int pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[(*top)--];
}

void push(int key, int stack[], int *top, int maxSize) {
    if (*top >= maxSize - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++(*top)] = key;
}

void DFSMatrix(int adjMatrix[n][n], int maxSize) {
    int start, w;
    int stack[maxSize], top = -1;
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter start: ");
    scanf("%d", &start);

    push(start, stack, &top, maxSize);
    visited[start] = 1;
    printf(" %d ", start);

    while (!empty(top)) {
        w = pop(stack, &top);
        for (int i = 0; i < n; i++) {
            if (adjMatrix[w][i] == 1 && visited[i] == 0) {
                push(w, stack, &top, maxSize);
                push(i, stack, &top, maxSize);
                printf(" %d ", i);
                visited[i] = 1;
                break;  // restart the outer loop
            }
        }
    }
}

void display(int matrix[n][n]) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void createMatrix(int matrix[n][n], int m) {
    int x, y;
    for (int i = 0; i < m; i++) {
        printf("Enter edge %d (two vertices): ", i + 1);
        scanf("%d %d", &x, &y);
        if (x < n && y < n) {
            matrix[x][y] = 1;
            matrix[y][x] = 1;
        } else {
            printf("Invalid edge. Please enter vertices between 0 and %d.\n", n - 1);
            i--;  // Repeat the iteration for invalid input
        }
    }
}

int main() {
    printf("No of vertices: ");
    scanf("%d", &n);
    int matrix[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;

    int m;
    printf("No. of edges: ");
    scanf("%d", &m);

    createMatrix(matrix, m);
    display(matrix);

    int maxSize = 10;  // Maximum size of the stack
    DFSMatrix(matrix, maxSize);

    return 0;
}

//DFS List
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LL {
    int data;
    struct LL *next;
};

struct stack {
    int data;
    struct stack *next;
};

bool stackEmpty(struct stack *top) {
    return top == NULL;
}

int pop(struct stack **top) {
    if (*top == NULL) {
        printf("Stack underflow.\n");
        return -1;
    }

    struct stack *temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

void push(int key, struct stack **top) {
    struct stack *node = (struct stack*)malloc(sizeof(struct stack));
    node->data = key;
    node->next = *top;
    *top = node;
}

void DFS(struct LL *list[], int v) {
    int start, visited[10] = {0};
    struct stack *top = NULL;

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    push(start, &top);
    visited[start] = 1;

    while (!stackEmpty(top)) {
        int current = pop(&top);
        printf("%d ", current);

        struct LL *temp = list[current];

        while (temp != NULL) {
            if (!visited[temp->data]) {
                push(temp->data, &top);
                visited[temp->data] = 1;  // Mark the node as visited
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void createList(struct LL *list[], int v) {
    int edges;
    struct LL *node, *temp;
    int v1, v2;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);

        // Creating node for v1
        node = (struct LL*)malloc(sizeof(struct LL));
        node->data = v2;
        node->next = NULL;
        if (list[v1] == NULL) {
            list[v1] = node;
        } else {
            temp = list[v1];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }

        // Creating node for v2 (since the graph is undirected)
        node = (struct LL*)malloc(sizeof(struct LL));
        node->data = v1;
        node->next = NULL;
        if (list[v2] == NULL) {
            list[v2] = node;
        } else {
            temp = list[v2];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
}

void printList(struct LL *list[], int no) {
    struct LL *temp;
    for (int i = 0; i < no; i++) {
        printf("Adjacency list of vertex %d\n head ", i);
        temp = list[i];
        while (temp) {
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    struct LL *list[10];
    for (int i = 0; i < v; i++) {
        list[i] = NULL;
    }

    createList(list, v);
    
    printList(list, v);

    DFS(list, v);

    return 0;
}

// Adj list Prims
#include <stdio.h>
#include<stdlib.h>

struct LL{
  int data, distance;
  struct LL *next;
};

void prims(struct LL *list[], int v){
  int visited[10], parent[10], distance[10], ele;
  struct LL *temp;
  
  // Initializing all arrays:
  for(int i = 0; i < v; i++){
    visited[i] = 0;
    parent[i] = -1;
    distance[i] = 999;
  }
  
  // Enter element to be visited first
  scanf("%d", &ele);
  visited[ele] = 1;
  distance[ele] = 0;
  
  for(int i = 0; i < v - 1; i++){
    temp = list[ele];
    int small = 999;
    int m;
    while(temp != NULL){
      if(visited[temp->data] == 0 && distance[temp->data] > temp->distance){
        parent[temp->data] = ele;
        distance[temp->data] = temp->distance;
      }
      temp = temp->next;
    }
    
    for(int j = 0; j < v; j++){
      if(visited[j] == 0 && distance[j] < small){
        small = distance[j];
        m = j;
      }
    }
    visited[m] = 1;
    printf("%d-%d\n", parent[m], m);
    ele = m;
  }
}

void createList(struct LL *list[], int v){
  
  int edge, v1, v2, v3;
  struct LL *node, *temp;
  
  scanf("%d", &edge);
  
  for(int i=0;i<edge;i++){
    scanf("%d %d %d", &v1, &v2, &v3);
    
    // creating node 1
    node = (struct LL*)malloc(sizeof(struct LL));
    node->data = v2;
    node->distance = v3;
    node->next = NULL;
    if(list[v1] == NULL){
      list[v1]=node;
    }else{
      temp = list[v1];
      while(temp->next!=NULL){
        temp = temp->next;
      }
      temp->next = node;
    }
    
    // creating for node 2
    node = (struct LL*) malloc(sizeof(struct LL));
    node->data = v1;
    node->distance = v3;
    node->next = NULL;
    if(list[v2]==NULL){
      list[v2] = node;
    }else{
      temp = list[v2];
      while(temp->next!=NULL){
        temp = temp->next;
      }
      temp->next = node;
    }
    
  }
}

int main()
{
  int v;
  scanf("%d", &v);
  struct LL *list[10];
  for(int i=0;i<v;i++){
    list[i] = NULL;
  }
  
  createList(list, v);
  
  prims(list, v);
  
  
  return 0;  
}

// Adj Matrix Kruskals
#include <stdio.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

// Function to print the weighted graph
void printWeightedGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d =", i);
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                printf(" %d(%d) ->", j, graph[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to find the parent of a vertex
int findParent(int i, int parent[]) {
    while (i != parent[i]) {
        i = parent[i];
    }
    return i;
}

// Function to perform union operation
void unionVertices(int i, int j, int parent[]) {
    int a = findParent(i, parent);
    int b = findParent(j, parent);
    parent[b] = a;
}

// Function to perform Kruskal's algorithm
void kruskal(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int parent[MAX_VERTICES] = {0};
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int v = 2;
    while (v < n - 1) {
        int min = 999;
        int a, b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] < min) {
                    a = i;
                    b = j;
                    min = graph[i][j];
                }
            }
        }
        unionVertices(a, b, parent);
        printf("%d -> %d\n", a, b);
        v++;
    }
}

int main() {
    int vertices[MAX_VERTICES];
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0}};
    int n, m; // n = number of vertices, m = number of edges

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);

    printf("Enter the vertices of the graph (start: 0): ");
    for (int i = 0; i < n; i++) {
        vertices[i] = i;
    }

    printf("Enter the edges of the graph (v1 v2 weight):\n");
    for (int i = 0; i < m; i++) {
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);
        graph[v1][v2] = graph[v2][v1] = weight;
    }

    printf("The weighted graph is:\n");
    printWeightedGraph(graph, n);

    printf("The minimum spanning tree using Kruskal's algorithm is:\n");
    kruskal(graph, n);

    return 0;
}

// Adj List Kruskals
// Adj List Dijkstras
// Adj Matrix Dijkstras
