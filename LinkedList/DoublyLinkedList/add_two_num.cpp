/*
Leetcode 2. Add Two Numbers

Question:
You are given two non-empty linked lists representing two non-negative integers.

The digits are stored in reverse order, and each node contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zeros,
except the number 0 itself.

Example 1:
Input:
l1 = [2,4,3]
l2 = [5,6,4]

Output:
[7,0,8]

Explanation:
342 + 465 = 807

Example 2:
Input:
l1 = [0]
l2 = [0]

Output:
[0]

Example 3:
Input:
l1 = [9,9,9,9,9,9,9]
l2 = [9,9,9,9]

Output:
[8,9,9,9,0,0,0,1]

Intuition:

Since both numbers are stored in reverse order,
we can add them exactly like we do by hand.

Traverse both linked lists simultaneously,
add the corresponding digits along with the carry,
create a new node for the current digit,
and move to the next nodes.

If one list becomes shorter, treat its value as 0.

Finally, if a carry is left after the traversal,
add one last node containing the carry.

Approach:

1. Create a dummy head node for the answer list.
2. Traverse both linked lists until both become NULL.
3. Compute:
      sum = carry + value from l1 + value from l2.
4. Create a new node with digit = sum % 10.
5. Update carry = sum / 10.
6. Move to the next nodes in both lists.
7. If carry still exists after traversal,
   add one final node.
8. Return dummyHead->next.

Time Complexity: O(max(n, m))

We traverse both linked lists only once.

Space Complexity: O(max(n, m))

The output linked list stores the answer.
(Extra auxiliary space is O(1).)
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* dummyHead = new ListNode(-1);

    ListNode* t1 = l1;
    ListNode* t2 = l2;
    ListNode* curr = dummyHead;

    int carry = 0;

    while(t1 != nullptr || t2 != nullptr) {

        int sum = carry;

        if(t1) sum += t1->val;
        if(t2) sum += t2->val;

        ListNode* newNode = new ListNode(sum % 10);

        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }

    if(carry) {
        curr->next = new ListNode(carry);
    }

    return dummyHead->next;
}

// Function to create linked list
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

// Function to print linked list
void printList(ListNode* head) {

    while(head != nullptr) {
        cout << head->val;

        if(head->next) cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    int n1, n2;

    cout << "Enter number of nodes in first linked list: ";
    cin >> n1;

    vector<int> arr1(n1);

    cout << "Enter elements of first linked list: ";
    for(int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter number of nodes in second linked list: ";
    cin >> n2;

    vector<int> arr2(n2);

    cout << "Enter elements of second linked list: ";
    for(int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);

    ListNode* ans = addTwoNumbers(l1, l2);

    cout << "Sum Linked List: ";
    printList(ans);

    return 0;
}