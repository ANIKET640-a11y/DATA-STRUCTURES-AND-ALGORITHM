#include<iostream>
#include<queue>
using namespace std;

class heap{
    vector<int> heap; //CBT
    public:
     void push(int val){
        heap.push_back(val);
        int x = heap.size()-1;
        int p = (x-1)/2;

        while(p >= 0 && heap[x]>heap[p]){ //heap[x]<heap[p] then smallest element will be on top. 
            swap(heap[x],heap[p]);
            x = p;
            p = (x-1)/2;
        }
        
     }
     void heapify(int i ){//i=p
        if(i>=heap.size()){
            return;
        }
        int l = 2*1+1;
        int r = 2*i+2;

        int maxi = i;

        if(l<heap.size() && heap[l]>heap[maxi]){
            maxi = l;
        }
        if(r<heap.size() && heap[r]>heap[maxi]){
            maxi = r;
        }

        swap(heap[i],heap[maxi]);
        if(maxi != i){ // swapping with child node
            heapify(maxi);
        }

     }

     void pop(){
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();

        heapify(0);
     }

     int top(){
        return heap[0]; //highest priority element
    }    
    
    bool empty(){
        return heap.size() == 0; //empty heap
    }


};

int main(){
    heap heap;
    heap.push(1);
    heap.push(2);
    heap.push(3);

    cout<<heap.top()<<endl;;
    heap.pop();
    cout<<heap.top()<<endl;

}