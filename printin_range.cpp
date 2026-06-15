#include<iostream>
using namespace std;

void printR(Node* root, int st, int end){
    if(root == NULL){
        return;
    }
    if(st<= root->data && root->data<=end){
        cout<<root->data<<" ";
        printR(root->left, st, end);
        printR(root->right, st, end);
    }

    if(root->data < st){
        printR(root->right, st, end);
    }
    else{
        printR(root->left, st, end);
    }

}