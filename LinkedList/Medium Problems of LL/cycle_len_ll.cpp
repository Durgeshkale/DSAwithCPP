/*
Cycle Length in a Linked List

Question:
Given the head of a linked list, find the length of the cycle.
If there is no cycle, return 0.

Example 1:
Input:
1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

Output:
3

Explanation:
The cycle is:
3 -> 4 -> 5 -> 3

So, cycle length = 3.

Example 2:
Input:
1 -> 2 -> 3 -> NULL

Output:
0


Intuition:

First detect whether a cycle exists using the Tortoise and Hare
algorithm.

If slow and fast meet, they are inside the cycle.

Now keep one pointer fixed and move the other pointer until it
comes back to the same node. The number of steps taken is the
length of the cycle.

Approach:
1. Use slow and fast pointers to detect a cycle.
2. When they meet, call the length function.
3. Keep one pointer fixed and move the other until they meet again.
4. Count the number of moves.
5. If no cycle exists, return 0.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;


class Node {
public:

    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


class Solution {
public:

    // Finds the length of the cycle
    int length(Node* temp1, Node* temp2) {

        int cnt = 1;

        temp2 = temp2->next;

        while(temp1 != temp2) {

            cnt++;
            temp2 = temp2->next;
        }

        return cnt;
    }


    int lengthOfLoop(Node* head) {

        Node* slow = head;
        Node* fast = head;

        // Detect cycle using slow and fast pointers
        while(fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if(slow == fast) {
                return length(slow, fast);
            }
        }

        // No cycle
        return 0;
    }
};


/*
Create linked list.
*/
Node* createList(vector<int>& arr) {

    if(arr.empty()) {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++) {

        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}


int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter list elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    Node* head = createList(arr);


    /*
    Enter the index where the last node should connect.

    Example:

    1 -> 2 -> 3 -> 4 -> 5
              ^         |
              |_________|

    Enter 2 to create a cycle starting at node 3.

    Enter -1 for no cycle.
    */

    int cycleIndex;

    cout << "Enter cycle index (-1 for no cycle): ";
    cin >> cycleIndex;


    if(cycleIndex >= 0 && cycleIndex < n) {

        Node* cycleNode = head;

        // Move to the node where cycle should begin
        for(int i = 0; i < cycleIndex; i++) {
            cycleNode = cycleNode->next;
        }

        // Find the last node
        Node* tail = head;

        while(tail->next != nullptr) {
            tail = tail->next;
        }

        // Create the cycle
        tail->next = cycleNode;
    }


    Solution solution;

    int ans = solution.lengthOfLoop(head);

    cout << "Length of cycle = " << ans << endl;


    return 0;
}