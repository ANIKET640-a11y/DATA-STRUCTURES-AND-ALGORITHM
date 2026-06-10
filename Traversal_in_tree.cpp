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

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root){
    if(root==NULL){
        return;
    }

    vector<Node*> queue;
    queue.push_back(root);

    while(!queue.empty()){
        Node* curr = queue[0];
        cout<<curr->data<<" ";
        queue.erase(queue.begin());

        if(curr->left!=NULL){
            queue.push_back(curr->left);
        }
        if(curr->right!=NULL){
            queue.push_back(curr->right);
        }
    }
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    Node* root = buildTree(nodes);

    cout<<"root: "<<root->data<<endl;
    cout<<"left child of root: "<<root->left->data<<endl;
    cout<<"right child of root: "<<root->right->data<<endl;

    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<endl;

    cout<<"Level-order traversal: ";
    levelOrder(root);
    cout<<endl;

    return 0;
}