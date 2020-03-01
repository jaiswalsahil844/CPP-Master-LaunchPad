#include <iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;

    // Constructor
    node(int data){
        this->data = data;
        next = NULL;
    }
};

// class linkedList{

//     node* head;
//     node* tail;

//     public:
//     linkedList(){
//         head = tail = NULL;
//     }

//     void insert() {

//     }
// };

// passing a pointer variable by reference
void insertAtHead(node *&head, int data){

    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&head, int data){

    if(head == NULL){
        insertAtHead(head, data);
    }
    else{
        node *temp = new node(data);
        node *itr = head;
        while(itr->next != NULL){
            itr = itr->next;
        }
        itr->next = temp;
    }
}

int length(node *head){

    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

void insertAtMiddle(node *&head, int data, int p){

   if(head == NULL || p == 0){
       insertAtHead(head, data);
   }
   else if(p > length(head)){
       insertAtTail(head, data);
   }
   else{    
       // Insert int the middle
       // Take p-1 jumps
       node *temp = new node(data);
       node *itr = head;
       while(p != 1){
           itr = itr->next;
           p--;
       }
       temp->next = itr->next;
       itr->next = temp;
   }
}

void deleteAtHead(node *&head){

    if(head == NULL){
        return;
    }
    node *temp = head;
    head = head->next;

    delete temp;
}

void deleteAtTail(node *&head){

    if(head == NULL){
        return;
    }
    node *prev = NULL;
    node *temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}

void deleteAtMiddle(node *&head, int p){

    if(head == NULL){
        return;
    }
    else if(p > length(head)){
        return;
    }
    else if(p == 0){
        deleteAtHead(head);
    }
    else {
        node *prev = NULL;
        node *temp = head;
        while(p){
            prev = temp;
            temp = temp->next;
            p--;
        }
        prev->next = temp->next;
        delete temp;
    }

}

void print(node *head){

    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;

}

bool searchIterative(node *head, int key){

    while(head != NULL){
        
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

bool searchRecursive(node *head, int key){

    if(head == NULL){
        return false;
    }
    // Rec Case
    if(head->data == key){
        return true;
    }
    return searchRecursive(head->next, key);
}

void buildList(node *&head){

    int data;
    cin>>data;

    while(data != -1){
        insertAtTail(head, data);
        cin>>data;
    }
}

istream& operator >> (istream &is, node *&head){
    buildList(head);
    return is;
}

ostream& operator << (ostream &os, node *&head){
    print(head);
    return os;
}

void reverseListIterative(node *&head){

    node *prev = NULL;
    node *curr = head;
    node *temp = NULL;

    while(curr != NULL){
        // Save the next node
        temp = curr->next;
        // Make the current node point to prev
        curr->next = prev;
        // Just update prev and current
        prev = curr;
        curr = temp;
    }
    head = prev;
}

node* reverseListRecursive(node *head){

    // Base Case
    if(head->next == NULL || head == NULL){
        return head;
    }

    // Recursive Case
    node *smallHead = reverseListRecursive(head->next);
    node *curr = head;
    curr->next->next = curr;
    curr->next = NULL;
    return smallHead;
}

void midPointNode(node *head){

    node *slow = head;
    // node *fast = head; for m1(middel node (odd))
    node *fast = head->next; // for m2(middle node(odd))

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data<<endl;
}

void KthNodeFromLast(node *head, int k){

    node *slow = head;
    node *fast = head;

    while(k--){
        fast = fast->next;
    }
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    cout<<slow->data<<endl;
}

node * merge2SortedLL(node *a, node *b){

    if(a == NULL){
        return b;
    }
    else if(b == NULL){
        return a;
    }

    node *c;
    if(a->data < b->data){
        c = a;
        c->next = merge2SortedLL(a->next, b);
    }
    else {
        c = b;
        c->next = merge2SortedLL(a, b->next);
    }
    return c;

}

int main(){

    // node *head = NULL;
    // insertAtHead(head,5);
    // insertAtHead(head,4);
    // insertAtHead(head,3);
    // insertAtTail(head,6);
    // insertAtMiddle(head,2,3);
    
    // print(head);
    // deleteAtHead(head);
    // deleteAtTail(head);
    
    // deleteAtMiddle(head,1);
    // print(head);

    // cout<<searchRecursive(head,3);

    node *head = NULL;
    // buildList(head);
    // print(head);
    
    node *head2 = NULL;
    // cin>>head>>head2;
    // cout<<head<<endl<<head2;

    // reverseListIterative(head);
    // cout<<head;

    // node *head3 = reverseListRecursive(head2);
    // cout<<head3;

    // cin>>head;
    // midPointNode(head);

    // KthNodeFromLast(head, 5);

    cin>>head>>head2;
    cout<<head<<head2;

    head = merge2SortedLL(head, head2);
    cout<<head;
    return 0;
}