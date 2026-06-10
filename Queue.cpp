// Queue implementation using linked list
#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){  
        head = tail = NULL;          
   
}

void push(int data){
    Node* newNode = new Node(data);
    if(empty()){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }

}

void pop(){
    if(empty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

int front(){
    return head -> data;
}

bool empty(){
    return head == NULL;
}

};   

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front()<<endl; // Output: 1
    q.pop();
    cout<<q.front()<<endl; // Output: 2
    q.pop();
    cout<<q.front()<<endl; // Output: 3
    q.pop();
    cout<<q.empty()<<endl; // Output: 1 (true)
    return 0;
}
