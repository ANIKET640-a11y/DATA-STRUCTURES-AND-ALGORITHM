#include<iostream>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    vector<int> start = {0,1,2};
    vector<int> end = {9,2,4};
    vector<pair<int, int>> act(3, make_pair(0, 0));
    act[0] = make_pair(0,9);
    act[1] = make_pair(1,2);
    act[2] = make_pair(2,4);

    for(int i=0; i<act.size(); i++){
        cout<<"A"<<i<<" start: "<<act[i].first<<" end: "<<act[i].second<<endl;
    }

    sort(act.begin(), act.end(), compare);
    cout<<"----sorted----"<<endl;

    for(int i=0; i<act.size(); i++){
        cout<<"A"<<i<<" start: "<<act[i].first<<" end: "<<act[i].second<<endl;
    }
}