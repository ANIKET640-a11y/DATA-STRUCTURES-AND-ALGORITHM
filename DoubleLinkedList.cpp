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

class DoublyList{
    Node* head;
    Node* tail;

    public:
    DoublyList(){
        head = tail = NULL; 
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(tail==NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front(){
        Node* temp = head;
        head = head->next;
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;

        }
             
        if(head!=NULL){
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }

    }

    void pop_back(){
        Node* temp = tail;
        tail = tail->prev;
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;

        }
             
        if(tail!=NULL){
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }

    }



    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    

};
int main(){

    DoublyList dl;
    dl.push_front(1);
    dl.push_front(2);
    dl.print();
    dl.push_back(3);
    dl.print();
    dl.pop_front();
    
    dl.print(); 
    dl.pop_back();
    dl.print();
    
    
    return 0;
}