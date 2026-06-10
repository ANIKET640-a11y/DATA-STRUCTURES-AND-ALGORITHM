#include<iostream>
#include<vector>
using namespace std;

int maxAct(vector<int> start, vector<int> end){
    cout<<"selecting A0\n"<<endl;
    int count = 1;
    int currEnd = end[0];
    for(int i=1; i<start.size(); i++){
        if(start[i] >= currEnd){
            cout<<"selecting A"<<i<<"\n"<<endl;
            count++;
            currEnd = end[i];
        }
    }
    return count;
}

int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout<<"max activities that can be performed: "<<maxAct(start, end)<<endl;

    return 0;
}