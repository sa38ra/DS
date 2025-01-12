#include <iostream>
using namespace std;

// Define the structure for the binary tree node
struct node {
   int value;           // Stores the value of the node
   struct node *leftChild, *rightChild;  // Pointers to left and right child nodes
};

// Function to create a new node with a given value
struct node *newNode(int value){
   struct node *temp = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
   temp->value = value;     // Set the node value
   temp->leftChild = temp->rightChild = NULL;  // Initialize left and right children as NULL
   return temp;  // Return the new node
}

// Function to perform in-order traversal (LNR) - Left, Node, Right
void printInOrder(struct node* root_node){
   if(root_node != NULL) {  // If the current node is not NULL
      printInOrder(root_node->leftChild);  // Recurse on the left child
      cout << "\n" << root_node->value;  // Print the value of the node
      printInOrder(root_node->rightChild);  // Recurse on the right child
   }
}

// Function to perform pre-order traversal (NLR) - Node, Left, Right
void printPreOrder(struct node* root_node){
   if(root_node != NULL) {  // If the current node is not NULL
      cout << "\n" << root_node->value;  // Print the value of the node
      printPreOrder(root_node->leftChild);  // Recurse on the left child
      printPreOrder(root_node->rightChild);  // Recurse on the right child
   }
}

// Function to perform post-order traversal (RLN) - Right, Left, Node
void printPostOrder(struct node* root_node){
   if(root_node != NULL) {  // If the current node is not NULL
      printPostOrder(root_node->rightChild);  // Recurse on the right child
      printPostOrder(root_node->leftChild);  // Recurse on the left child
      cout << "\n" << root_node->value;  // Print the value of the node
   }
}

// Function to perform in-order traversal (LNR) - Left, Node, Right
void traverseLNR(struct node* root_node) {
   if (root_node != NULL) {
      traverseLNR(root_node->leftChild);  // Visit the left subtree
      cout << root_node->value << " ";  // Print the node
      traverseLNR(root_node->rightChild);  // Visit the right subtree
   }
}

// Function to perform reverse in-order traversal (RLN) - Right, Left, Node
void traverseRLN(struct node* root_node) {
   if (root_node != NULL) {
      traverseRLN(root_node->rightChild);  // Visit the right subtree
      cout << root_node->value << " ";  // Print the node
      traverseRLN(root_node->leftChild);  // Visit the left subtree
   }
}

// Function to perform pre-order traversal (NLR) - Node, Left, Right
void traverseNLR(struct node* root_node) {
   if (root_node != NULL) {
      cout << root_node->value << " ";  // Print the node
      traverseNLR(root_node->leftChild);  // Visit the left subtree
      traverseNLR(root_node->rightChild);  // Visit the right subtree
   }
}

// Function to insert a node with a given value into the binary search tree
struct node* insert_node(struct node* node, int value){
   if(node == NULL) {  // If the tree is empty or we reached a NULL node, insert the new node here
      return newNode(value);
   }
   // If the value is less than the current node's value, go to the left child
   if(value < node->value) {
      node->leftChild = insert_node(node->leftChild, value);
   } 
   // If the value is greater than the current node's value, go to the right child
   else if(value > node->value) {
      node->rightChild = insert_node(node->rightChild, value);
   }
   // If the value is equal to the current node's value, do nothing (no duplicates in BST)
   return node;  // Return the (unchanged) node pointer
}

// Function to find the minimum value in the binary search tree
struct node* findMin(struct node* node) {
   if (node == NULL) {
      return NULL;
   }
   while (node->leftChild != NULL) {  // Go left until the minimum node is found
      node = node->leftChild;
   }
   return node;  // Return the minimum node
}

// Function to delete a node from the binary search tree
struct node* delete_node(struct node* root, int value) {
   if (root == NULL) {
      return NULL;  // If the root is NULL, return NULL (node to be deleted is not found)
   }

   // If the value is smaller, recursively go to the left subtree
   if (value < root->value) {
      root->leftChild = delete_node(root->leftChild, value);
   }
   // If the value is larger, recursively go to the right subtree
   else if (value > root->value) {
      root->rightChild = delete_node(root->rightChild, value);
   }
   // If value is same as root node's value, then this is the node to be deleted
   else {
      // Node with only one child or no child
      if (root->leftChild == NULL) {
         struct node* temp = root->rightChild;
         free(root);  // Free memory
         return temp;  // Return the right child or NULL
      }
      else if (root->rightChild == NULL) {
         struct node* temp = root->leftChild;
         free(root);  // Free memory
         return temp;  // Return the left child or NULL
      }

      // Node with two children: Get the inorder successor (smallest in the right subtree)
      struct node* temp = findMin(root->rightChild);  // Find minimum in right subtree
      root->value = temp->value;  // Copy the inorder successor's value to this node

      // Delete the inorder successor
      root->rightChild = delete_node(root->rightChild, temp->value);
   }
   return root;  // Return the (unchanged) root node
}

int main(){
   cout << "Binary Tree \n\n";
   struct node *root_node = NULL;

   // Insert nodes into the binary search tree
   root_node = insert_node(root_node, 10);
   insert_node(root_node , 10);
   insert_node(root_node , 30);
   insert_node(root_node , 25);
   insert_node(root_node , 36);
   insert_node(root_node , 56);
   insert_node(root_node , 6);

   // Print in-order (LNR)
   cout << "In-order Traversal (LNR): ";
   printInOrder(root_node);
   
   // Print pre-order (NLR)
   cout << "\nPre-order Traversal (NLR): ";
   printPreOrder(root_node);

   // Print post-order (RLN)
   cout << "\nPost-order Traversal (RLN): ";
   printPostOrder(root_node);

   // Print in-order traversal using traverseLNR
   cout << "\nIn-order Traversal (LNR) using traverseLNR: ";
   traverseLNR(root_node);
   
   // Print reverse in-order traversal (RLN) using traverseRLN
   cout << "\nReverse In-order Traversal (RLN) using traverseRLN: ";
   traverseRLN(root_node);
   
   // Print pre-order traversal (NLR) using traverseNLR
   cout << "\nPre-order Traversal (NLR) using traverseNLR: ";
   traverseNLR(root_node);

   // Deleting a node and then printing the tree again
   root_node = delete_node(root_node, 36);
   cout << "\nAfter Deleting 36, In-order Traversal: ";
   printInOrder(root_node);

   // Find minimum value
   struct node* minNode = findMin(root_node);
   if (minNode != NULL) {
      cout << "\nMinimum value in the tree is: " << minNode->value << endl;
   }

   return 0;  // End of the program
}
