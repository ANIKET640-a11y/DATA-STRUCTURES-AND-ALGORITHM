#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int main(){
    vector<int> arr = {3,1,0,8,6};
    stack<int> s;
    vector<int> ans;

    for(int i=0; i<arr.size(); i++){
        while(!s.empty() && s.top() >= arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    for(int val: ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}