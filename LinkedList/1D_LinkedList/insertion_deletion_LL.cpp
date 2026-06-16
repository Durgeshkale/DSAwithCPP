#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]); // create a head and stored it
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head; // we just have to return the starting point it finds complete linked list
}

// print LL
void Print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// remove head of the ll
Node *removesHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// removes tail of the linkedlist
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

// delete kth element from the linked list
Node *deleteKthEl(Node *head, int k)
{
    if (head == NULL)
        return head;

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    Node *previous = NULL;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            previous->next = previous->next->next;
            delete temp;
            break;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;
}

// delete node with value x
Node *deleteEl(Node *head, int el)
{
    if (head == NULL)
        return head;
    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp != NULL)
        {
            if (temp->data == el)
            {
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

// Insertion in LL
// Inserting at the head
Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    return temp;
}

// insertion at the tail
Node *insertTail(Node *head, int val) {
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    } 
    Node *newNode = new Node(val);
    temp->next = newNode;  
    return head;
}

// insert at kth position
Node* insertK(Node *head,  int el, int  k) {
    if(head == NULL) {
        if(k == 1) return new Node(el);
        else return NULL;
    }
    if(k == 1) {
        Node * temp = new Node(el);
        temp->next = head;
        return temp;
    }

    int cnt = 0;
    Node* temp = head;
    
    while(temp != NULL) {
        cnt++;

        if(cnt == k - 1) {
            Node *x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}


// insert element before the val

Node* insertBeforeVal(Node *head,  int el, int val) {
    if(head == NULL) return NULL;

    if(head->data == val) {
        Node * temp = new Node(el);
        temp->next = head;
        return temp;
    }

    Node* temp = head;
    
    while(temp->next != NULL) {

        if(temp->next->data == val) {
            Node *x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}


int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArr2LL(arr);
    // head = removesHead(head);
    // head = deleteTail(head);
    // head = deleteKthEl(head, 2);
    // head = deleteEl(head, 8);
    // head = insertHead(head, 123);
    // head = insertTail(head, 1413);
    // head = insertK(head, 1232 , 4);
    head = insertBeforeVal(head, 452, 7);
    Print(head);
}