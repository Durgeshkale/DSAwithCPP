/*
Leetcode 21. Merge Two Sorted Lists

Question:
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted linked list and return its head.

The merged list should be made by splicing together the nodes of the first
two lists.

Example 1:
Input:
list1 = [1,2,4]
list2 = [1,3,4]

Output:
[1,1,2,3,4,4]

Example 2:
Input:
list1 = []
list2 = []

Output:
[]

Example 3:
Input:
list1 = []
list2 = [0]

Output:
[0]

Intuition:

Since both linked lists are already sorted,
we compare the current nodes of both lists.

The smaller value is added to the answer list,
and its pointer is moved forward.

Once one list becomes empty,
append all remaining nodes of the other list.

Approach:

1. Create a dummy head for the merged list.
2. Maintain pointers for both linked lists.
3. Compare current nodes of both lists.
4. Insert the smaller value into the merged list.
5. Move the corresponding pointer forward.
6. After one list ends, append the remaining nodes of the other list.
7. Return dummyHead->next.

Time Complexity: O(n + m)

Each node from both linked lists is visited exactly once.

Space Complexity: O(n + m)

A new linked list is created containing all nodes.
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

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* dummyHead = new ListNode(-1);

    ListNode* t1 = list1;
    ListNode* t2 = list2;
    ListNode* curr = dummyHead;

    while(t1 != nullptr && t2 != nullptr) {

        // add smaller element to merged list
        if(t1->val < t2->val) {
            curr->next = new ListNode(t1->val);
            curr = curr->next;
            t1 = t1->next;
        }
        else {
            curr->next = new ListNode(t2->val);
            curr = curr->next;
            t2 = t2->next;
        }
    }

    // add remaining nodes of first list
    while(t1 != nullptr) {
        curr->next = new ListNode(t1->val);
        curr = curr->next;
        t1 = t1->next;
    }

    // add remaining nodes of second list
    while(t2 != nullptr) {
        curr->next = new ListNode(t2->val);
        curr = curr->next;
        t2 = t2->next;
    }

    return dummyHead->next;
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

    int n1, n2;

    cout << "Enter size of first linked list: ";
    cin >> n1;

    vector<int> arr1(n1);

    cout << "Enter elements of first sorted linked list: ";
    for(int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second linked list: ";
    cin >> n2;

    vector<int> arr2(n2);

    cout << "Enter elements of second sorted linked list: ";
    for(int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    ListNode* list1 = createList(arr1);
    ListNode* list2 = createList(arr2);

    ListNode* ans = mergeTwoLists(list1, list2);

    cout << "Merged Linked List: ";
    printList(ans);

    return 0;
}