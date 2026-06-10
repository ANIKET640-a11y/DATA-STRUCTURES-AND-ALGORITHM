#include<iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int currSize, cap;
    int f , r;

public:

    CircularQueue(int size){
        cap = size;
        arr = new int[cap];

        currSize = 0;   // FIX

        f = 0;
        r = -1;
    }

    void push(int data){

        if(currSize == cap){
            cout<<"CQ is full"<<endl;
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;

        currSize++;
    }

    void pop(){

        if(currSize == 0){
            cout<<"CQ is empty"<<endl;
            return;
        }

        f = (f + 1) % cap;

        currSize--;
    }

    int front(){

        if(currSize == 0){
            cout<<"CQ is empty"<<endl;
            return -1;
        }

        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }

    void printarr(){

        for(int i=0; i<cap; i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }
};

int main(){

    CircularQueue cq(5);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);

    cq.pop();

    cq.push(6);

    while(!cq.empty()){

        cout<<cq.front()<<" ";

        cq.pop();
    }

    cout<<endl;
}