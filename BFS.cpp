#include<iostream>
using namespace std;

// Define the maximum number of vertices
#define MAX 5

// Define a struct to represent a vertex with a label and visited status
struct Vertex {
   char label;   // Label to identify the vertex (e.g., 'S', 'A', etc.)
   bool visited; // Boolean flag to check if the vertex has been visited during BFS
};

// Declare queue variables for BFS
int queue[MAX];  // Array to hold the queue
int rear = -1;   // Rear of the queue, initialized to -1 (empty queue)
int front = 0;   // Front of the queue, initialized to 0
int queueItemCount = 0; // To track the number of elements in the queue

// Declare graph variables
// Array to hold the list of vertices
struct Vertex* lstVertices[MAX];
// Adjacency matrix to represent the edges between vertices
int adjMatrix[MAX][MAX];
// Count the number of vertices in the graph
int vertexCount = 0;

// Queue functions

// Insert data into the queue (increase rear, add item to the queue)
void insert(int data) {
   queue[++rear] = data;   // Increment the rear and insert the data into the queue
   queueItemCount++;       // Increase the count of queue items
}

// Remove data from the front of the queue (decrease front)
int removeData() {
   queueItemCount--;  // Decrease the count of queue items
   return queue[front++];  // Return the data at the front of the queue and increment the front
}

// Check if the queue is empty (queueItemCount == 0)
bool isQueueEmpty() {
   return queueItemCount == 0;  // Return true if queue is empty, otherwise false
}

// Graph functions

// Add a vertex to the list of vertices
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));  // Allocate memory for the vertex
   vertex->label = label;  // Set the label of the vertex
   vertex->visited = false; // Initially, the vertex is not visited
   lstVertices[vertexCount++] = vertex;  // Add the vertex to the list and increment the vertex count
}

// Add an edge between two vertices (undirected graph)
void addEdge(int start, int end) {
   adjMatrix[start][end] = 1;  // Mark an edge from 'start' to 'end'
   adjMatrix[end][start] = 1;  // Since the graph is undirected, mark an edge from 'end' to 'start' as well
}

// Display a vertex by its index (print the label)
void displayVertex(int vertexIndex) {
   printf("%c ", lstVertices[vertexIndex]->label); // Print the label of the vertex
}

// Get the index of an adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;
   // Iterate through all vertices
   for(i = 0; i < vertexCount; i++) {
      // If there's an edge from 'vertexIndex' to 'i' and 'i' is unvisited
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i; // Return the index of the unvisited adjacent vertex
      }
   }
   return -1; // If no unvisited adjacent vertex is found, return -1
}

// Breadth First Search function (BFS)
void breadthFirstSearch() {
   int i;
   // Start BFS from the first vertex (index 0)
   lstVertices[0]->visited = true;  // Mark the first vertex as visited
   displayVertex(0);  // Display the first vertex
   insert(0);  // Insert the index of the first vertex into the queue

   int unvisitedVertex;
   // Continue BFS until the queue is empty
   while(!isQueueEmpty()) {
      // Remove the front vertex from the queue
      int tempVertex = removeData();
      
      // Get all unvisited adjacent vertices and add them to the queue
      while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
         lstVertices[unvisitedVertex]->visited = true;  // Mark the adjacent vertex as visited
         displayVertex(unvisitedVertex);  // Display the unvisited adjacent vertex
         insert(unvisitedVertex);  // Insert the unvisited adjacent vertex into the queue
      }
   }

   // Once the BFS is complete, reset the visited flag for all vertices
   for(i = 0; i < vertexCount; i++) {
      lstVertices[i]->visited = false; // Reset the visited flag
   }
}

// Main function
int main() {
   int i, j;

   // Initialize the adjacency matrix to 0 (no edges)
   for(i = 0; i < MAX; i++) {   
      for(j = 0; j < MAX; j++) {
         adjMatrix[i][j] = 0;  // Set all values in the adjacency matrix to 0
      }
   }

   // Add vertices to the graph with labels 'S', 'A', 'B', 'C', and 'D'
   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4

   // Add edges between vertices to form the graph
   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D

   // Print a message indicating that BFS will start
   printf("\nBreadth First Search: ");
   breadthFirstSearch();  // Perform BFS starting from vertex 'S'
   
   return 0;  // End of program
}
