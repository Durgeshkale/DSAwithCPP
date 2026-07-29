/*
Leetcode 707. Design Linked List

Question:
Design your implementation of the linked list.

Implement the MyLinkedList class:

1. get(index)
   - Get the value of the index-th node in the linked list.
   - If the index is invalid, return -1.

2. addAtHead(val)
   - Add a node of value val before the first element.

3. addAtTail(val)
   - Append a node of value val to the end.

4. addAtIndex(index, val)
   - Add a node before the index-th node.
   - If index == length, append at the end.
   - If index > length, do nothing.

5. deleteAtIndex(index)
   - Delete the index-th node if the index is valid.

Example:

MyLinkedList linkedList;

linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);

Linked List:
1 -> 2 -> 3

linkedList.get(1)
Output: 2

linkedList.deleteAtIndex(1);

Linked List:
1 -> 3

linkedList.get(1)
Output: 3

Intuition:

We maintain a head pointer and keep track of the current
size of the linked list.

For every operation:

• Traverse to the required position.
• Insert/Delete the node.
• Update the size whenever a node is inserted or deleted.

Maintaining the size allows us to quickly validate indices.

Approach:

1. Store the head pointer and current size.
2. For get(), traverse to the required index.
3. For addAtHead(), insert before the current head.
4. For addAtTail(), traverse to the last node and append.
5. For addAtIndex(), traverse to index-1 and insert.
6. For deleteAtIndex(), traverse to index-1 and remove the node.
7. Update the size after every insertion/deletion.

Time Complexity:

get(index)         : O(n)

addAtHead(val)     : O(1)

addAtTail(val)     : O(n)

addAtIndex(index)  : O(n)

deleteAtIndex()    : O(n)

Space Complexity: O(n)

The linked list stores n nodes.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val1) {
        val = val1;
        next = nullptr;
    }
};

class MyLinkedList {

private:

    Node* head;
    int size;

public:

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    // return value at given index
    int get(int index) {

        if(index < 0 || index >= size) {
            return -1;
        }

        Node* temp = head;

        while(index--) {
            temp = temp->next;
        }

        return temp->val;
    }

    // insert at beginning
    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    // insert at end
    void addAtTail(int val) {

        Node* newNode = new Node(val);

        if(head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        Node* tail = head;

        while(tail->next != nullptr) {
            tail = tail->next;
        }

        tail->next = newNode;

        size++;
    }

    // insert before given index
    void addAtIndex(int index, int val) {

        if(index < 0 || index > size) {
            return;
        }

        if(index == 0) {
            addAtHead(val);
            return;
        }

        if(index == size) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);

        Node* temp = head;

        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }

    // delete node at given index
    void deleteAtIndex(int index) {

        if(index < 0 || index >= size) {
            return;
        }

        if(index == 0) {

            Node* del = head;

            head = head->next;

            delete del;

            size--;

            return;
        }

        Node* temp = head;

        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* del = temp->next;

        temp->next = del->next;

        delete del;

        size--;
    }

    // print linked list
    void display() {

        Node* temp = head;

        while(temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    MyLinkedList list;

    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);

    cout << "Linked List: ";
    list.display();

    cout << "Value at index 1: ";
    cout << list.get(1) << endl;

    list.deleteAtIndex(1);

    cout << "After deleting index 1: ";
    list.display();

    cout << "Value at index 1: ";
    cout << list.get(1) << endl;

    return 0;
}