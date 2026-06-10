#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this-> data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }

    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);

    return curr;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int currentDiameter = height(root->left) + height(root->right) + 1;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max({leftDiameter, rightDiameter, currentDiameter});
}

pair<int, int> diameterOptimized(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int, int> left = diameterOptimized(root->left);
    pair<int, int> right = diameterOptimized(root->right);
    int currentDiameter = left.second + right.second + 1;
    int maxDiameter = max({left.first, right.first, currentDiameter});
    int maxHeight = max(left.second, right.second) + 1;
    return make_pair(maxDiameter, maxHeight);
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1,6,-1, -1};

    Node* root = buildTree(nodes);
    cout<<"Root Node: "<<root->data<<endl;
    cout<<"Left Child of Root: "<<root->left->data<<endl;
    cout<<"Right Child of Root: "<<root->right->data<<endl;
    cout<<"Height of the tree: "<<height(root)<<endl;

    cout<<"Diameter of the tree: "<<diameter(root)<<endl;
    cout<<"Optimized Diameter of the tree: "<<diameterOptimized(root).first<<endl;
}