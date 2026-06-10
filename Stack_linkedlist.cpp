#include<iostream>
#include<list>
using namespace std;

class Stack{
    list<int> l;
    public:
    void push(int data){
        l.push_front(data);
    }

    void pop(){
        if(l.empty()) return;
        l.pop_front();
    }

    int top(){
        if(l.empty()) return -1;
        return l.front();
    }

    bool empty(){
        return l.empty();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

   while(!s.empty()){
       cout<<s.top()<<" ";
       s.pop();
   }

   cout<<endl;
   return 0;
}