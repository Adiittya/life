#include <stdio.h>
#include <conio.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1, i, j;
void initialize(int numVertices) {
    for (i = 0; i < numVertices; i++) {
	visited[i] = 0;
	for (j = 0; j < numVertices; j++) {
	    graph[i][j] = 0;
	}}}
void addEdge(int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1;
}
void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
	printf("Queue is full.\n");
    } else {
	if (front == -1) {
	    front = 0;
	}
	rear++;
	queue[rear] = vertex;
    }}
int dequeue() {
    int vertex;
    if (front == -1) {

        printf("Queue is empty.\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }}
void breadthFirstSearch(int start, int numVertices) {
    int i, vertex;
    printf("Breadth-First Search starting from vertex %d:\n", start);
    enqueue(start);
    visited[start] = 1;
    while (front != -1) {
        vertex = dequeue();
        printf("%d ", vertex);
        for (i = 0; i < numVertices; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }}}}
int main() {
    int numVertices, numEdges, i, startVertex, endVertex;
    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    initialize(numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (format: start_vertex end_vertex):\n");
    for (i = 0; i < numEdges; i++) {
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(startVertex, endVertex);
    }
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    breadthFirstSearch(startVertex, numVertices);
    getch();
    return 0;
}

