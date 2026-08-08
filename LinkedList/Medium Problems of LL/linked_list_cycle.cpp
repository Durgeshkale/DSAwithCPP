/*
Leetcode 141. Linked List Cycle

Question:
Given the head of a linked list, determine whether the linked list
contains a cycle.

A cycle exists if a node can be reached again by continuously
following the next pointer.

Example 1:
Input:
3 -> 2 -> 0 -> -4
     ^           |
     |___________|

Output:
true

Example 2:
Input:
1 -> 2
     ^  |
     |__|

Output:
true

Example 3:
Input:
1 -> 2 -> NULL

Output:
false


Intuition:

Use the Tortoise and Hare algorithm.

Take two pointers:
- slow moves one step at a time.
- fast moves two steps at a time.

If a cycle exists, fast will eventually catch slow inside the cycle.

If there is no cycle, fast will reach NULL.

Approach:
1. Initialize slow and fast at head.
2. Move slow by one step and fast by two steps.
3. If slow == fast, a cycle exists.
4. If fast reaches NULL, there is no cycle.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;


class ListNode {
public:

    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};


class Solution {
public:

    bool hasCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {

            // Slow moves one step
            slow = slow->next;

            // Fast moves two steps
            fast = fast->next->next;

            // If both pointers meet, cycle exists
            if(slow == fast) {
                return true;
            }
        }

        // Fast reached NULL, so there is no cycle
        return false;
    }
};


/*
Create linked list.
*/
ListNode* createList(vector<int>& arr) {

    if(arr.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++) {

        temp->next = new ListNode(arr[i]);
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


    ListNode* head = createList(arr);


    /*
    Enter the index where the last node should connect.

    Example:
    0 -> 1 -> 2 -> 3
              ^    |
              |____|

    Enter 2 to create a cycle.

    Enter -1 for no cycle.
    */

    int cycleIndex;

    cout << "Enter cycle index (-1 for no cycle): ";
    cin >> cycleIndex;


    if(cycleIndex >= 0 && cycleIndex < n) {

        ListNode* cycleNode = head;

        for(int i = 0; i < cycleIndex; i++) {
            cycleNode = cycleNode->next;
        }

        ListNode* tail = head;

        while(tail->next != nullptr) {
            tail = tail->next;
        }

        tail->next = cycleNode;
    }


    Solution solution;

    if(solution.hasCycle(head)) {
        cout << "Cycle detected" << endl;
    }
    else {
        cout << "No cycle" << endl;
    }


    return 0;
}