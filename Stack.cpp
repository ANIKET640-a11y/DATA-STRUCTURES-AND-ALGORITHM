#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> v;
    public:
    void push(int data){
        v.push_back(data);
    }

    void pop(){
        if(v.empty()) return;
        v.pop_back();
    }

    int top(){
        if(v.empty()) return -1;
        return v.back();
    }

    bool empty(){
        return v.empty();
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