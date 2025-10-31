#include <iostream>
using namespace std;
// Structure definition for each node in the linked list
struct ListNode {
    int val; // stores the value of the node
    ListNode* next; // pointer to the next node
};
// Function to find the middle node of the linked list
ListNode* middleNode(ListNode* head) {
    // 'slow' moves 1 step at a time, 'fast' moves 2 steps at a time
    ListNode* slow = head;
    ListNode* fast = head;

 // Loop runs until 'fast' reaches the end of the list
    while (fast != NULL && fast->next != NULL) {
         // Move 'slow' by 1 step
        slow = slow->next;
        // Move 'fast' by 2 steps
        fast = fast->next->next;
    }
 // When loop ends, 'slow' will be at the middle node
    return slow;
}

int main() {
    int n;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;
 // Check if number of nodes is invalid
    if (n <= 0) {
        cout << "Invalid number of nodes!" << endl;
        return 0;
    }

    // Create array of nodes (max 100 as per problem constraint)
    ListNode nodes[100];

    cout << "Enter " << n << " values for the linked list: ";
    // Loop to take input and link nodes together
    for (int i = 0; i < n; i = i + 1) {
        cin >> nodes[i].val;
        // If it's the last node, point 'next' to NULL
        if (i == n - 1)
            nodes[i].next = NULL;
            // Otherwise, link to the next node

        else
            nodes[i].next = &nodes[i + 1];
    }
// Set head pointer to the first node
    ListNode* head = &nodes[0];
    // Call function to find the middle node
    ListNode* mid = middleNode(head);

    cout << "The list from the middle node to the end is: ";
      // Loop to print values starting from middle till the end
    while (mid != NULL) {
        cout << mid->val;
        // Add space between numbers (but not after last)
        if (mid->next != NULL)
            cout << " ";
            // Move to the next node
        mid = mid->next;
    }
    cout << endl;

    return 0;
}
