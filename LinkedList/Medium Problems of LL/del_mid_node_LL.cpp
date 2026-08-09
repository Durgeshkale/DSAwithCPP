/*
Leetcode 2095. Delete the Middle Node of a Linked List

Question:
Given the head of a singly linked list, delete the middle node
and return the head of the modified linked list.

For an even-sized list, the second middle node is considered
the middle node.

Example 1:
Input:
[1, 3, 4, 7, 1, 2, 6]

Output:
[1, 3, 4, 1, 2, 6]

Explanation:
The middle node is 7, so it is deleted.

Example 2:
Input:
[1, 2, 3, 4]

Output:
[1, 2, 4]

Explanation:
The middle node is 3, so it is deleted.

Example 3:
Input:
[2, 1]

Output:
[2]


Intuition:

We need to find the middle node first.

Using the Tortoise and Hare approach:
- slow moves one step.
- fast moves two steps.

Here, we initially move fast two steps before starting
the loop. This makes slow stop at the node just before
the middle node.

Then we can directly delete slow->next.

Approach:
1. Handle the single-node case.
2. Move fast two steps initially.
3. Move slow one step and fast two steps.
4. slow will point to the node before the middle.
5. Delete slow->next.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = nullptr;
    }

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {

        // If there is only one node, return NULL
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Move fast ahead by two steps
        fast = fast->next->next;

        // Find the node just before the middle
        while (fast != nullptr && fast->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        ListNode *delNode = slow->next;

        slow->next = delNode->next;

        delete delNode;

        return head;
    }
};

/*
Create linked list.
*/
ListNode *createList(vector<int> &arr)
{

    if (arr.empty())
    {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {

        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

/*
Print linked list.
*/
void printList(ListNode *head)
{

    while (head != nullptr)
    {

        cout << head->val;

        if (head->next != nullptr)
        {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main()
{

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter list elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ListNode *head = createList(arr);

    Solution solution;

    head = solution.deleteMiddle(head);

    cout << "Linked list after deleting middle node: ";

    printList(head);

    return 0;
}