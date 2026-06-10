#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int, string> m;
    m[101] = "Rahul";
    m[110] = "Aniket";
    m[113] = "Satyarth";
    // cout<<m[110]<<endl;
    // cout<<m[101]<<endl;
    // cout<<m[113]<<endl;
    // m[101] = "Rahul Kumar";
    // cout<<m[101]<<endl;
    cout<<m.count(110)<<endl;
    cout<<m.count(120)<<endl;

    for(auto i : m){
        cout<<"Key: "<<i.first<<" Value: "<<i.second<<endl;
    }
}