#include <bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
        Node* next;

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;

    }
};

Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]); //create a head and stored it 
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head; // we just have to return the starting point it finds complete linked list
}

//print LL
void Print(Node* head) {
    while(head != NULL) {
        cout<<head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// remove head of the ll
Node* removesHead(Node* head) {
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// removes tail of the linkedlist
Node* deleteTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp =  head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

int main() {
    vector<int> arr = {2, 5 , 8, 7};
    Node* head = convertArr2LL(arr);
    // head = removesHead(head);
    head = deleteTail(head);
    Print(head);

}