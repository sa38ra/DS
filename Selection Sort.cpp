#include <iostream>
using namespace std;

// Original selectionSort function (unchanged)
void selectionSort(int arr[], int size) 
{ 
    int i, j; 
    // Outer loop: Iterates through each element in the array.
    for (i = 0; i < size; i++) 
    { 
        // Inner loop: Starts from the current position of the outer loop (i) 
        // and iterates through the remaining elements to find the smallest one.
        for (j = i; j < size; j++) 
        { 
            // If the current element at index i is greater than the element at index j,
            // we attempt to "swap" the two elements to move the smaller element closer to the start.
            if (arr[i] > arr[j]) 
            { 
                // This block is meant to swap arr[i] and arr[j], but it mistakenly shifts elements.
                int temp = arr[j];       // Store the element at index j in a temporary variable.
                arr[j] = arr[j + 1];     // Shift the element at index j + 1 to index j.
                arr[j + 1] = temp;       // Place the original element from index j at index j + 1.
            } 
        } 
    } 
}


// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int size;

    // Input the size of the array
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Display the original array
    cout << "Original array: ";
    displayArray(arr, size);

    // Attempt to perform selection sort
    selectionSort(arr, size);

    // Display the "sorted" array
    cout << "Array after selectionSort function: ";
    displayArray(arr, size);

    return 0;
}
