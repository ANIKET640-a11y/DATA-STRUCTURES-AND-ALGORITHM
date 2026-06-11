#include<iostream>
using namespace std;

int kthancs(Node* root, int n, int k){
    if(root == NULL){
        return -1;

    }
    if(root->data == n){
        return 0;
    }

    int leftd = kthancs(root->left, n, k);
    int rightd = kthancs(root->right, n, k);

    if(leftd == -1 && rightd == -1){
        return -1;
    }

    int validval = leftd == -1 ? rightd : leftd;
    if(validval + 1 == k){
        cout<<root->data<<" ";
    }
    return validval + 1;
}