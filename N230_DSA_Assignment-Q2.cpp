#include <iostream>
using namespace std;

// Function to concatenate the array with itself
void getConcatenation(int nums[], int n, int ans[]) {
    // Loop to copy elements of nums[] into ans[] twice
    for (int i = 0; i < n; i = i + 1) {
        ans[i] = nums[i];       // first half
        ans[i + n] = nums[i];   // second half
    }
}

int main() {
    int n;

    // Ask user for size of the array
    cout << "Enter number of elements in array: ";
    cin >> n;

    // Check for invalid input
    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    int nums[1000]; // input array (max limit 1000 as per constraints)
    int ans[2000];  // output array (2 * n elements)

    // Ask user to input array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i = i + 1) {
        cin >> nums[i];
    }

    // Call the function to create concatenated array
    getConcatenation(nums, n, ans);

    // Print the final concatenated array
    cout << "Concatenated array: ";
    for (int i = 0; i < 2 * n; i = i + 1) {
        cout << ans[i];
        if (i != 2 * n - 1)
            cout << " ";
    }

    cout << endl;
    return 0;
}
