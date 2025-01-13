#include <iostream> // Include standard input/output library for cin and cout
#include <conio.h>  // Include for _getch() to hold the console window
using namespace std;

int main() {
    // Declare an array of size 100 to store elements
    int array[100], search, c, n;

    // Prompt user to enter the number of elements in the array
    cout << "Enter number of elements in array\n";
    cin >> n; // Input the size of the array

    // Prompt user to enter the elements of the array
    cout << "Enter integer(s)\n";
    for (c = 0; c < n; c++) {
        cin >> array[c]; // Read each integer and store it in the array
    }

    // Prompt user to enter the value to search in the array
    cout << "Enter a number to search\n";
    cin >> search;

    // Search for the entered value in the array
    for (c = 0; c < n; c++) {
        if (array[c] == search) { // Check if the current element matches the search value
            cout << search << " is present at location " << c + 1; // Print its position
            break; // Exit the loop once the value is found
        }
    }

    // If the loop completes without finding the value, print not found message
    if (c == n) {
        cout << search << " isn't present in the array.\n";
    }

    _getch(); // Wait for a key press before exiting (specific to Windows)
    return 0; // End of the program
}
