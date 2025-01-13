#include <iostream> // Include standard input/output library for cin and cout
#include <conio.h>  // Include for _getch() to hold the console window
using namespace std;

int main() {
    int c, first, last, middle, n, search, array[100]; // Variable declarations

    // Prompt the user to enter the number of elements in the array
    cout << "Enter number of elements\n";
    cin >> n; // Input number of elements

    // Prompt the user to input the elements of the array
    cout << "Enter numbers \n";
    for (c = 0; c < n; c++) {
        cin >> array[c]; // Input each element
    }

    // Prompt the user to input the value to be searched
    cout << "Enter value to find: \n";
    cin >> search;

    // Initialize the indices for the binary search
    first = 0;          // Start of the array
    last = n - 1;       // End of the array
    middle = (first + last) / 2; // Middle index

    // Binary search loop
    while (first <= last) {
        if (array[middle] < search) {
            // If the middle element is smaller, search the right half
            first = middle + 1;
        } else if (array[middle] == search) {
            // If the middle element matches the search value
            cout << search << " found at location " << middle + 1 << endl; // Output position
            break; // Exit the loop
        } else {
            // If the middle element is greater, search the left half
            last = middle - 1;
        }
        // Update the middle index for the next iteration
        middle = (first + last) / 2;
    }

    // If the search value is not found
    if (first > last) {
        cout << "Not found! " << search << " isn't present in the list.\n";
    }

    _getch(); // Wait for a key press before exiting (specific to Windows)
    return 0; // End of program
}
