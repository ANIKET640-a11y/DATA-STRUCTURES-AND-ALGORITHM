#include<iostream>
using namepace std;

void topView(Node* root){
    queue<pair<Node*, int>> q; //(node, HD)
    map<int, int> m; //(HD, node->data)

    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* node = curr.first;
        int hd = curr.second;

        if(m.find(hd) == m.end()){
            m[hd] = node->data;
        }

        if(node->left){
            q.push(make_pair(node->left, hd-1));
        }

        if(node->right){
            q.push(make_pair(node->right, hd+1));
        }
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
}