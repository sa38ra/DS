#include <iostream>
using namespace std;

// Define the maximum number of vertices
#define MAX 5

// Define a struct to represent a vertex with a label and visited status
struct Vertex {
   char label;   // Label to identify the vertex (e.g., 'A', 'B', etc.)
   bool visited; // Boolean flag to check if the vertex has been visited during DFS
};

// Declare a stack array for DFS operations
int stack[MAX]; 
int top = -1; // Initialize the top of the stack to -1, indicating an empty stack

// Declare the graph variables
// Array to hold the list of vertices
struct Vertex* lstVertices[MAX];
// Adjacency matrix to represent the edges between vertices
int adjMatrix[MAX][MAX];
// Count the number of vertices in the graph
int vertexCount = 0;

// Stack functions

// Push an item onto the stack (increase top, add item to stack)
void push(int item) { 
   stack[++top] = item; // Increment the top index and insert the item
} 

// Pop an item from the stack (decrease top, return top item)
int pop() { 
   return stack[top--]; // Return the item at top and decrement top
} 

// Peek to see the item at the top of the stack without removing it
int peek() {
   return stack[top]; // Return the item at top without removing it
}

// Check if the stack is empty (top is -1)
bool isStackEmpty() {
   return top == -1; // If top is -1, the stack is empty
}

// Graph functions

// Add a vertex to the list of vertices
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex)); // Allocate memory for the vertex
   vertex->label = label;  // Set the label of the vertex
   vertex->visited = false; // Initially, the vertex is not visited
   lstVertices[vertexCount++] = vertex; // Add the vertex to the list and increment the vertex count
}

// Add an edge between two vertices (undirected graph)
void addEdge(int start, int end) {
   adjMatrix[start][end] = 1; // Mark an edge from 'start' to 'end'
   adjMatrix[end][start] = 1; // Since the graph is undirected, mark an edge from 'end' to 'start' as well
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

// Depth First Search function (DFS)
void depthFirstSearch() {
   int i;
   // Start DFS from the first vertex (index 0)
   lstVertices[0]->visited = true;  // Mark the first vertex as visited
   displayVertex(0);  // Display the first vertex
   push(0);  // Push the index of the first vertex onto the stack

   // Continue DFS until the stack is empty
   while(!isStackEmpty()) {
      // Get the unvisited adjacent vertex of the vertex at the top of the stack
      int unvisitedVertex = getAdjUnvisitedVertex(peek());
      
      // If no adjacent vertex is found
      if(unvisitedVertex == -1) {
         pop();  // Pop the stack to backtrack to the previous vertex
      } else {
         // If an unvisited adjacent vertex is found
         lstVertices[unvisitedVertex]->visited = true; // Mark it as visited
         displayVertex(unvisitedVertex);  // Display the unvisited vertex
         push(unvisitedVertex); // Push the unvisited vertex onto the stack
      }
   }

   // Once the DFS is complete, reset the visited flag for all vertices
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

   // Print a message indicating that DFS will start
   printf("Depth First Search: ");
   depthFirstSearch();  // Perform DFS starting from vertex 'S'
   
   return 0;  // End of program
}
