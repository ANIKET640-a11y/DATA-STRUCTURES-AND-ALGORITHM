#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int getCelebrity(vector<vector<int>>& arr, int n) {
    stack<int> s;
    for(int i=0; i<n; i++){
        s.push(i);
    }
    while(s.size() > 1){
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if(arr[i][j] == 0){
            s.push(i);
        }
        else{
            s.push(j);
        }
    }
    int candidate = s.top();
    for(int i=0; i<n; i++){
        if(i != candidate){
            if(arr[candidate][i] == 1 || arr[i][candidate] == 0){
                return -1;
            }
        }
    }
    return candidate;
}