class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

        for(int i=0; i<n; i++){
            pq.push({matrix[i][0],{i,0}});
        }


        while(--k){
            auto curr = pq.top();
            pq.pop();

            int r = curr.second.first;
            int c = curr.second.second;

            if(c+1 < n){
                pq.push({matrix[r][c+1], {r,c+1}});
            }
        }

        return pq.top().first;
    }
};