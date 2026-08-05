/*
Leetcode 234. Palindrome Linked List

Question:
Given the head of a singly linked list, return true if it is
a palindrome, otherwise return false.

Example 1:
Input:
head = [1,2,2,1]

Output:
true

Example 2:
Input:
head = [1,2]

Output:
false

Intuition:

A palindrome reads the same from both directions.

Using the Slow & Fast Pointer technique, we find the middle of the
linked list. Then we reverse the second half and compare it with the
first half node by node.

Finally, we restore the original linked list by reversing the second
half again.

Approach:

1. Find the middle of the linked list using slow and fast pointers.
2. Reverse the second half of the linked list.
3. Compare both halves node by node.
4. If any values differ, restore the list and return false.
5. Reverse the second half again to restore the original list.
6. Return true.

Time Complexity: O(n)

Finding the middle, reversing, comparing, and restoring each take linear time.

Space Complexity: O(n)

Recursive reverse uses recursion stack.
(With iterative reverse, it becomes O(1).)
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};

// Recursive reverse function
ListNode* reverse(ListNode* &head) {

    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* newHead = reverse(head->next);

    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

// Check if linked list is palindrome
bool isPalindrome(ListNode* head) {

    if(head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Find middle of linked list
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* newHead = reverse(slow->next);

    ListNode* first = head;
    ListNode* second = newHead;

    // Compare both halves
    while(second != nullptr) {

        if(first->val != second->val) {

            // Restore original list
            reverse(newHead);
            return false;
        }

        first = first->next;
        second = second->next;
    }

    // Restore original list
    reverse(newHead);

    return true;
}

// Create linked list
ListNode* createList(vector<int>& arr) {

    if(arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print linked list
void printList(ListNode* head) {

    while(head != nullptr) {
        cout << head->val;

        if(head->next) cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter linked list elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ListNode* head = createList(arr);

    if(isPalindrome(head))
        cout << "Linked List is a Palindrome";
    else
        cout << "Linked List is NOT a Palindrome";

    return 0;
}