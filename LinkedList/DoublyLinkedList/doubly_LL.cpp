#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data1, Node *next1, Node *prev1) {
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        prev = NULL;
        next = NULL;
    }
};

// Print Doubly Linked List
void printDLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

//convert array to a doubly linkedlist
Node* convertArr2LL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for(int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Deletion in Doubly LL
//delete head of the dll
Node* deleteHead(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    if(head->next == NULL) {
        delete head;
        return  NULL;
    }

    Node *prev = head;
    head = head->next;

    head->prev = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

//delete tail of the dll
Node* deleteTail(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    if(head->next == NULL) {
        delete head;
        return NULL;
    }

    Node *tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

//delete kth element in DLL
Node* deleteKthel(Node* head, int k) {
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    if(temp == NULL) return head;

    Node* back = temp->prev;
    Node* front = temp->next;

    if(back == NULL && front == NULL) {
        delete temp;
        return NULL;
    }
    else if(back == NULL) {
        return deleteHead(head);
    }
    else if(front == NULL) {
        return deleteTail(head);
    }
    else{
        back->next = front;
        front->prev = back;
        temp->next = NULL;
        temp->prev = NULL;

        delete temp;
    }
    return head;
}

//Remove given node from DLL
void deleteNode(Node* temp) {
    Node* back = temp->prev;
    Node* front = temp->next;

    if(front == NULL) {
        back->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return ;
    }

    back->next = front;
    front->prev = back;

    temp->next = temp->prev = NULL;
    delete temp;
}

int main() {
    vector<int> arr = {2, 7, 14, 8};
    Node* head = convertArr2LL(arr);
    // head = deleteHead(head);
    // printDLL(head);
    // head = deleteTail(head);
    // printDLL(head);
    // head = deleteKthel(head , 3);
    // printDLL(head);

    deleteNode(head->next->next->next);
    printDLL(head);

    return 0;
}