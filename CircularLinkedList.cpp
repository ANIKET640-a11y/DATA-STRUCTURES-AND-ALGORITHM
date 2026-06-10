#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class CircularList{
    Node* head;
    Node* tail;

    public:
    CircularList(){
        head = tail = NULL; 
    }

    void insertAthead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            
            newNode->next = head;
            head = newNode;
            tail->next = head;

        }
    }

    void print(){
        if(head == NULL) return;

       cout<<head->data<<" <=> ";
            
                
        Node* temp = head->next;
        while(temp!=head){
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
    
}; 

int main(){
    CircularList cl;
    cl.insertAthead(1);
    cl.insertAthead(2);
    cl.insertAthead(3);
    
    cl.print(); 

    return 0;
}