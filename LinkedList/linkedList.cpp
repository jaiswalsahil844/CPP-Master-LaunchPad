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

    // Home Work
}

void print(node *head){

    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;

}
int main(){

    node *head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtTail(head,6);
    insertAtMiddle(head,2,3);
    
    print(head);
    deleteAtHead(head);
    deleteAtTail(head);

    print(head);
    return 0;
}