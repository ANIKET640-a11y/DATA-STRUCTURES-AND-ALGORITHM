#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row{
public:
    int idx;
    int soldiers;

    Row(int idx, int soldiers){
        this->idx = idx;
        this->soldiers = soldiers;
    }

    bool operator<(const Row &obj) const{
        if(this->soldiers == obj.soldiers)
            return this->idx > obj.idx;   // Smaller index has higher priority
        return this->soldiers > obj.soldiers; // Min Heap based on soldiers
    }
};

void weakestRows(vector<vector<int>> &mat, int k){
    vector<Row> rows;

    for(int i = 0; i < mat.size(); i++){
        int count = 0;

        // Count soldiers in the current row
        for(int j = 0; j < mat[i].size(); j++){
            if(mat[i][j] == 1)
                count++;
            else
                break;
        }

        rows.push_back(Row(i, count));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i = 0; i < k; i++){
        Row r = pq.top();
        cout << r.idx << " ";
        pq.pop();
    }
}

int main(){

    vector<vector<int>> mat = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };

    int k = 3;

    weakestRows(mat, k);

    return 0;
}